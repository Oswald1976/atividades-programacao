#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
     float mediaRGB;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            mediaRGB = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(mediaRGB);
            image[i][j].rgbtGreen = round(mediaRGB);
            image[i][j].rgbtRed = round(mediaRGB);
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
        for(int j = width; j > 0; j--)
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    return;
}
