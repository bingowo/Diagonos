#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int a[128];

void in(int a[]);
void duqu(int a[]);
void add(int a[]);
void mul(int a[]);
void sub(int a[]);
void divv(int a[]);
void out(int a[]);
void mov(int a[]);
void xchg(int a[]);
void and(int a[]);
void or(int a[]);
void xor(int a[]);


void duqu(int a[])
{
    char s[10];
    memset(s,0,sizeof(char)*10);
    if(scanf("%s",s)==EOF) return;
    //printf("\n in duqu s=%s\n",s);
    if(strcmp(s,"IN")==0) return in(a);
    else if(strcmp(s,"ADD")==0) return add(a);
    else if(strcmp(s,"MOV")==0) return mov(a);
    else if(strcmp(s,"MUL")==0) return mul(a);
    else if(strcmp(s,"SUB")==0) return sub(a);
    else if(strcmp(s,"DIV")==0) return divv(a);
    else if(strcmp(s,"OUT")==0) return out(a);
    else if(strcmp(s,"AND")==0) return and(a);
    else if(strcmp(s,"OR")==0) return or(a);
    else if(strcmp(s,"XOR")==0) return xor(a);
    else if(strcmp(s,"XCHG")==0) return xchg(a);
    else if(strcmp(s,"MOD")==0) return modd(a);
    else return;
}

void in(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),j,re=0,sign=1;

    for(i=0;i<len;i++)
    {
        //printf("hello\n");
        if(s[i]==',')
        {
            if(s[i+1]=='-') {i++;sign=-1;}
            for(j=i+1;j<len;j++)
            {
                re*=10;
                re+=(s[j]-'0');
            }
            re*=sign;
            break;

        }
    }
    //printf("re=%d\n",re);
    a[s[0]]=re;
    return duqu(a);
}

void add(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;
    if(len==5)
    {
        re=a[s[3]];
        a[s[0]]+=re;
        return duqu(a);
    }
    else if(len==8)
    {
        mid1=a[s[3]];
        mid2=a[s[6]];
        a[s[0]]=mid1+mid2;
        return duqu(a);
    }
    else printf("wrong len\n");
}

void mov(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0;
    a[s[0]]=a[s[3]];

    return duqu(a);
}

void mul(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;
    if(len==5)
    {
        re=a[s[3]];
        a[s[0]]*=re;
        return duqu(a);
    }
    else if(len==8)
    {
        mid1=a[s[3]];
        mid2=a[s[6]];
        a[s[0]]=mid1*mid2;
        return duqu(a);
    }
    else printf("wrong len\n");
}

void sub(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;
    if(len==5)
    {
        re=a[s[3]];
        a[s[0]]-=re;
        return duqu(a);
    }
    else if(len==8)
    {
        mid1=a[s[3]];
        mid2=a[s[6]];
        a[s[0]]=mid1-mid2;
        return duqu(a);
    }
    else printf("wrong len\n");
}

void divv(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;
    if(len==5)
    {
        re=a[s[3]];
        a[s[0]]/=re;
        return duqu(a);
    }
    else if(len==8)
    {
        mid1=a[s[3]];
        mid2=a[s[6]];
        a[s[0]]=mid1/mid2;
        return duqu(a);
    }
    else printf("wrong len\n");

}

void out(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    printf("%d\n",a[s[0]]);
    return duqu(a);
}

void and(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;
    if(len==5)
    {
        re=a[s[3]];
        a[s[0]]&=re;
        return duqu(a);
    }
    else if(len==8)
    {
        mid1=a[s[3]];
        mid2=a[s[6]];
        a[s[0]]=mid1&mid2;
        return duqu(a);
    }
    else printf("wrong len\n");
}

void or(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;
    if(len==5)
    {
        re=a[s[3]];
        a[s[0]]|=re;
        return duqu(a);
    }
    else if(len==8)
    {
        mid1=a[s[3]];
        mid2=a[s[6]];
        a[s[0]]=mid1|mid2;
        return duqu(a);
    }
    else printf("wrong len\n");
}

void xor(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;
    if(len==5)
    {
        re=a[s[3]];
        a[s[0]]^=re;
        return duqu(a);
    }
    else if(len==8)
    {
        mid1=a[s[3]];
        mid2=a[s[6]];
        a[s[0]]=mid1^mid2;
        return duqu(a);
    }
    else printf("wrong len\n");
}

 void xchg(int a[])
 {
     char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;

    mid1=a[s[0]];
    a[s[0]]=a[s[3]];
    a[s[3]]=mid1;
    return duqu(a);
 }

 void modd(int a[])
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0,mid1,mid2;
    if(len==5)
    {
        re=a[s[3]];
        a[s[0]]%=re;
        return duqu(a);
    }
    else if(len==8)
    {
        mid1=a[s[3]];
        mid2=a[s[6]];
        a[s[0]]=mid1%mid2;
        return duqu(a);
    }
    else printf("wrong len\n");
}

int main()
{
    int a[128];
    memset(a,0,sizeof(int)*128);
    duqu(a);
    return 0;

}
