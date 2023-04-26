#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
int main()
{
    unsigned long long num;int res=0;
    while(scanf("%llu",&num)){
        if(num==0)break;
        double a,c;
        a=num*log10(num);
        int b=(int)a;
        c=a-b;
        int d=pow(10,c);
        printf("%d\n",d);
    }
}
