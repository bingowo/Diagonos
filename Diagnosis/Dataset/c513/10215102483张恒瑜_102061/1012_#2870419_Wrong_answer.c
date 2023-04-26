#include<stdio.h>
#include<string.h>
#include<stdlib.h>

long long a=0,b=0;

int findfirst(char A[],int x)
{
    int i;
    for(i=0;i<strlen(A);i++)
    {
        if(A[i]==x) return i;
    }
    return -1;
}

int findlast(char A[],int x)
{
    int i;
    for(i=strlen(A)-1;i>=0;i--)
    {
        if(A[i]==x) return i;
    }
    return -1;
}

int calr(long long a0,long long b0)
{
    if(a0%2==b0%2) return 0;
    else return 1;
}

void calab(long long a0,long long b0,int r)
{
    a=(r-a0+b0)/2;
    b=(r-a0-b0)/2;
}

int main()
{
    char input[100]={'\0'},stra[50]={'\0'},strb[50]={'\0'};
    scanf("%s",input);
    int i;
    if(findfirst(input,'i')==-1) a=atoll(input);
    else
    {
        if(input[0]=='i') b=1;
        else if(input[0]=='-' && input[1]=='i') b=-1;
        else
        {
            input[strlen(input)-1]='\0';
            if(findfirst(input,'+')==-1 || findlast(input,'-')==0 ) b=atoll(input);
            else
            {
                
                if((i=findfirst(input,'+'))!=-1);
                else i=findlast(input,'-');
                strncpy(stra,input,i);
                a=atoll(stra);
                if(input[strlen(input)-1]=='+') b=1;
                else if(input[strlen(input)-1]=='-') b=-1;
                else
                {
                    int j;
                    for(j=0;i<strlen(input);i++,j++)
                    {
                        strb[j]=input[i];
                    }
                    b=atoll(strb);
                }
            }
        }
    }
    printf("%lld %lld\n",a,b);
    char res[500]={'\0'};
    int r;
    i=0;
    while (a!=0 || b!=0)
    {
        res[i]=calr(a,b)+'0';
        calab(a,b,res[i]-'0');
        i++;
    }
    for(i=strlen(res)-1;i>=0;i--) printf("%c",res[i]);
    return 0;
}