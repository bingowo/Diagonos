#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define M 32


int main()
{   int t,i,p,m,n,r;
    char c[M];
    scanf("%d",&t);//会有负数的情况。
    int a[2*t];
    for(i=0;scanf("%d",&a[i])==1&&i<=2*t;i++);
    for (i=0;i<2*t;i++)
    {   n=a[i];r=a[++i];
        if(r<=10)
        {for(p=0;n/r!=0;p++){c[p]=n%r-'0';n=n/r;}
            c[p]=n-'0';}
    else{for(p=0;n/r!=0;p++)
        {   m=n%r;
            if (m<10){c[p]=m-'0';}
            else {c[p]=m-10+'A';}
            n=n/r;
        }
     for (;p>=0;p--){printf("%c",c[p]);}}
    return 0;
}}
