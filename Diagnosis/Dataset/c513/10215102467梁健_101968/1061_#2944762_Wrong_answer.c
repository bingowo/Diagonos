#include<stdio.h>
#include<string.h>
typedef struct listnum
{
    char list[16];
    long long num;
}LISTNUM;
int main()
{
    LISTNUM* str= NULL;
    int T=0;
    scanf("%d",&T);
    str=(LISTNUM*)malloc(sizeof(LISTNUM)*T);
    for(int i=0;i<T;i++){
        scanf("%s",str[i].list);
        int a[128];
        for(int step=0;step<128;step++){
            a[step]=-1;
        }
        int num=0,N=1;
        char *p=str[i].list;
        a[*p]=1;
        int digit=0;
        while(*++p){
            if(a[*p]==-1){
                a[*p]=digit;
                if(digit==0)digit=2;
                else digit+=1;
                N++;
            }
        }
        if(N<2)N=2;
        long long res=0;
        p=str[i].list;
        while(*p){
            res=res*N+a[*p++];
        }
        str[i].num=res;
    }
    int cmp(const void *a,const void *b)
    {
        LISTNUM a1=*(LISTNUM*)a;
        LISTNUM b1=*(LISTNUM*)b;
        long long r1,r2;
        r1=a1.num,r2=b1.num;
        return r1>r2?1:-1;
    }
    qsort(str,T,sizeof(LISTNUM),cmp);
    for(int i=0;i<T;i++)printf("%s\n",str[i].list);
    return 0;
}
