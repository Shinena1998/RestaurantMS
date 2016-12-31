#include "stdio.h"
#include "string.h"
#define N 100
struct rest
{
    int num;
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int tnum;
    int cnum;
    char name[10];
    int money;
    float discount;
    float fmoney;
}rest[N],a[N];
int main(int argc, char const *argv[])
{
    char ch[200],str[10];
    scanf("%s",str);
    FILE *fp;
    int i;

    fp=fopen("D:\\c\\keshe\\restaurant.txt","r");

    fgets(ch,200,fp);
    printf("%s", ch);

     for(i=0;i<N;i++)
    {
    fread(&a[i],sizeof(struct rest),1,fp);

    if(a[i].tnum==0)
        break;

    if(0==strcmp(str,a[i].name))
    printf("%-5d| %d/%02d/%02d | %d:%d:%02d| %-7d | %-9d| %-11s| %-9d| %-7.1f| %.1f\n",a[i].num,a[i].year,a[i].month,a[i].day,a[i].hour,a[i].min,a[i].sec,a[i].tnum,a[i].cnum,a[i].name,a[i].money,a[i].discount,a[i].fmoney);

    }

    fclose(fp);
    return 0;
}
