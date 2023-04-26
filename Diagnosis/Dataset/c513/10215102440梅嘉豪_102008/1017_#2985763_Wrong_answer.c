#include <stdio.h>
#include <string.h>
int d[128]={0};

int pos=0;
int roman_to_int(char *s);

int main()
{
    char s[100];
    d['I']=1;
    d['X']=10;
    d['C']=100;
    d['M']=1000;
    d['V']=5;
    d['L']=50;
    d['D']=500;
    int ans=0;
    scanf("%s",s);
    ans+=roman_to_int(s);
    printf("%d",ans);
}
int roman_to_int(char *s)
{
    int n=strlen(s);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        int value=d[s[i]];
        if(i<n-1&&value<d[s[i]])    ans-=value;
        else ans+=value;
    }
    return ans;
}
