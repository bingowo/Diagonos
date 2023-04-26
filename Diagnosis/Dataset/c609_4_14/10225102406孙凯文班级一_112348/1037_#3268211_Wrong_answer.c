#include<stdio.h>
#include<string.h>
int main()
{
    char s[10000];
    int i,d[129],max=0,len,r=0,m=0;
    scanf("%s",s);
    len=strlen(s);
    while(i!=len)
    {
        for(int j=0;j<129;j++) d[j]=0;
        for(;i<len;i++)
        {
            if(d[s[i]]==0) r++;
            else break;
        }
        if(max<r) max=r,m=i-r-1;
        if(i!=len) i=i-r;
    }
    for(int j=0;j<max;j++) printf("%c",s[m+j]);
    return 0;
}
