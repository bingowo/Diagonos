#include<stdio.h>
#include<string.h>
#include<malloc.h>

void func(char*dest,char*src,int l)
{
    int l1=strlen(src);
    for(int i=0;i<l1;i++)
    {
        dest[i]=src[i];
        dest[i+l1]=(src[i]=='0'?'1':'0');
    }
    dest[l]='\0';
}

int main()
{
    char**s;
    int l=1;
    s=(char**)malloc(sizeof(char*)*16);
    for(int i=0;i<16;i++)
    {
        s[i]=(char*)malloc(sizeof(char)*(l+1));
        if(i==0) {s[0][0]='0';s[0][1]='\0';}
        else func(s[i],s[i-1],l);
        l*=2;
    }
    int t;scanf("%d",&t);
    printf("%s",s[t]);

    return 0;
}