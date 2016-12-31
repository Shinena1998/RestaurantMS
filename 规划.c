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
    int s,t;
    FILE *fp;
    int i;

    fp=fopen("restaurant.txt","r");

    fgets(ch,200,fp);
    printf("%s", ch);

     for(i=0;i<N;i++)
    {
    fread(&a[i],sizeof(struct rest),1,fp);

    if(a[i].tnum==0)
        break;

    // if(s==a[i].month&&t==a[i].day)
    //if(0==strcmp(str,a[i].name))
    printf("%-5d| %d/%02d/%02d | %d:%02d:%02d| %-7d | %-9d| %-11s| %-9d| %-7.1f| %.1f\n",a[i].num,a[i].year,a[i].month,a[i].day,a[i].hour,a[i].min,a[i].sec,a[i].tnum,a[i].cnum,a[i].name,a[i].money,a[i].discount,a[i].fmoney);

    }
    // fclose(fp);
    // fp=fopen("restaurant.txt","r");
    rewind(fp);
    scanf("%d",&t);

    fgets(ch,200,fp);
    printf("%s", ch);

    for(i=0;i<N;i++)
    {
    fread(&a[i],sizeof(struct rest),1,fp);

    if(t==i+1)
    {
    scanf("%d",&a[i].money);

    if(a[i].money>=0&&a[i].money<=100)
        rest[i].discount=10;

    else if(a[i].money>100&&a[i].money<=200)
        rest[i].discount=9.5;

    else if(a[i].money>200&&a[i].money<=500)
        a[i].discount=9;

    else a[i].discount=8;

    a[i].fmoney=a[i].money*a[i].discount/10;

    //fseek(fp,-sizeof(struct rest),1);
    //fwrite(&a[i],sizeof(struct rest),1,fp);
    //fseek(fp,-sizeof(struct rest),1);
    }
    if(a[i].tnum==0)
        break;

    //if(s==a[i].month&&t==a[i].day)
    //if(0==strcmp(str,a[i].name))
    printf("%-5d| %d/%02d/%02d | %d:%02d:%02d| %-7d | %-9d| %-11s| %-9d| %-7.1f| %.1f\n",a[i].num,a[i].year,a[i].month,a[i].day,a[i].hour,a[i].min,a[i].sec,a[i].tnum,a[i].cnum,a[i].name,a[i].money,a[i].discount,a[i].fmoney);
    }
    fclose(fp);
     fp=fopen("restaurant.txt","w");
    fputs("编号 | 日期       | 时间    | 台面号  | 顾客数量 | 接待服务生 | 消费金额 | 折扣率 | 实收金额\n",fp);
    for ( i = 0; i < N; ++i)
    {
    if(fwrite(&a[i],sizeof(struct rest),1,fp)==0)
        printf("file write error\n");

    if(a[i].tnum==0)
        break;
    }
    fclose(fp);
    return 0;
}
