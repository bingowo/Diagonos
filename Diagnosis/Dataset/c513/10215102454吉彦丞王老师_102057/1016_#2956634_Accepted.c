#include<stdio.h>
char ans[25];
int num[25];
void change(int j)
{
    int i;
    for(i=0;i<j;i++)
    {
        if(num[i]<=9&&num[i]>=0)
        {
            ans[i]=num[i]+'0';
        }
        else
        {
            ans[i]=num[i]-10+'A';
        }
    }
}
int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    int t=0;
    if(a==0)
    {
        printf("0");
    }
    else
    {
        while(a!=0)
        {
            if(a%b<0)
            {
                num[t]=a%b-b;
                a=a/b+1;
            }
            else
            {
                num[t]=a%b;
                a=a/b;
            }
            t++;
        }
        change(t);
        for(int i=t-1;i>=0;--i)
        {
            printf("%c",ans[i]);
        }
    }
    return 0;
}