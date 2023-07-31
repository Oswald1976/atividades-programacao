#include <cs50.h>
#include <stdio.h>
#include <string.h>

#define MAX 5 // Max number of candidates

typedef struct // Candidates have name and vote count
{
    string name;
    int votes;
}
candidate;

candidate candidates[MAX]; // Array of candidates

int candidate_count; // Number of candidates

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    if (argc < 2) // Check for invalid usage
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1; // Populate array of candidates
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }
    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}
bool vote(string name) // Update vote totals given a new vote
{
    candidate.name
    for(int i=0;  )
    // TODO
    return false;
}

void print_winner(void) // Print the winner (or winners) of the election
{
    // TODO
    return;
}

