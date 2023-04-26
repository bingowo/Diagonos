#include <stdio.h>
#include <stdlib.h>
int plus(int*p1,int*p2,int q1,int q2)
{
    int i=0,temp;
    for(i=0;i<q1||i<q2;i++)
    {
        temp=p1[i]+p2[i];
        p1[i]=temp%10;
        p1[i+1]=temp/10;
    }
    if(p1[i]){i++;}
    return i;
}
void minus(char*p1,char*p2,int q1,int q2)
{
    int i=0,x;
    for(;i<q2;i++)
    {
        if(p1[i]>=p2[i]){p1[i]-=p2[i];}
        else{
                p1[i]=p1[i]+10-p2[i];
                for(x=i+1;p1[x]==0;x++){p1[x]=9;}
                p1[x]--;
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    unsigned long long a,min,sum;
    int t1,t2,c1[22]={0},c2[22]={0},i;
    scanf("%llu",&a);
    min=a;
    sum=a;
    for(t1=0;a;a/10)
    {c1[t1]=a%10;}
    for(i=1;i<n;i++)
    {
        scanf("%llu",&a);
        sum^=a;
        if(a<min){min=a;}
        for(t2=0;a;a/10)
         {c2[t2]=a%10;}
     t1=plus(c1,c2,t1,t2);}
     if(sum){printf("-1");return 0;}
     for(t2=0;min;min/10)
         {c2[t2]=min%10;}
    minus(c1,c2,t1,t2);
    for(i=t1-1;c1[i]==0;i--);
    for(;i>=0;i--)
    {
        printf("%d",c1[i]);
    }


}
