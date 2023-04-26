#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int max(int a,int b)
{
    if(a>b) return a;
    else return b;
}

int min(int a,int b)
{
    if(a>b) return b;
    else return a;
}

int GCD(int a,int b)
{
    if(max(a,b)%min(a,b)==0) return min(a,b);
    return GCD(min(a,b),max(a,b)%min(a,b));
}



int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while (T--)
    {
        unsigned char input[150]={'\0'};
        int i=0;
        unsigned char c;
        while((c=getchar())!=EOF && c!='\n')
        {
            input[i++]=c;
        }
        int sum=0;
        for(i=0;i<strlen(input);i++)
        {
            unsigned char tmp=input[i];
            int j;
            for(;tmp!=0;tmp>>=1)
            {
                if(tmp&(unsigned char)1) sum++;
            }
        int all=(strlen(input))*sizeof(char)*8;
        int g=GCD(sum,all);
        printf("%d/%d\n",sum/g,all/g);
    }
    return 0;
}