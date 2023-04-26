#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
    int T;
    scanf("%d",&T);
    char s[100];
    for(int i=0;i<T;i++)
    {
        scanf("%s",s);
        int s1[100];
        for(int q=0;q<100;q++) s1[q]=-1;
        int m=strlen(s);
        for(int j=0;j<m;j++)
        {
            if(s[j]=='-') s1[j]=-1;
            if(s[j]=='0') s1[j]=0;
            if(s[j]=='1') s1[j]=1;
        }
        int ans=0;
        for(int k=0;k<m;k++)
            ans=ans*3+s1[k];
        printf("case #%d:\n%d\n",i,ans);
        ans=0;
    }
}
