#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct data
{
    char serial[100];//学号
    int SUM;//总分
};

int cmp(const void *a,const void *b)
{
    struct data d1,d2;int t;
    d1=*((struct data*)a);d2=*((struct data*)b);
    t=d2.SUM-d1.SUM;
    if(t==0) t=strcmp(d1.serial,d2.serial);
    return t;
}

int main()
{
    int n,i,j,q,flag;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        int rs,ts,suc,format[100];
        scanf("%d",&rs);
        struct data per[100];
        scanf("%d",&ts);scanf("%d",&suc);
        for(j=1;j<ts+1;j++) scanf("%d",&format[j]);
        for(j=0;j<rs;j++)
        {
            char str[100];int sum=0;
            scanf("%s",per[j].serial);getchar();
            gets(str);int l=strlen(str);
            for(q=2;q<l;q+=2) sum+=format[str[q]-'0'];
            per[j].SUM=sum;
        }
        qsort(per,rs,sizeof(per[0]),cmp);
        for(j=0,flag=0;j<rs;j++) if(per[j].SUM>=suc) flag++;
        printf("case #%d:\n",i);printf("%d\n",flag);
        for(j=0,flag=0;j<rs;j++)
            if(per[j].SUM>=suc) printf("%s %d\n",per[j].serial,per[j].SUM);
    }
    return 0;
}

