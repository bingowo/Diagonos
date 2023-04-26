#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 32
char binary(int n,int r)
{   char b[MAX];
    int p,m;
    if(r<=10){for(p=0;n/r!=0;p++)
        {b[p]=n%r-'0';n=n/r;}//不要忘了字符串最后还有一个0
    b[p]=n-'0';}
    else{for(p=0;n/r!=0;p++)
        {   m=n%r;
            if (m<10){b[p]=m-'0';}
        else {b[p]=m-10+'a';}
        n=n/r;}
    b[++p]='\0';
    return b;
   // for (;p>=0;p--){printf("%c",b[p]);}
}

int main()
{   int t,i;
    char c[MAX];
    scanf("%d",&t);//会有负数的情况。
    int a[2*t];
    for(i=0;scanf("%d",&a[i])==1&&i<=2*t;i++);
    for (i=0;i<2*t;i++)
    {strcpy(c,binary(a[i],a[++i]));
     for (;p>=0;p--){printf("%c",c[p]);}}
    return 0;
}

