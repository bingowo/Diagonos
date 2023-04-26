#include <stdio.h>
#include <stdlib.h>
void mult(int *s,int a)
{
    int last=0;
    for(int i=999;i>=0;i--)
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
        int a,n;
        scanf("%d%d",&a,&n);
        int s[1000]={0};
        s[999]=1;
        for(int j=0;j<n;j++)
        {
            mult(s,a);
        }
        int p;
        for(p=0;;p++)
        {
            if(s[p]!=0) break;
        }
        printf("case #%d:\n",i);
        for(int j=p;j<1000;j++) printf("%d",s[j]);
        printf("\n");
    }
    return 0;
}
