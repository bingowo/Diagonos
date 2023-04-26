#include<stdio.h>
#include<stdlib.h>
#include<string.h>

itoa(int x,char y[65])
{
    int i=0;
    while(i<64){y[64-i]=(1<<i&&x)>>i+'0';i++;}
}

struct function
{
    char num[20];
    int numt;
    char nums[65];
    int ws;
};

int cmp(const void *a,const void *b)
{
    struct function *c=(struct function *)a;
    struct function *d=(struct function *)b;
    if((*c).ws!=(*d).ws)return (*d).ws-(*c).ws;
    else return (*c).numt-(*d).numt;
}


int main()
{
    int i,j,T,N,t1=1,t2,len,ws,k;
    itoa(int x,char y[65]);
    scanf("%d",&T);
    while(t1<=T)
    {
        printf("case #%d:\n",t1-1);
        t2=1;
        scanf("%d",&N);
        struct function dig[N];
        struct function swap;
        int m=0;
        while(t2++<=N)
        {
            scanf("%s",dig[m].num);
            dig[m].numt=atoi(dig[m].num);
            itoa(dig[m].numt,dig[m].nums);
            len=strlen(dig[m].nums);
            dig[m].ws=0;
            for(i=0;i<len;i++)if(dig[m].nums[i]=='1')dig[m].ws++;
            m++;
        }
        qsort(dig,N,sizeof(struct function),cmp);
        for(i=0;i<N;i++)printf("%s ",dig[i].num);
        printf("\n");
        t1++;
    }
}
