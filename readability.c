#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string letters);
int count_words(string words);
int count_sentences(string sentences);

int main(void)
{
    string text=get_string("Text:  ");

    int score1= count_letters(text);
    int score2= count_words(text);
    int score3= count_sentences(text);

    float L=(float)  score1 / score2* 100;
    float S=(float)  score3 / score2* 100;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    int grade = round(index);

    if(grade>=16)
    {
     printf("Grade 16+\n");
    }
    else if(grade<1)
    {
     printf("Before Grade 1\n ");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}
     int count_letters(string letters)
     {
        int count=0;
       for(int i=0,n=strlen(letters); i<n ;i++)
       {
        if(isalpha(letters[i]))
        {
            count++;
        }
       }
       return count;
     }

     int count_words(string words)
     {
      int count=0;
      for(int i=0,N=strlen(words); i<N; i++)
      {
         if(words[i]==' ')
        {
            count++;
        }
      }
    return count;
 }

     int count_sentences(string sentences)
      {
        int count=0;
      for(int i=0,n=strlen(sentences); i<n; i++)
      {
        if(sentences[i]=='.' || sentences[i]=='!' || sentences[i]=='?' )
        {
            count++;
        }
      }
 return count;
 }



