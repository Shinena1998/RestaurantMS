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
    char ch[200];
    float t=0;
    FILE *fp;
    int i;
    fp=fopen("D:\\c\\keshe\\restaurant.txt","r");
    fgets(ch,200,fp);
    //printf("%s", ch);
    for(i=0;i<N;i++)
    {
        fread(&a[i],sizeof(struct rest),1,fp);
            if(a[i].tnum==0)
            break;
        t=t+a[i].fmoney;
    }
    printf("总顾客数    总收入\n");
    printf("%-12d%.1f",a[i-1].num,t);
    //if(t==a[i].tnum)
    //printf("%-7d%d:%d:%-4d%-9d%-11d%-13s%-11d%-9.1f%.1f\n",a[i].num,a[i].hour,a[i].min,a[i].sec,a[i].tnum,a[i].cnum,a[i].name,a[i].money,a[i].discount,a[i].fmoney);}
    fclose(fp);
    return 0;
}
