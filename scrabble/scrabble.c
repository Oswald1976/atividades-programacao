#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>


// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
char alp[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    printf("%d", score1);
    // TODO: Print the winner
}

int compute_score(string word)
{
    int score=0;
    int len=strlen(word);
    for(int i = 0; i < len; i++)
    {
        word[i]=islower(word[i]);
    }

    for(int i = 0; i < len; i++)
    {
        for(int j = 0; j < len; j++)
        {
            if(word[i] == alp[j])
            {
                score += POINTS[j];
            }
        }
    }
    return score;
}
