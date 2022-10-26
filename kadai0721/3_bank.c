#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <math.h>

void AddMembers();
void DisplayMembers();
void Sort_Display();
void AddInterest();
void RemoveMembers();
int  year_dat(int dat);

typedef struct Club
{
    char FirstName[25];
    char LastName[25];
    char Account[25];
    int timedat;
    int Fare;
    struct Club *NextMember;
}ClubMembers;

int ACCOUNT_SIZE = 0;
ClubMembers *FirstMember=NULL;

int main()
{

  char KeyBoardInput,Options;
  while(1)
  {
  printf("--------------------------------------------------------------------\n");
  printf("A: Add, D:Display, S:Sort_Display, I:Interest_Rate, R:Remove Q: Quit\n");
  printf("Type desired options(A,D,S,I,R,Q):");
  scanf("%s",&KeyBoardInput);
  Options=toupper(KeyBoardInput);
  switch (Options)
   {
    case 'A':
    AddMembers();
    break;

    case 'D':
    DisplayMembers();
    break;

    case 'S':
    Sort_Display();
    break;

    case 'I':
    AddInterest();
    DisplayMembers();
    break;

    case 'R':
    RemoveMembers();
    break;

    case 'Q':
    return 0;

    default:
    printf("Invalid Option.\n");
    break;
   }
  }
}


void AddMembers()
{
   ClubMembers *NewMember, *CurrentMember;

   NewMember=(ClubMembers*)malloc(sizeof(ClubMembers));
   printf("\n");
   printf("Type Details of New Member:\n");
   printf("First Name\n");
   scanf("%s",NewMember->FirstName);
   printf("Last Name\n");
   scanf("%s",NewMember->LastName);
   printf("Account(xxx-xxxx)\n");
   scanf("%s",NewMember->Account);
   printf("Date(yyyy/mm/dd) ( '/'Except )\n");
   scanf("%d",&NewMember->timedat);
   printf("Fare(in JPY)\n");
   scanf("%d",&NewMember->Fare);

   ACCOUNT_SIZE++;
   NewMember->NextMember=NULL;

    if (FirstMember==NULL)
       {
        FirstMember=NewMember;
        return;
      }

     CurrentMember=FirstMember;

     while (1)
      if(CurrentMember->NextMember!=NULL)
         {
          CurrentMember=CurrentMember->NextMember;
         }
         else
        {
          break;
        }
        CurrentMember->NextMember=NewMember;
}

void DisplayMembers()
{
  ClubMembers *DisplayIt;
   if (FirstMember==NULL)
   {
     printf("There is no member data.\n");
     return;
   }
   DisplayIt=FirstMember;
   printf("\nThe Account data is as follows:\n\n");

   while (1)
   {
     printf("%s\t",DisplayIt->FirstName);
     printf("%s\t",DisplayIt->LastName);
     printf("%s\t",DisplayIt->Account);
     printf("%d\t",DisplayIt->timedat);
     printf("%d\n\n",DisplayIt->Fare);
       if (DisplayIt->NextMember!=NULL)
         {
           DisplayIt=DisplayIt->NextMember;
          }
      else
          {
           break;
        }

    }

}

void Sort_Display()
{
  ClubMembers *Sort_Display, *tmp, *Accounts[ACCOUNT_SIZE];
  int count = 0, i = 0;
  int SIZE = (ACCOUNT_SIZE - 1);
   if (FirstMember==NULL)
   {
     printf("There is no member data.\n");
     return;
   }

   Sort_Display=FirstMember;

   while (1) {
     Accounts[count++] = Sort_Display;
     if (Sort_Display -> NextMember != NULL) {
       Sort_Display = Sort_Display -> NextMember;
     }
     else{
       break;
     }
   }

for (i=SIZE; i > 0; i--) {
  for (int k = 0; k < i; k++) {
    if ( (Accounts[k] -> timedat) < (Accounts[k+1] -> timedat)) {
      tmp = Accounts[k];
      Accounts[k] = Accounts[k+1];
      Accounts[k+1] = tmp;
    }
  }
}

   for (int j = 0; j < ACCOUNT_SIZE; j++) {
     printf("%s\t", Accounts[j] -> FirstName);
     printf("%s\t", Accounts[j] -> LastName);
     printf("%s\t", Accounts[j] -> Account);
     printf("%d\t", Accounts[j] -> timedat);
     printf("%d\n\n", Accounts[j] -> Fare);
   }
   return;
}

void AddInterest()
{
  ClubMembers *Interest;
  int year;

   if (FirstMember==NULL)
   {
     return;
   }
   Interest=FirstMember;
   printf("\nApplied the interest:");

   while (1)
   {
     year = year_dat(Interest->timedat);

     if (1<=year) {
       Interest->Fare = (pow(1.02, year)) * (Interest->Fare);
     }
       if (Interest->NextMember!=NULL)
         {
           Interest=Interest->NextMember;
          }
      else
        {
           break;
        }

    }

}

void RemoveMembers()
  {
   ClubMembers *CurrentMember, *JustBeforeCurrentMember;
   int year;
while (1) {
  CurrentMember=FirstMember;
  JustBeforeCurrentMember=NULL;

  year = year_dat(CurrentMember->timedat);

  while(CurrentMember!=NULL)
   {
     if((CurrentMember->Fare) <= 100 && 5 <= year)
       {
         break;
        }
    else
      {
       JustBeforeCurrentMember=CurrentMember;
       CurrentMember=CurrentMember->NextMember;
       }
    }

   if(CurrentMember==NULL)
    {
     printf("Completed!!!\n");
     break;
    }
   else if(CurrentMember==FirstMember)
    {
    FirstMember=FirstMember->NextMember;
    free(CurrentMember);
    printf("It was the first item. Its deleted.\n");
     }
     else
     {
       JustBeforeCurrentMember->NextMember=CurrentMember->NextMember;
       free(CurrentMember);
       printf("Requested item deleted.\n");
     }
}

}

int year_dat(int date)
{
  int year;
  char timedats[25];
  time_t now,dat;
  struct tm ts = {0};
  double diff,nissuu;

  now = time(NULL);
  snprintf(timedats,25,"%d",date);

  sscanf(timedats ,"%4d%2d%2d",&(ts.tm_year),&(ts.tm_mon),&(ts.tm_mday));
  ts.tm_year -= 1900;
  ts.tm_mon -= 1;
  dat = mktime(&ts);

  diff = difftime(dat, now);
  nissuu = diff / (60*60*24);

  year=(int)nissuu/-365;

  return year;
}
