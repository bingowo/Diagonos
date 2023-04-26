#include<stdio.h>
#include<string.h>
int Turn(char s[1000])
{
    int n = strlen(s);
    int i,j;
    int x = 0,m = 1,y;
    for(i = n-1;i>=0;i--)
    {
        if(s[i] =='-') y = -1;
        else if(s[i] =='0') y = 0;
        else if(s[i] =='1') y = 1;
        x = x+y*m;
        m = m*3;
    }
    return x;
}
int main()
{
    int n;
    scanf("%d",&n);
    char s[n][1000];
    int i,j;
    for(i = 0;i<n;i++)
    {
        scanf("%s",s[i]);
    }
    for(i = 0;i<n;i++)
    {
        printf("case #%d:\n%d\n",i,Turn(s[i]));
    }
    return 0;
}
