#include<stdio.h>

int main()
{
    int n;
    int res=0;
    char s[100000];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s",s);
        for(int j=0;s[j];j++)
        {
            res=res*3;
            if(s[j]=='-') res=res-1;
            if(s[j]=='0') res=res+0;
            if(s[j]=='1') res=res+1;
        }
        printf("case #%d:\n%d\n",j,res);
    }
    return 0;
}