#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct function
{
    char num[20];
    int numt;
    char nums[65];
    int ws;
};

int main()
{
    int i,j,T,N,t1=1,t2,len,ws,k;
    scanf("%d",&T);
    while(t1<=T)
    {
        printf("case #%d",t1-1);
        t2=1;
        scanf("%d",&N);
        struct function dig[N];
        struct function swap;
        int m=0;
        while(t2++<=N)
        {
            scanf("%s",dig[m].num);
            dig[m].numt=atoi(dig[m].num);
            itoa(dig[m].numt,dig[m].nums,2);
            len=strlen(dig[m].nums);
            dig[m].ws=0;
            for(i=0;i<len;i++)if(dig[m].nums[i]=='1')dig[m].ws++;
        }m++;
        for(i=0;i<N;i++)
            {
                k=i;
                for(j=i+1;j<N;j++)if(dig[j].ws>dig[k].ws||dig[j].ws==dig[k].ws&&dig[j].numt<dig[k].numt)k=j;
                if(k!=i){swap=dig[i];dig[i]=dig[k];dig[k]=swap;}
            }
        for(i=0;i<N;i++)printf("%s ",dig[i].num);
        printf("\n");
        t1++;
    }
}
