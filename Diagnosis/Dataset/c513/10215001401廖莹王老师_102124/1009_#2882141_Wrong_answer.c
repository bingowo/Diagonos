#include <stdio.h>
#include <stdlib.h>
int GCD(int m,int n)
{
    if(n<=m && m%n==0)
        return n;
    else if(n>m)
        return GCD(n,m);
    else return GCD(n,m%n);
}
void hp()
{
    char s[125];

    int  a[125];
    int i=0,k,number1=0,number0=0,d,g;
    scanf("%s",s);
   for(i=0;s[i];i++)
    a[i]=s[i];
    for(i=0;s[i];i++)
   {
       d=1;
       for(k=0;k<8;k++)
       {
           if(a[i]&d){d=d<<1;number1=number1+1;}
        else{d=d<<1;number0=number0+1;}
       }

   }
   g=GCD(number0,number1);
   printf("%d/%d\n",number1/g,(number0+number1)/g);
    return 0;
}
int main()
{
    int i,n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        hp();
    return 0;
}

