#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{   char s[500]={'\0'};
    char c[2000]={'\0'};
    c[0]='0';
    c[1]='0';
    c[2]='0';
    c[3]='1';
    scanf("%s",&s);
    int num=strlen(s);
    int j=13;
    while(num)
    {
        c[j]=num%2+'0';
        num=num/2;
        j=j-1;
    }
    for(int m=4;m<=13;m++)
        if(c[m]==0)
        c[m]='0';
    num=strlen(s);
    int k=0;
    char l[3]={'\0'};
    int v=14;
    char z[10]={'\0'};
    char z1[7]={'\0'};
    char z2[4]={'\0'};
    while (num)
    {
        if(num>=3)
            {l[0]=s[k];
            l[1]=s[k+1];
            l[2]=s[k+2];
            int litter=atoi(l);
            int x1=9;
            while(litter)
            {
                z[x1]=litter%2+'0';
                litter=litter/2;
                x1=x1-1;
            }
            for(int x2=0;x2<=9;x2++)
            {
                if(z[x2]==0)
                    z[x2]='0';
            }
            for(int x3=0;x3<=9;x3++)
            {
                c[v]=z[x3];
                v=v+1;
            }
            k=k+3;
            num=num-3;}
        else if(num==2)
        {
            l[0]=s[k];
            l[1]=s[k+1];
            l[2]=0;
            int litter=atoi(l);
            int x1=6;
            while(litter)
            {
                z1[x1]=litter%2+'0';
                litter=litter/2;
                x1=x1-1;
            }
            for(int x2=0;x2<=6;x2++)
            {
                if(z1[x2]==0)
                    z1[x2]='0';
            }
            for(int x3=0;x3<=6;x3++)
            {
                c[v]=z1[x3];
                v=v+1;
            }
            num=num-2;
        }
        else
        {
            l[0]=s[k];
            l[1]=0;
            l[2]=0;
            int litter=atoi(l);
            int x1=3;
            while(litter)
            {
                z2[x1]=litter%2+'0';
                litter=litter/2;
                x1=x1-1;
            }
            for(int x2=0;x2<=3;x2++)
            {
                if(z2[x2]==0)
                    z2[x2]='0';
            }
            for(int x3=0;x3<=3;x3++)
            {
                c[v]=z2[x3];
                v=v+1;
            }
            num=num-1;
        }
    }
    printf("%s",c);
    return 0;
}
