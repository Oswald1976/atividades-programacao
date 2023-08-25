#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{


    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double Blue =image[i][j].rgbtBlue;
            double Green=image[i][j].rgbtGreen;
            double Red  =image[i][j].rgbtRed;

            int mediaRGB= round((Blue + Green +Red) / 3);

            image[i][j].rgbtBlue = image[i][j].rgbtGreen = image[i][j].rgbtRed = mediaRGB;
        }
    }
       return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE));
    for(int i=0; i < height; i++)
    {
        for(int j = width - 1; j > 0; j--)
        {
           tmp[i][(width - 1) - j].rgbtBlue  = image[i][j].rgbtBlue;
           tmp[i][(width - 1) - j].rgbtGreen = image[i][j].rgbtGreen;
           tmp[i][(width - 1) - j].rgbtRed   = image[i][j].rgbtRed;
        }
    }
     for(int i=0; i < height; i++)
     {
        for(int j=0; j < width; j++)
        {
            image[i][j].rgbtBlue  = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed =   tmp[i][j].rgbtRed;
        }
     }

    free(tmp);
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE)); //
    float media[3];
    float divisor;

    for(int i=0; i < height; i++)
    {
        for(int j= width-1; j >= 0; j--)
        {
            divisor=0;
            for(int n=0; n < 3; n++)
            {
                media[n]=0;
            }
            for(int y=-1; y <2 ; y++)
            {
                for(int x=-1; x <2 ; x++)
                {
                    if (i + y >= 0 && i + y < height)
                    {
                        if (j + x >= 0 && j + x < width)
                        {
                            media[0] = image[i + y][j + x].rgbtBlue  + media[0];
                            media[1] = image[i + y][j + x].rgbtGreen + media[1];
                            media[2] = image[i + y][j + x].rgbtRed   + media[2];
                            divisor++;
                        }
                    }

                }
            }
            if( media[0] != 0)
            {
                tmp[i][j].rgbtBlue = round(media[0] / divisor);
            }
            if( media[1] != 0)
            {
                tmp[i][j].rgbtBlue = round(media[1] / divisor);
            }
            if( media[2] != 0)
            {
                tmp[i][j].rgbtBlue = round(media[2] / divisor);
            }
        }
     }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = tmp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tmp[i][j].rgbtGreen;
            image[i][j].rgbtRed = tmp[i][j].rgbtRed;
        }
    }
    free(tmp);

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE(*tmp)[width] = calloc(height, width * sizeof(RGBTRIPLE)); // aloca um espaço na memoria para um RGBTRIPLE

     // Initialise Sobel arrays
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    // Initialise ints
    float Gx_red, Gx_blue, Gx_green, Gy_red, Gy_blue, Gy_green;
    Gx_red = Gx_blue = Gx_green = Gy_red = Gy_blue = Gy_green = 0;

    for(int i=0; i < height; i++)  // percorre a linha
    {
        for(int j=0; j < width; j++) // percorre a coluna
        {
            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // Check if pixel is outside rows
                    if (i + k < 0 || i + k >= height)
                    {
                        continue;
                    }
                    // Check if pixel is outside columns
                    if (j + l < 0 || j + l >= width)
                    {
                        continue;
                    }
                    // Otherwise add to sums
                    Gx_red += tmp[i + k][j + l].rgbtRed * Gx[k + 1][l + 1];
                    Gx_green += tmp[i + k][j + l].rgbtGreen * Gx[k + 1][l + 1];
                    Gx_blue += tmp[i + k][j + l].rgbtBlue * Gx[k + 1][l + 1];
                    Gy_red += tmp[i + k][j + l].rgbtRed * Gy[k + 1][l + 1];
                    Gy_green += tmp[i + k][j + l].rgbtGreen * Gy[k + 1][l + 1];
                    Gy_blue += tmp[i + k][j + l].rgbtBlue * Gy[k + 1][l + 1];
                }
            }
            // Calculate Sobel operator
            int red = round(sqrt(Gx_red * Gx_red + Gy_red * Gy_red));
            int green = round(sqrt(Gx_green * Gx_green + Gy_green * Gy_green));
            int blue = round(sqrt(Gx_blue * Gx_blue + Gy_blue * Gy_blue));
            // Cap at 255
            if (red > 255)
            {
                red = 255;
            }
            if (green > 255)
            {
                green = 255;
            }
            if (blue > 255)
            {
                blue = 255;
            }
            // Assign new values to pixels
            image[i][j].rgbtRed = red;
            image[i][j].rgbtGreen = green;
            image[i][j].rgbtBlue = blue;
        }
    }
    free(tmp);  //  Libera o espaço da memoria para o RGBTRIPLE tmp
    return;
}
