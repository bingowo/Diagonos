#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#define NUM 0
#define VECTOR 1
typedef long long ll;
typedef struct MAP
{
    char name[5];
    ll num[100];
    int type;
    int vectorlen;
}MAP;
MAP map[10000]={{'\0'},{0},0,0};
int validx=0;

void reverse(char s[])
{
    int len=strlen(s);
    char temp;
    for(int i=0;i<len/2;i++)
    {
        temp=s[i];
        s[i]=s[len-1-i];
        s[len-1-i]=temp;
    }
}

int searchmap(char s[])
{
    for(int i=0;i<10000;i++)
    {
        if(strcmp(s,map[i].name)==0) return i;
    }
    return -1;
}

MAP solve(char input[])
{
    char c;
    MAP res={{'\0'},0,0,0};
    int i=strlen(input)-1;
    while (i>=0)
    {
        c=input[i];
        if(isspace(c)) {i--;continue;}
        else if(c=='=')
        {
            char s[200]={'\0'};
            i--;
            int tmpidx=0;
            while (c=input[--i])
            {
                if(isalpha(c))
                    s[tmpidx++]=c;
                else break;
            }
            reverse(s);
            tmpidx=searchmap(s);
            if(tmpidx==-1)
            {
                map[validx]=res;
                strcpy(map[validx].name,s);
                validx++;
            }
            else
            {
                map[tmpidx]=res;
                strcpy(map[tmpidx].name,s);
            }
        }
        else if(isdigit(c))
        {
            char s[200]={'\0'};
            int tmpidx=1;
            s[0]=c;
            while(c=input[--i])
            {
                if(isdigit(c))
                    s[tmpidx++]=c;
                else break;
            }
            reverse(s);
            res.num[res.vectorlen]=atoll(s);
            res.vectorlen++;
            if(res.vectorlen!=0) res.type=VECTOR;
        }
        else if(isalpha(c))
        {
            char s[200]={'\0'};
            int tmpidx=1;
            s[0]=c;
            while (c=input[--i])
            {
                if(isalpha(c))
                    s[tmpidx++]=c;
                else break;
            }
            reverse(s);
            tmpidx=searchmap(s);
            if(tmpidx!=-1)
            {
                res=map[tmpidx];
            }
        }
        else if(c=='+'||c=='-'||c=='*')
        {
            ll tmp=res.num[0];
            char s[200]={'\0'},flag=c;
            int tmpidx=0;
            i--;
            while(c=input[--i])
            {
                if(isdigit(c)||isalpha(c))
                    s[tmpidx++]=c;
                else break;
            }
            reverse(s);
            if(isdigit(s[0]))
            {
                switch (flag)
                {
                    case '+':res.num[0]=atoll(s)+tmp;break;
                    case '-':res.num[0]=atoll(s)-tmp;break;
                    case '*':res.num[0]=atoll(s)*tmp;break;
                    default:break;
                }
            }
            else
            {
                tmpidx=searchmap(s);
                res=map[tmpidx];
                for(int j=0;j<map[tmpidx].vectorlen;j++)
                    switch (flag)
                    {
                        case '+':res.num[j]+=tmp;break;
                        case '-':res.num[j]-=tmp;break;
                        case '*':res.num[j]*=tmp;break;
                        default:break;
                    }
            }
        }
        else if(c=='/')
        {
            i-=2;
            char flag=input[i--],s[200]={'\0'};
            int idx=i+5,tmpidx=0;
            while (c=input[idx++])
            {
                if(isalpha(c))
                    s[tmpidx++]=c;
                else break;
                if(idx==strlen(input)) break;
            }
            tmpidx=searchmap(s);
            for(int j=0;j<map[tmpidx].vectorlen-1;j++)
            {
                switch (flag)
                {
                    case '+':map[tmpidx].num[j+1]+=map[tmpidx].num[j];break;
                    case '-':map[tmpidx].num[j+1]-=map[tmpidx].num[j];break;
                    case '*':map[tmpidx].num[j+1]*=map[tmpidx].num[j];break;
                    default:break;
                }
            }
            map[tmpidx].num[0]=map[tmpidx].num[map[tmpidx].vectorlen-1];
            map[tmpidx].type=NUM;
            map[tmpidx].vectorlen=1;
            res=map[tmpidx];
        }
        else i--;
    }
    return res;
}

int main()
{
    int N;
    scanf("%d",&N);
    getchar();
    char input[200]={'\0'};
    while (N--)
    {
        memset(input,0,sizeof(input));
        gets(input);
        MAP res={{'\0'},0,0,0};
        int i;
        res=solve(input);
        if(res.type==VECTOR)
        {
            for(i=res.vectorlen-1;i>=0;i--) printf("%lld ",res.num[i]);
        }
        else printf("%lld",res.num[0]);
        printf("\n");

    }
    return 0;
}