#include <stdio.h>
#include <stdlib.h>
void mult(int *s,int a)
{
    int last=0;
    for(int i=99999;i>=0;i--)
    {
        int temp=s[i]*a+last;
        if(temp<10) s[i]=temp,last=0;
        else if(temp>9)
        {
            s[i]=temp%10;last=temp/10;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        int a,b,n;
        scanf("%d%d%d",&a,&b,&n);
        int s[100000]={0};s[99999]=1;
        for(int j=0;j<b;j++)
        {
            mult(s,a);
        }
        printf("case #%d:\n",i);
        for(int j=100000-n;j<100000;j++) printf("%d",s[j]);
        printf("\n");
    }
    return 0;
}
