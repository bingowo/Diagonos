#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void itob(int n,char s[100],int b)
{
    int i=0,j,t;
    if(n<0){n=abs(n);s[i]='-';i++;}
    for(i;n>0;i++)
    {
        if(n%b>=10)s[i]='A'+n%b-10;
        else s[i]=48+n%b;
        n=n/b;
    }
    
    if(s[0]=='-'){for(j=1;j<=i/2;j++){t=s[j];s[j]=s[i-j];s[i-j]=t;}}
    else{for(j=0;j<=i/2-1;j++){t=s[j];s[j]=s[i-j-1];s[i-j-1]=t;}}
    s[i]='\0';
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
            itob(dig[m].numt,dig[m].nums,2);
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
