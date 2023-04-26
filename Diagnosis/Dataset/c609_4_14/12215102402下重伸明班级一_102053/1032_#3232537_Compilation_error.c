#include<stdio.h>
#include<string.h>
int main()
{
    char a[100];
    gets(a);
    int x=strlen(a);
    int y[x]={0};
    int z=0,m=0;
    for(int i=0;i<x;i++)
    {
        if(a[i]==a[i+1])
        {
            z++;
        }
        else
        {
            y[z]++;
        }
    }
    for(int ii=0;ii<x;ii++)
    {
        if(m<y[ii])
            m=y[ii];
    }
    printf("%d",m);
    
    
}