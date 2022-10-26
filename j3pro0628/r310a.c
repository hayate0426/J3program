#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
void AddMembers();
void DisplayMembers();
typedef struct Club
{
    char FirstName[25];
    char LastName[25];
    char Department[25];
    int SchoolYear;
    int CommutingTime;
    int Fare;
    struct Club *NextMember;
}ClubMembers;

ClubMembers *FirstMember=NULL;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*前回授業時間の課題で言うたのはここに最後のメンバーはLastMemberとして覚えるおくことなく、追加するときに最後まで行って、その次に追加して欲しかったです。
//ですから、ClubMembers *LastMember=NULL;　は要らない。
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
*/
int main()
{

  char KeyBoardInput,Options;
  while(1)
  {
  printf("A: Add Members, D:Display Members Q: Quit\n");
  printf("Type desired options(A,D, Q):");
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
   ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//表示するときの関数DisplayMembers(）と同じ方法でできます。覚えてないのであればDisplaYMembers()の説明は前回のフォームでもう一回読んでください。
//そこにDisplayItとして最後まで行って各項目のデータをプリント（表示）したのですが、AddMembers()の場合はプリントしないで最後まで行くだけです。変数だけははDisplayITのところCurrentMemberにしましょう。
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/

 /*ここからーーーーーーーーーーーー */

   NewMember=(ClubMembers*)malloc(sizeof(ClubMembers));
   printf("Type Details of New Member:\n");
   printf("First Name\n");
   scanf("%s",NewMember->FirstName);
   printf("Last Name\n");
   scanf("%s",NewMember->LastName);
   printf("Department(for eg. Information, Mechanical, Civil, Elecrical, Control etc)\n");
   scanf("%s",NewMember->Department);
   printf("School Year (1~5)\n");
   scanf("%d",&NewMember->SchoolYear);
   printf("Commuting Time(in minutes)\n");
   scanf("%d",&NewMember->CommutingTime);
   printf("Transportation Fare(in JPY)\n");
   scanf("%d",&NewMember->Fare);
   NewMember->NextMember=NULL;
 /*ここまでは前回のAddMember()関数と同様です。ーーーーーーーーーーーー */

/*前回のAddMembers()関数はif (FirstMember==NULL　&& LastMember=NULL)　実は FirstMemberはないとデータがないのでLastMember==NULLは実は要らないです*/
    if (FirstMember==NULL)
       {
        FirstMember=NewMember;
        return;
      }
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*データがある場合はCurrentMemberにFirstMemberを設定します。DisplayMembers()と同様です。先も書いたけど、覚えてないのであればDisplaYMembers()の説明は前回のフォームでもう一回読んでください*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
     CurrentMember=FirstMember;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
     while (1)
      if(CurrentMember->NextMember!=NULL)/*CurrentMember->NextMember=NULLになったときにはCurrentMemberは最後のメンバーですので、最後まで行きます。どうやっていく母DisplayMembers()の説明もう一回前回フォームより読んでください。*/
         {
          CurrentMember=CurrentMember->NextMember;
         }
         else
        {
          break;/*CurrentMember->NextMember=NULLになったときにはCurrentMemberは最後のメンバーですのでWhileループから外に出ます*/
        }
        /*WhileループのところでCurrentMemberは最後のメンバーですので、最後のメンバーの次のメンバとして以下のようにNewMemberを設定します。これで終わりです*/
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
        CurrentMember->NextMember=NewMember;
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
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
   printf("\nThe member data is as follows:\n\n");

   while (1)
   {
     printf("%s\t",DisplayIt->FirstName);
     printf("%s\t",DisplayIt->LastName);
     printf("%s\t",DisplayIt->Department);
     printf("%d\t",DisplayIt->SchoolYear);
     printf("%d\t",DisplayIt->CommutingTime);
     printf("%d\n",DisplayIt->Fare);
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
