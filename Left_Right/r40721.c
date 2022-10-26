#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct num
{
    int Data;
    struct num *Left;
    struct num *Right;
}Number;

void AddNumber();
void SearchAndInsert(Number* Node);
void DisplayNumbers(Number* Node);
void Inorder_Transversal(Number* Node);
void Preorder_Transversal(Number* Node);
void Postorder_Transversal(Number* Node);
Number *NewNumber, *Root=NULL;
int NewData;

int main()
{

 char KeyBoardInput,Options;
while(1)
  {
  printf("A: Add Numbers, D:Display Numbers Q: Quit\n");
  printf("Type desired options(A,D, Q):");
  scanf("%s",&KeyBoardInput);
  Options=toupper(KeyBoardInput);
  switch (Options)
   {
    case 'A':
    AddNumber();
    break;
    case 'D':
    printf("Inserted Numbers are as follows\n");
    DisplayNumbers(Root);
    printf("\n");
    break;
   case 'Q':
   return 0;
   default:
    printf("Invalid Option.\n");
    break;
  }
}
}

/*数字を追加する関数*/
///////////////////////////
//////////////////////////
void AddNumber()
{
  printf("Enter the number:\n");
 scanf("%d",&NewData);
  if (Root==NULL)　//初めてデータを追加する場合
   {
    NewNumber=(Number*)malloc(sizeof(Number));
    NewNumber->Data=NewData;
    NewNumber->Left=NULL;　　　//初回なので左に何もデータが入ってないとする
    NewNumber->Right=NULL;　　//同様に右も何も入ってないとする
    Root=NewNumber;
    printf("Inserted as Root\n");
   }
   else           //初回以降データを追加する場合
   {
    SearchAndInsert(Root);
   }
}
///////////////////////////
//////////////////////////


/*追加する関数に関連する関数*/
///////////////////////////
//////////////////////////
void SearchAndInsert(Number *Node)

{
   if((NewData > Node->Data)&& (Node->Right!=NULL))
   //新しいデータが今見ているtreeより大きく、treeの右側にデータが入っている場合
     {
       SearchAndInsert(Node->Right);
  　//treeの右側のデータを参照しもう一度繰り返す
     }
   else if((NewData > Node->Data) && (Node->Right==NULL))
   //新しいデータが今見ているtreeより大きく、treeの右側にデータが入っていない場合
     {
       //右側にデータを追加し、初めてデータを追加する場合同様に次の場所を初期化する
       NewNumber=(Number*)malloc(sizeof(Number));
       Node->Right=NewNumber;
       NewNumber->Data=NewData;
       NewNumber->Left=NULL;
       NewNumber->Right=NULL;
       printf("Inserted at the right of %d\n", Node->Data);
     }
   else if ((NewData< Node->Data) &&(Node->Left!=NULL))
   //新しいデータが今見ているtreeより小さく、treeの左側にデータが入っている場合
    {
       SearchAndInsert(Node->Left);
  　//treeの左側のデータを参照しもう一度繰り返す
    }
   else if ((NewData< Node->Data) &&(Node->Left==NULL))
   //新しいデータが今見ているtreeより小さく、treeの左側にデータが入っていない場合
    {
      //左側にデータを追加し、初めてデータを追加する場合同様に次の場所を初期化する
       NewNumber=(Number*)malloc(sizeof(Number));
       Node->Left=NewNumber;
       NewNumber->Data=NewData;
       NewNumber->Left=NULL;
       NewNumber->Right=NULL;
      printf("Inserted at the left of %d\n", Node->Data);
    }
    else　//同じ番号が既に存在する場合
    {
       printf("Number Already Exists\n");
    }

}
///////////////////////////
//////////////////////////


/*数字を表示する関数*/
///////////////////////////
//////////////////////////
void  DisplayNumbers(Number *Node)
{
  if (Root==NULL)　//データが何もない場合はデータがないと表示し戻る
   {
    printf("No data exists\n");
    return;
   }
   else
   {
    printf("In-order Transversal\n");
    Inorder_Transversal(Node);　         //通りがけ
    printf("\nPre-order Transversal\n");
    Preorder_Transversal(Node);　　　　　　//行きがけ
    printf("\nPost-Order Transversal\n");
    Postorder_Transversal(Node);        //帰りがけ
   }
 }

///////////////////////////
//////////////////////////


/*通りがけ、行きがけ、帰りがけはNode->Dataを表示するタイミングによって表すことができる
それ以外の部分は共通している*/

/*通りがけ順で表示する関数*/
///////////////////////////
//////////////////////////
void  Inorder_Transversal(Number *Node)
{
 if(Node->Left!=NULL)
 {
   Inorder_Transversal(Node->Left);
  }
 printf ("%d,",Node->Data);
 if(Node->Right!=NULL)
 {
    Inorder_Transversal(Node->Right);
 }
}

/*行きがけ順で表示する関数*/
///////////////////////////
//////////////////////////
void  Preorder_Transversal(Number *Node)
{
  printf ("%d,",Node->Data);
 if(Node->Left!=NULL)
 {
   Preorder_Transversal(Node->Left);
  }
  if(Node->Right!=NULL)
 {
  Preorder_Transversal(Node->Right);
 }
}

/*帰りがけ順で表示する関数*/
///////////////////////////
//////////////////////////
void  Postorder_Transversal(Number *Node)
{
   if(Node->Left!=NULL)
 {
   Postorder_Transversal(Node->Left);
  }
  if(Node->Right!=NULL)
 {
  Postorder_Transversal(Node->Right);
 }
 printf ("%d,",Node->Data);
}
//////////////////////////
//////////////////////////
