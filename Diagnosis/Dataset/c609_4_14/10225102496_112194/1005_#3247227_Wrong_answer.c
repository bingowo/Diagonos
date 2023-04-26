#include<stdio.h>
#include<string.h>

int main()
{
    int n,i,j;
    int res=0;
    char s[100000];
    scanf("%d",&n);
    int len;
    for(i=0;i<n;i++)
    {
        scanf("%s",s);
        len=strlen(s);
        for(j=0;j<len;j++)
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