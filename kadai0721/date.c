#include<stdio.h>
#include<time.h>

int main()
{
int year;
time_t now,dat;
int timedat;
char date[25];
struct tm ts = {0};
double diff,nissuu;

scanf("%d", &timedat);
/* 現在時刻の取得 */
now = time(NULL);
snprintf(date,25,"%d",timedat);
/* 日付をtime_tに変換 */
sscanf(date ,"%4d%2d%2d",&(ts.tm_year),&(ts.tm_mon),&(ts.tm_mday));
ts.tm_year -= 1900;
ts.tm_mon -= 1;
dat = mktime(&ts);

/* 差分算出 */
diff = difftime(dat, now);
nissuu = diff / (60*60*24);

year=(int)nissuu/-365;
printf("%d\n",year );
if (1<=year) {
  printf("1years\n");
}
return 0;
}
