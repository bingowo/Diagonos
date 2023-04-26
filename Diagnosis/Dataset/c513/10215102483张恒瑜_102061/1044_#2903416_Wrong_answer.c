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
    char in[50000]={'\0'};
    scanf("%s",in);
    int i=0,flag=0;
    while ((i=findfirst(in,'x'))!=-1)
    {
        if(in[i-1]=='0')
        {
            char tmp[50000]={'\0'};
            int index=0;
            i++;
            while ((in[i]>='0' && in[i]<='9') || (in[i]>='a' && in[i]<='f'))
            {
                tmp[index++]=in[i++];
            }
            if(strlen(tmp)!=0) {printf("%lld ",dtoh(tmp));flag=1;}
        }
        for(int j=0;j<=i;j++) in[j]='p';
    }
    if(flag==0) printf("-1");
    
    return 0;
}