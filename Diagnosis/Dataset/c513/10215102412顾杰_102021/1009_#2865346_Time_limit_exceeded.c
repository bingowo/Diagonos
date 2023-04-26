#include <stdio.h>
#include<string.h>
#include<math.h>
int main() {
    int a,b,x,i,n;
    char c;
    scanf("%d",&x);
    getchar();
    for(i=0;i<x;i++)
    {
        a=0;b=0;
        while((c=getchar())!=-1)
        {
            if(c=='\n')break;
            b+=8;
            while(c)
            {
                a+=c&1;
                c>>=1;
            }
        }
        n=2;
        while(n<=a)
        {
            if(!(a%n)&&!(b%n)){a/=n;b/=n;n=1;}
            n++;
        }
    printf("%d/%d\n",a,b);
    }
    return 0;
}
