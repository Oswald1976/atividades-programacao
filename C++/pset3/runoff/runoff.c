#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

int preferences[MAX_VOTERS][MAX_CANDIDATES]; // preferences[i][j] is jth preference for voter i

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;
candidate candidates[MAX_CANDIDATES]; // Array of candidates



// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Numero de Cédulas : ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }



    // Keep querying for votes
    while(true)
    {
        for (int i = 0; i < voter_count; i++)
        {

            // Query for each rank
            for (int j = 0; j < candidate_count; j++)
            {
                string name = get_string("Rank %i: ", j + 1);

                // Record vote, unless it's invalid
                if (!vote(i, j, name))
                {
                    printf("Invalid vote.\n");
                //   return 4;
                    continue ;
                }


                 printf("\n");
            }
        }


int min = find_min();
        while(true)
        {
            tabulate(); // faz os calulos do votos primeiramente

            // Check if election has been won
            bool won = print_winner();
            if(won==true)
            {
                return 0;
            }
            else
            {

                // Eliminate last-place candidates
                eliminate(min);

                // Reset vote counts back to zero
                for (int i = 0; i < candidate_count; i++)
                {
                    candidates[i].votes = 0;
                }
            }
        }

            bool tie = is_tie(min);

            // If tie, everyone wins
            if (tie)
            {
                for (int i = 0; i < candidate_count; i++)
                {
                    if (!candidates[i].eliminated)
                    {
                        printf("%s\n", candidates[i].name);
                    }
                }
            //  break;
            }

    return 0;
    }
}
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // bool voto=false;
    for(int i=0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank]=i;

            return true;
        }

     }


    return false;
}

// Calcula os votos
void tabulate(void)
{
    for(int i = 0; i < voter_count; i++)
    {
        for(int j = 0; j < candidate_count; j++)
        {
            if(candidates[preferences[i][j]].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                j = candidate_count;
            }
        }
    }

}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for(int i=0; i < candidate_count; i++)
    {
        if(candidates[i].votes >= round(voter_count / (float)2))
        {
             printf("%s\n", candidates[i].name);
             return true;
        }

    }

    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int menosv=voter_count;
    for(int i=0; i < candidate_count; i++)
    {
        if(candidates[i].votes < menosv)
        {
            menosv=candidates[i].votes;
        }
    }
    return menosv;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int new_count = 0;
    int x = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated)
        {
            new_count++;
        }
    }

    for (int j = 0; j < candidate_count; j++)
    {
        if (candidates[j].votes == min)
        {
            x++;
        }
    }

    if (x == new_count)
    {
        return true;
    }

    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for(int i=0; i < candidate_count; i++)
    {
        if(candidates[i].votes == min)
        {
             candidates[i].eliminated = true;
        }
     }
}

