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
    int t;
    scanf("%d",&t);
    float s=0;
    FILE *fp,*p;
    int i;
    fp=fopen("D:\\c\\keshe\\restaurant.txt","r");
   // p=fopen("D:\\c\\keshe\\servert.txt","w+");
    fgets(ch,200,fp);
   // fputs("编号 | 日期       | 时间    | 台面号  | 顾客数量 | 接待服务生 | 消费金额 | 折扣率 | 实收金额\n",p);
    printf("%s", ch);
     for(i=0;i<N;i++)
    {
    fread(&a[i],sizeof(struct rest),1,fp);
    //fwrite(&a[i],sizeof(struct rest),1,fp);
            if(a[i].tnum==0)
            break;
    if(t==a[i].tnum)
    {
        s=s+a[i].fmoney;

        printf("%-5d| %d/%02d/%02d | %d:%d:%02d| %-7d | %-9d| %-11s| %-9d| %-7.1f| %.1f\n",a[i].num,a[i].year,a[i].month,a[i].day,a[i].hour,a[i].min,a[i].sec,a[i].tnum,a[i].cnum,a[i].name,a[i].money,a[i].discount,a[i].fmoney);
    }
    }
    printf("台面号%d总收入\n",t);
    printf("%.1f\n",s);
    /*rewind(p);
    fgets(ch,200,p);
    printf("%s",ch);
     for(i=0;i<N;i++)
    {
    fread(&a[i],sizeof(struct rest),1,fp);
            if(a[i].tnum==0)
            break;
        printf("%-5d| %d/%02d/%02d | %d:%d:%02d| %-7d | %-9d| %-11s| %-9d| %-7.1f| %.1f\n",a[i].num,a[i].hour,a[i].month,a[i].day,  a[i].hour,a[i].min,a[i].sec,a[i].tnum,a[i].cnum,a[i].name,a[i].money,a[i].discount,a[i].fmoney);
    }
    fclose(p);*/
    fclose(fp);
    return 0;
}
