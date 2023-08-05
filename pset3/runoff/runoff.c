#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

typedef struct
{
    int nrcedu;
    int ordem;
    string name;
}
cedula;

cedula cedulas[MAX_VOTERS];

int indvot=0;

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
    int minvot=0;
    minvot = round(voter_count / (float)2);


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



        // Check if election has been won
        bool won = print_winner();
        if(won==true)
        {
            return 0;
        }
        else
        {

            // Keep holding runoffs until winner exists

            // Calculate votes given remaining candidates
            tabulate();



            // Eliminate last-place candidates
            int min = find_min();

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

            // Eliminate anyone with minimum number of votes
            eliminate(min);

            // Reset vote counts back to zero
            for (int i = 0; i < candidate_count; i++)
            {
                candidates[i].votes = 0;
            }
        }
    return 0;
    }
}
// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    voto=false;
    for(int i=0; i < candidate_count; i++)
    {
        if(strcmp(name, candidates[i].name) == 0)
        {
            cedulas[indvot].nrcedu = voter;
            cedulas[indvot].ordem = rank;
            cedulas[indvot].name = name;
            candidates[i].votes++;
            indvot++;
            voto=true;
        }

     }


    return voto;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // TODO
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    bool ganho = false;
    int maisv=0;
        for(int i=0; i < candidate_count; i++)
        {
            if(candidates[i].votes > maisv)
            {
                maisv=candidates[i].votes;
            }

            if(maisv >= minvot)
            {
                for(int i=0; i < candidate_count; i++)
                {
                    if(candidates[i].votes == maisv)
                    {
                        printf("%s\n", candidates[i].name);
                        ganho = true;
                    }
                }
            }
        }

    return ganho;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    return false;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // TODO
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // TODO
    return;
}
