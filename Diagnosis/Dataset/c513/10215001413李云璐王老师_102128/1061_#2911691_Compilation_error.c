#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    int n;
    scanf("%d\n",n);
    for(int i=0;i<n;i++)
    {
        char s[16];
        scanf("%s\n",s);
        int len=strlen(s);
        int a[128];
        for(int k=0;k<128;k++)
        a[k]=-1;
        a[s[0]]=1;
        for(int k=2;k<len;k++)
        {
            if(a[s[i]]==-1) a[s[i]]=
        }
    }
}