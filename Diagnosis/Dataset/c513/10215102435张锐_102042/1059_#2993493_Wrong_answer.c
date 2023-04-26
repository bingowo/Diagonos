#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b)
{
    int s1=*(int*)a,s2=*(int *)b;
    if(s1>s2) return 1;
    else return 0;
}
int gcd(int x,int y)
{
    int n=1;
    for(int i=1;i<=x;i++)
    {
        if(x%i==0&&y%i==0) n=i;
    }
    return n;
}
int main()
{
    int n,s;
    scanf("%d%d",&n,&s);
    int *p=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++) scanf("%d",&p[i]);
    int num=0,x=0,y=0;
    while(s)
    {
        qsort(p,n,sizeof(int),cmp);
        if(p[0]!=p[1]) {p[0]++,s--,num++;}
        else
        {
            for(int i=0;i<n-1;i++)
            {
                if(p[i]!=p[i+1])
                {
                    if((i+1)<=s) s-=(i-1),num+=1;
                    else x=s,y=i+1,s=0;
                    break;
                }
                if(p[i]==p[i+1]&&i==n-2)
                {
                    if((i+2)<=s) s-=(i+2),num+=1;
                    else x=s,y=i+2,s=0;
                    break;
                }
            }
        }
    }
    if(num==0) ;
    else printf("%d",num);
    int temp=gcd(x,y);
    if(num!=0&&x!=0&&y!=0) printf("+");
    if(x!=0&&y!=0)printf("%d/%d\n",x/temp,y/temp);
    return 0;
}
