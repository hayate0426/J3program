#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <ctype.h>
void AddWords();
void DisplayWords();
void RemoveWords();
typedef struct Club
{
    char len[25];
    int check;

    struct Club *NextWord;
}ClubWords;

ClubWords *FirstWord=NULL;

int main()
{

  char KeyBoardInput,Options;
  while(1)
  {
  printf("A: Add, D:Display, R:Remove Q: Quit\n");
  printf("Type desired options(A,D,R Q):");
  scanf("%s",&KeyBoardInput);
  Options=toupper(KeyBoardInput);
  switch (Options)
   {
    case 'A':
    AddWords();
    break;

    case 'D':
    DisplayWords();
    break;

    case 'R':
    RemoveWords();
    break;

    case 'Q':
    return 0;

    default:
    printf("Invalid Option.\n");
    break;
   }

  }
}


void AddWords()
{
   ClubWords *NewWord, *CurrentWord;

   NewWord=(ClubWords*)malloc(sizeof(ClubWords));
   printf("Type Details of New Word:\n");
   scanf("%s",NewWord->len);

   CurrentWord=FirstWord;
   NewWord->check = 1;
   NewWord->NextWord=NULL;

    if (FirstWord==NULL)
       {
        FirstWord=NewWord;
        return;
      }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
     while (1)
      if(CurrentWord->NextWord==NULL || strcmp(CurrentWord->len,NewWord->len) == 0)
         {
           break;
         }
         else
        {
          CurrentWord=CurrentWord->NextWord;
        }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
          if (!(strcmp(CurrentWord->len,NewWord->len) == 0)) {
            CurrentWord->NextWord=NewWord;
            }
            else {
              CurrentWord->check = (CurrentWord->check)+1;
              printf("[%s] Added Count \n",CurrentWord->len);
            }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
}

void DisplayWords()
{
  ClubWords *DisplayIt;
   if (FirstWord==NULL)
   {
     printf("There is no word data.\n");
     return;
   }
   DisplayIt=FirstWord;
   printf("\nThe word data is as follows:\n\n");

   while (1)
   {
     printf("%s\t",DisplayIt->len);
     printf("%d\n", DisplayIt->check);

       if (DisplayIt->NextWord!=NULL)
         {
           DisplayIt=DisplayIt->NextWord;
          }
      else
        {
           break;
        }

    }

}

 void RemoveWords()

  {
   ClubWords *CurrentWord, *JustBeforeCurrentWord;

   char RemovebyFirstName[20]="";
   printf("Please write the word of the word to be removed\n");
   scanf("%s",RemovebyFirstName);

   while (1) {
     CurrentWord=FirstWord;
     JustBeforeCurrentWord=NULL;

     while(CurrentWord!=NULL)
      {
        if(strcmp(CurrentWord->len,RemovebyFirstName) == 0)
          {
            break;
           }
       else
         {
          JustBeforeCurrentWord=CurrentWord;
          CurrentWord=CurrentWord->NextWord;
          }
       }

      if(CurrentWord==NULL)
       {
        printf("Completed!!!\n");
        break;
       }
      else if(CurrentWord==FirstWord)
       {
       FirstWord=FirstWord->NextWord;
       free(CurrentWord);
       printf("It was the first item. Its deleted.\n");
        }
        else
        {
          JustBeforeCurrentWord->NextWord=CurrentWord->NextWord;
          free(CurrentWord);
          printf("Requested item deleted.\n");
        }
   }
}
