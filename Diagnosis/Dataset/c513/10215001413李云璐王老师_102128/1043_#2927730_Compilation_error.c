#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char*insertA(char*s,int k)
{
    char d[110];
    int lens=strlen(s),i;
    for(i=0;i<=k;i++)
    d[i]=s[i];
    d[i]='A';
    for(i=k+2;i<=lens;i++)
    d[i]=s[i-1];
    d[i]='\0';
    return d;
}
char*insertB(char*s,int k)
{
    char d[110];
    int lens=strlen(s),i;
    for(i=0;i<=k;i++)
    d[i]=s[i];
    d[i]='B';
    for(i=k+2;i<=lens;i++)
    d[i]=s[i-1];
    d[i]='\0';
    return d;
}
char*insertC(char*s,int k)
{
    char d[110];
    int lens=strlen(s),i;
    for(i=0;i<=k;i++)
    d[i]=s[i];
    d[i]='C';
    for(i=k+2;i<=lens;i++)
    d[i]=s[i-1];
    d[i]='\0';
    return d;
}

int jiancha(char*s)
{
    int len=strlen(s),k;
    for(k=1;k<len;k++)
    if(s[k]==s[k-1]) break;
    if(k==len) return 1;
    else return 0;
}

char*xiaochu(char*s)
{
    char c[110];
    c[0]=s[0];
    int lens=strlen(s);
    while(jiancha(s)==0)
    {
        for(int k=1,l=1;k<lens;k++)
        {if(s[k]==s[k-1]) l--;
        if(s[k]!=s[k-1]) {c[l]=s[k];l++;}}
        strcpy(s,c)
    }
    return s;
}

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char a[110];
        scanf("%s",a);
        int len=strlen(a),max=0;
        for(int k=0;k<len;k++)
        {
            char b[110]={'\0'},c[110]={'\0'};
            b=insertA(a,k);
            c=xiaochu(b);
            max=(max>(len-strlen(c)))?max:(len-strlen(c));
        }
        for(int k=0;k<len;k++)
        {
            char b[110]={'\0'},c[110]={'\0'};
            b=insertB(a,k);
            c=xiaochu(b);
            max=(max>(len-strlen(c)))?max:(len-strlen(c));
        }
        for(int k=0;k<len;k++)
        {
            char b[110]={'\0'},c[110]={'\0'};
            b=insertC(a,k);
            c=xiaochu(b);
            max=(max>(len-strlen(c)))?max:(len-strlen(c));
        }
        printf("case #%d:\n);
        printf("%d\n",max);
        
    }
    return 0;
}