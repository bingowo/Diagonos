#include<stdio.h>
#include<string.h>

int findfirst(char A[],int x)
{
    int i;
    for(i=0;i<strlen(A);i++)
    {
        if(A[i]==x) return i;
    }
    return -1;
}

long long dtoh(char x[])
{
    long long weight=1,res=0;
    for(int i=strlen(x)-1;i>=0;i--)
    {
        if(x[i]>='0' && x[i]<='9') res+=weight*(x[i]-'0');
        else if(x[i]>='a' && x[i]<='f') res+=weight*(x[i]-'a'+10);
        weight*=16;
    }
    return res;
}

int main()
{
    char in[10000]={'\0'};
    scanf("%s",in);
    int i=0,flag=0;
    while ((i=findfirst(in,'0'))!=-1)
    {
        for(int j=0;j<=i;j++) in[j]='p';
        if(in[++i]=='x')
        {
            char tmp[10000]={'\0'};
            int index=0;
            i++;
            while ((in[i]>='0' && in[i]<='9') || (in[i]>='a' && in[i]<='f'))
            {
                tmp[index++]=in[i++];
            }
            flag=1;
            if(strlen(tmp)!=0) printf("%lld ",dtoh(tmp));
        }
    }
    if(flag==0) printf("-1");
    
    return 0;
}