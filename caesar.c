#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Step 1: Check if command-line arguments are correct

int main(int argc, string argv[])
{
    if (argc != 2)
    {
     printf("Usage: ./caesar key\n");
     return 1;
    }
    // Step 2: Get plaintext from user
    for(int i=0, n=strlen(argv[1]); i<n; i++)
    {
      if(!isdigit(argv[1][i]))
      {
        printf("Usage: ./caesar key\n");
        return 1;
      }
    }
       int key = atoi(argv[1]);
       string plaintext=get_string("plaintext: ");
       printf("ciphertext: ");

       for(int i =0,n=strlen(plaintext); i<n; i++)
       {
        if(isupper(plaintext[i]))
        {
          printf("%c", (plaintext[i] - 'A' +key)%26 + 'A');
        }

       else if(islower(plaintext[i]))
       {
          printf("%c", (plaintext[i]-'a' + key)%26 + 'a');
       }
       else
       {
        printf("%c", plaintext[i]);
       }
    }
    printf("\n");
  }







