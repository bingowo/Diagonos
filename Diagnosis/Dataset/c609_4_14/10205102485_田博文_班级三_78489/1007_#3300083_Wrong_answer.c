#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct data
{
long long int a;
int number;
};

int cmp(const void *a,const void *b)
{
struct data d1,d2;
d1=*((struct data *)a);
d2=*((struct data *)b);
if(d2.number!=d1.number)
return d2.number-d1.number;
else
{ if(d1.a>d2.a) return 1;
else return -1;
}
}

int main(){
    int ques_num=0;
    scanf("%d",&ques_num);
    for(int mmm=0;mmm<ques_num;mmm++)
    {
    int n=0;
    struct data p[10000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&p[i].a);
        int d=1;p[i].number=0;
        for(int t=0;t<64;t++)
        {
            if(p[i].a&d) p[i].number++;
        d=d<<1;
        }
    }
        qsort(p,n,sizeof(p[0]),cmp);
        printf("case #%d:",mmm);
        for(int i=0;i<n-1;i++)
            printf("%lld ",p[i].a);
        printf("%lld\n",p[n].a);

    }
}


