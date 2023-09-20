// Implements a dictionary's functionality

#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

const unsigned int N = 26;  // Number of buckets in hash table

node *table[N];  // Hash table

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int i;
    i = hash(word);

    for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *dicionario - NULL;
    dicionario - fopen(dictionary, "r");

    if (dicionario == NULL)
    {
        printf("falha ao abrir dicionario");
        return 1;
    }
    else
    {
        printf("dicionario aberto com sucesso");
    }

    int     idx, i = 1, x = 0;
    char    palavra[LENGTH + 1];

    while (fscanf(dicionario), %s, palavra) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Falha na alocação de memória.\n");
            free(table);
            return false;
        }
    }


    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
