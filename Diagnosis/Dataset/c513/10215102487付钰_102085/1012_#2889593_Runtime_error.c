#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

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
    if(a0<0) a0=-a0;
    if(b0<0) b0=-b0;
    if(a0%2==b0%2) return 0;// 如果 均为偶数或均为奇数，则令 为此外，如果一奇一偶，则令 为 。
    else return 1;
}

void calab(long long a0,long long b0,int r)
{
    a0=(r-a0+b0)/2;
    b0=(r-a0-b0)/2;
}
int main()
{
    char input[5000]={'\0'},stra[5000]={'\0'},strb[5000]={'\0'};
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
            if(findfirst(input,'+')==-1 && findfirst(input,'-')==-1) b=atoll(input);
            else if(findlast(input,'-')==0 && findfirst(input,'+')==-1) b=atoll(input);
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

    char res[10000]={'\0'};
    i=0;
    while (a!=0 || b!=0)
    {
        res[i]=calr(a,b)+'0';
        calab(a,b,res[i]-'0');
        i++;
    }
    if(strlen(res)==0) printf("0");
    for(i=strlen(res)-1;i>=0;i--) printf("%c",res[i]);
    return 0;
}