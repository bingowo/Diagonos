#include <stdio.h>
#include<string.h>
#include<math.h>
int main() {
    int a,b,x,i,n,j;
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
            for(j=0;j<8;j++)a+=(c&(1<<j))>>j;
        }
        for(n=2;n<=a;n++)if(!(a%n)&&!(b%n)){a/=n;b/=n;n=1;}
    printf("%d/%d\n",a,b);
    }
    return 0;
}
