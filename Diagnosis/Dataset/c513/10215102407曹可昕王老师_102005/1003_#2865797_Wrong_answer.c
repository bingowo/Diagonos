#include<stdio.h>

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
    {    if(d1.a>d2.a) return 1;
         else return -1;
    }
}




int main()
{
    int n,i,d,t,question,s;
    scanf("%d",&question);
    for(s=0;s<question;s++)
{
    printf("case #%d:\n",s);
    struct data p[10000];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {   scanf("%lld",&p[i].a);
        d=1;p[i].number=0;
        for(t=0;t<64;t++)
        {
            if(p[i].a&d)
                p[i].number++;
            d=d<<1;
        }
    }
    qsort(p,n,sizeof(p[0]),cmp);
     for(i=0;i<n-1;i++)
            printf("%lld ",p[i].a);
        printf("%lld\n",p[i].a);
}
    return 0;
}
