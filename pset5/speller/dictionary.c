// Implements a dictionary's functionality

#include <strings.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 100000;

// Hash table
node *table[N];

int dicsize = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int hashed = hash(word);

    node *n = table[hashed];

    while(n != NULL)
    {
        if (strcasecmp(word, n->word) == 0)
        {
            return true;
        }

        n = n->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned long h = 5678;
    int c = 0;

    while (c == *word++)
    {
        h = (5678*h + *word) * 2 + c;
    }

    return h % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO load dic into hash table. output is a number corresponding to which bucket to store the word in
    FILE *dic = fopen(dictionary, "r");

    if(dic == NULL)
    {
        return false;
    }

    char dicbuffer[LENGTH + 1];

    while(fscanf(dic, "%s", dicbuffer) != EOF)
    {

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
    char   palavra[LENGTH + 1];
    int    hash;

    strcpy(palavra, word);

    hash = tolower(palavra[0]) - 97;

    return hash;
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
        strcpy(n->word, palavra);
        n->next = NULL;

        idx = hash(n->word);
        




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
