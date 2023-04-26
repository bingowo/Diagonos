#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c,d;
    int char s[100];
    void jinzhi (int n, int m,char x[])
    {
        char y[36]={"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
        char p ;
        int i=0,z=0,t=0;
        if (n<0)
        {
            x[0]='-';
            i++;
            n=-n;
            t=1;
        }
        while (n)
        {
            z=n%m;
            n=n/m;
            x[i]=y[z];
            i++;
        
        }
        i--;
        if(t)
        {
            printf("%c",x[0]);
            while (int j=i;j>=1;j--)
            {
                printf("%d",x[i]);
            }
        }
        else
        {
           while (int j=i;j>=0;j--)
            {
                printf("%d",x[i]);
            } 
        }
}
        
    }
    sacnf("%d",&a);
    for (int i=0;i<a;i++)
    {
        scanf("%d %d",&b,&c);
        