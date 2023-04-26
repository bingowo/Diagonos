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
        {if(c[m]==0)
        c[m]='0';}
    int f=0;
    j=14;
    while((s[f]!=0)&&(s[f+1]!=0)&&(s[f+2]!=0))
    {
        for(int k=j;k<j+10;k++)
            c[k]='0';
        char z[5]={'0'};//容量不能太小，比所需的多一点
        z[0]=s[f];
        z[1]=s[f+1];
        z[2]=s[f+2];
        num=atoi(z);
        int v=j+9;
        while(num)
        {
            c[v]=num%2+'0';
            num=num/2;
            v=v-1;
        }
        j=j+10;
        f=f+3;
    }
    while((s[f]!=0)&&(s[f+1]!=0))
    {
        for(int k=j;k<j+7;k++)
            c[k]='0';
        char z[5]={'0'};
        z[0]=s[f];
        z[1]=s[f+1];
        num=atoi(z);
        int v=j+6;
        while(num)
        {
            c[v]=num%2+'0';
            num=num/2;
            v=v-1;
        }
        j=j+7;
        f=f+2;
    }
    while(s[f]!=0)
    {
        for(int k=j;k<j+4;k++)
            c[k]='0';
        char z[5]={'0'};
        z[0]=s[f];
        num=atoi(z);
        int v=j+3;
        while(num)
        {
            c[v]=num%2+'0';
            num=num/2;
            v=v-1;
        }
        j=j+4;
        f=f+1;
    }
    printf("%s\n",c);
    return 0;
}
