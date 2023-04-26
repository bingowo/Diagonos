#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000000];
    int i,d[129],max=0,len,r=0;
    scanf("%s",s);
    len=lenth(s);
    while(i!=len)
    {
        for(int j=0;j<129;j++) d[j]=0;
        for(;i<len;i++)
        {
            if(d[i]==0) r++;
            else break;
        }
        if(max<r) max=r;
        if(i!=len) i=i-r;
    }
    i=i-r;
    for(int j=0;j<max;j++) printf("%c",s[i+j]);
    return 0;
}