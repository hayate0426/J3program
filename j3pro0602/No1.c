/*構造体を用いてお客様の氏名、口座番号と残高を入力し、任意の残高より以上と以下のお客様の氏名、口座番号と残高を表示するプログラムを書きなさい(typedef等を使用すること）*/
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char FirstName[25];
    char LastName[25];
    int CustomerNunmber;
    int Fare;
}CustomerMembers;

int main(){
  int N_Members, Any_Money;
  printf("How many members?\n");
  scanf("%d", &N_Members);
  CustomerMembers Members[N_Members];

for (int i = 0; i < N_Members; i++) {
  printf("[%d]\n", i+1);
  printf("Please Name = ");
  scanf("%s", Members[i].FirstName);
  //printf("Please CustomerNunmber = ");
  Members[i].CustomerNunmber = rand() % 99 + 1;
  //scanf("%d", &Members[i].CustomerNunmber);
  //printf("Deposit = ");
  scanf("%d", &Members[i].Fare);
  Members[i].Fare = (rand() % 24)*100 + 100;
}
  printf("\n");

  int Higher[N_Members],Lower[N_Members];

  scanf("%d", &Any_Money);

for (int juage = 0; juage < N_Members; juage++) {
  int count = 0;

  if (Members[juage].Fare >= Any_Money) {
    Higher[count] = juage;
  }
    else {
      Lower[count] = juage;
    }
  count++;
}

for (int j = 0; j < N_Members; j++) {
  printf("[%d]\n", j+1);
  printf("Name = %s\n", Members[j].FirstName);
  printf("Number = %d\n", Members[j].CustomerNunmber);
  printf("JPY = %d\n", Members[j].Fare);
}
  return 0;
}
