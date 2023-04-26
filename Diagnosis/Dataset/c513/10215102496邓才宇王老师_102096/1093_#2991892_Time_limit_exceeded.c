#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 200
void add(int a[],int b[])
{
    int i;
    for(i=N-1;i>0;i--)
    {
        a[i] += b[i];
        a[i-1] += a[i]/10;
        a[i] %= 10;
    }
}void output(int a[])
{
    int i=0;
    while(i<N && a[i]==0) i++;
    if(i>=N)
    { printf("0\n"); return;}

    while(i<N)
        printf("%d",a[i++]);
    printf("\n");

}
int main()
{
    char s[200];
    scanf("%s",s);
    int m[200]={0};
    int b[200]={0};
    b[199]=1;
    int M=200;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        m[--M]=s[i]-'0';
    }
    while(1)
    {
        add(m,b);
        int flag=0;
        int ans=0;
        for(int j=0;j<200;j++)
        {
            ans+=m[j];
            if(m[j]==9) flag=1;
        }
        if(ans%9!=0&&flag==0)
        {
            output(m);
            break;
        }
    }
}

