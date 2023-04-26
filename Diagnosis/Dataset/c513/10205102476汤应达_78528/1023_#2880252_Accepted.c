#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int getnum(char*s)
{
    int ex=1,res=0,l=strlen(s);
    for(int i=l-1;i>=0;i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {res+=(s[i]-'0')*ex;ex*=10;}
    }
    if(ex==1) return -1;
    else return res;
}

int cmp(const void*a,const void *b)
{
    char*a0=(char*)a,*b0=(char*)b;
    int n1=getnum(a0),n2=getnum(b0);
    if(n1>n2) return 1;
    else if(n1<n2) return -1;
    else return strcmp(a0,b0);
}

int main()
{
    int cnt=0;
    char words[100][31];
    while ((scanf("%s",words[cnt++]))!=EOF);
    qsort(words,cnt-1,sizeof(words[0]),cmp);
    for(int i=0;i<cnt-1;i++) printf("%s ",words[i]);

    return 0;
}