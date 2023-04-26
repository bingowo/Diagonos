#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void in(int a,int b,int c,int d);
void duqu(int a,int b,int c,int d);
void add(int a,int b,int c,int d);
void mul(int a,int b,int c,int d);
void sub(int a,int b,int c,int d);
void divv(int a,int b,int c,int d);
void out(int a,int b,int c,int d);
void mov(int a,int b,int c,int d);


void duqu(int a,int b,int c,int d)
{
    char s[10];
    memset(s,0,sizeof(char)*10);
    if(scanf("%s",s)==EOF) return;
    //printf("\n in duqu s=%s\n",s);
    if(strcmp(s,"IN")==0) return in(a,b,c,d);
    else if(strcmp(s,"ADD")==0) return add(a,b,c,d);
    else if(strcmp(s,"MOV")==0) return mov(a,b,c,d);
    else if(strcmp(s,"MUL")==0) return mul(a,b,c,d);
    else if(strcmp(s,"SUB")==0) return sub(a,b,c,d);
    else if(strcmp(s,"DIV")==0) return divv(a,b,c,d);
    else if(strcmp(s,"OUT")==0) return out(a,b,c,d);
    else return;
}

void in(int a,int b,int c,int d)
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    //printf("\ntest:%s\n",s);
    int i,len=strlen(s),j,re=0;
    for(i=0;i<len;i++)
    {
        //printf("hello\n");
        if(s[i]==',')
        {
            for(j=i+1;j<len;j++)
            {
                re*=10;
                re+=(s[j]-'0');
            }
            break;

        }
    }
    //printf("re=%d\n",re);
    switch(s[0])
    {
        case 'A':a=re;break;
        case 'B':b=re;break;
        case 'C':c=re;break;
        case 'D':d=re;break;
        default:printf("wrong form:%c\n",s[0]);break;
    }
    return duqu(a,b,c,d);
}

void add(int a,int b,int c,int d)
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0;

    switch(s[3])
    {
        case 'A':re=a;break;
        case 'B':re=b;break;
        case 'C':re=c;break;
        case 'D':re=d;break;
        default:printf("wrong form:%c\n",s[3]);break;
    }

    switch(s[0])
    {
        case 'A':a+=re;break;
        case 'B':b+=re;break;
        case 'C':c+=re;break;
        case 'D':d+=re;break;
        default:printf("wrong form:%c\n",s[0]);break;
    }
    return duqu(a,b,c,d);
}

void mov(int a,int b,int c,int d)
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0;

    switch(s[3])
    {
        case 'A':re=a;break;
        case 'B':re=b;break;
        case 'C':re=c;break;
        case 'D':re=d;break;
        default:printf("wrong form:%c\n",s[3]);break;
    }

    switch(s[0])
    {
        case 'A':a=re;break;
        case 'B':b=re;break;
        case 'C':c=re;break;
        case 'D':d=re;break;
        default:printf("wrong form:%c\n",s[0]);break;
    }
    return duqu(a,b,c,d);
}

void mul(int a,int b,int c,int d)
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0;

    switch(s[3])
    {
        case 'A':re=a;break;
        case 'B':re=b;break;
        case 'C':re=c;break;
        case 'D':re=d;break;
        default:printf("wrong form:%c\n",s[3]);break;
    }

    switch(s[0])
    {
        case 'A':a*=re;break;
        case 'B':b*=re;break;
        case 'C':c*=re;break;
        case 'D':d*=re;break;
        default:printf("wrong form:%c\n",s[0]);break;
    }
    return duqu(a,b,c,d);
}

void sub(int a,int b,int c,int d)
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0;

    switch(s[3])
    {
        case 'A':re=a;break;
        case 'B':re=b;break;
        case 'C':re=c;break;
        case 'D':re=d;break;
        default:printf("wrong form:%c\n",s[3]);break;
    }

    switch(s[0])
    {
        case 'A':a-=re;break;
        case 'B':b-=re;break;
        case 'C':c-=re;break;
        case 'D':d-=re;break;
        default:printf("wrong form:%c\n",s[0]);break;
    }
    return duqu(a,b,c,d);
}

void divv(int a,int b,int c,int d)
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    int i,len=strlen(s),re=0;

    switch(s[3])
    {
        case 'A':re=a;break;
        case 'B':re=b;break;
        case 'C':re=c;break;
        case 'D':re=d;break;
        default:printf("wrong form:%c\n",s[3]);break;
    }

    switch(s[0])
    {
        case 'A':a/=re;break;
        case 'B':b/=re;break;
        case 'C':c/=re;break;
        case 'D':d/=re;break;
        default:printf("wrong form:%c\n",s[0]);break;
    }
    return duqu(a,b,c,d);
}

void out(int a,int b,int c,int d)
{
    char s[100];
    memset(s,0,sizeof(char)*100);
    scanf("%s",s);
    switch(s[0])
    {
        case 'A':printf("%d\n",a);break;
        case 'B':printf("%d\n",b);break;
        case 'C':printf("%d\n",c);break;
        case 'D':printf("%d\n",d);break;
        default:printf("wrong form:%c\n",s[0]);break;
    }
    return duqu(a,b,c,d);
}

int main()
{
    int a=0,b=0,c=0,d=0;
    duqu(a,b,c,d);
    return 0;

}
