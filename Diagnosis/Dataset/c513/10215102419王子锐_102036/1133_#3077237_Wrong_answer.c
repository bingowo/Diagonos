#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int s[1<<15]={0};
    int cnt=0;
    for(int i=0;i<=n;i++) 
    {
        for(int j=0;j<(1<<(i-1));j++)
        {
            s[++cnt]=(!s[j]);
        }
        for(int i=0;i<=cnt;i++)printf("%d",s[i]);
        printf("\n");
        return 0;
    }
}
