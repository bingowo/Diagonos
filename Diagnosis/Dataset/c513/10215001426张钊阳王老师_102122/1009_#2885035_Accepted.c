#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int m,l,temp,count,t;
    scanf("%d\n",&m);
    char s[1200];
    int GCD(int a,int b);
    for(int i=0;i<m;i++)
    {
        count=0;
        gets(s);
        l=strlen(s);
        int total=8*l;
        for(int z=0;z<l;z++)
        {
            while(s[z]!=0)
            {
                count++;
                s[z]=s[z]&(s[z]-1);
            }
        }
        t=GCD(count,total);
        printf("%d/%d\n",count/t,total/t);
    }
    return 0;
}
int GCD(int a,int b)
{
    if(b%a!=0) return GCD(b%a,a);
    else return a;
}
