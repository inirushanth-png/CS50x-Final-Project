// Implements a dictionary's functionality
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdbool.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

int word_count =0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    for(node *ptr = table[index]; ptr != NULL; ptr = ptr->next)
    {
        if(strcasecmp(ptr->word, word)==0)
        {
            return true;
        }
    }
    return false;
}
unsigned int hash(const char *word)
{
    unsigned int sum= 0;
    for( int i =0; word[i] != '\0'; i++)
    {
        sum += tolower(word[i]);
    }
    return sum % N;
}


bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary, "r");
    if(file == NULL)
{
     return false;
}

   char word[LENGTH + 1];
   while(fscanf(file, "%s", word) != EOF)
   {
    node *n = malloc(sizeof(node));
    if (n == NULL)
    {
        fclose(file);
        return false;
    }

    strcpy(n->word, word);
    unsigned int index = hash(word);
    n->next = table[index];
    table[index] =n;
    word_count++;
   }
     fclose(file);
      return true;
}
     unsigned int size(void)
     {
        return word_count;
     }

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i=0; i<N; i++)
    {
        node *ptr = table[i];
        while (ptr != NULL)
        {
            node *next = ptr->next;
            free(ptr);
            ptr=next;
        }
    }
    return true;
}
