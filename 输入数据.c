#include "stdio.h"
#include "time.h"
#include "string.h"
#define N 1000
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
}rest[N];
int main(int argc, char const *argv[])
{
    FILE *fp;
    struct rest a;
    struct tm *p;
    int i,j,t=0,c=0;
    char ch[200];
    time_t timep;
    time(&timep);
    p=localtime(&timep);//�˺�����õ�tm�ṹ���ʱ�䣬���Ѿ����й�ʱ��ת��Ϊ����ʱ��
    //p = gmtime(&timep); //�����ں�ʱ��ת��Ϊ��������(GMT)ʱ��ĺ���
    //printf("%d:%d:%d",p->tm_hour,p->tm_min,p->tm_sec);
    fp=fopen("E:\\c\\keshe\\restaurant.txt","w");
    fputs("��� | ����       | ʱ��    | ̨���  | �˿����� | �Ӵ������� | ���ѽ�� | �ۿ��� | ʵ�ս��\n",fp);
    printf("���   ʱ��     ̨���   �˿�����   �Ӵ�������   ���ѽ��   �ۿ���   ʵ�ս��\n");
    for(i=0;i<N;i++)
    {
        rest[i].num=i+1;

        rest[i].year=1900+p->tm_year;rest[i].month=1+p->tm_mon;rest[i].day=p->tm_mday;
        rest[i].hour=p->tm_hour;rest[i].min=p->tm_min;rest[i].sec=p->tm_sec;

        scanf("%d%d",&rest[i].tnum,&rest[i].money);

         if(1==rest[i].tnum)
         {
             strcpy(rest[i].name,"�ű�");
             rest[i].cnum=++t;
         }

         else
         {
            strcpy(rest[i].name,"�Ŷ�");
            rest[i].cnum=++c;
        }

        if(rest[i].money>=0&&rest[i].money<=100)
            rest[i].discount=10;

        else if(rest[i].money>100&&rest[i].money<=200)
            rest[i].discount=9.5;

        else if(rest[i].money>200&&rest[i].money<=500)
            rest[i].discount=9;

        else rest[i].discount=8;

        rest[i].fmoney=rest[i].money*rest[i].discount/10;

       //  scanf("%d%s%d%d%s%d%s%d",&rest[i].num,rest[i].time,&rest[i].tnum,&rest[i].cnum,rest[i].name,&rest[i].money,rest[i].discount,&rest[i].fmoney);
        fwrite(&rest[i],sizeof(rest[0]),1,fp);
            if(0==rest[i].tnum)
            break;
    }
    rewind(fp);
   fclose(fp);
    fp=fopen("E:\\c\\keshe\\restaurant.txt","r");
    fgets(ch,200,fp);
    printf("%s", ch);
    for(j=0;j<N;j++)
    {fread(&a,sizeof(rest[0]),1,fp);
    if(a.tnum==0)
    break;

    printf("%-5d| %d/%02d/%02d | %d:%02d:%02d| %-7d | %-9d| %-11s| %-9d| %-7.1f| %.1f\n",a.num,a.year,a.month,a.day,a.hour,a.min,a.sec,a.tnum,a.cnum,a.name,a.money,a.discount,a.fmoney);

    }
    fclose(fp);
    return 0;
}

