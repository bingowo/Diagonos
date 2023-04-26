#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
long long int solve (long long int n)
{ long long int x,y,i,j;
while(n!=0)
{ x=n%10;
 if(x==9) { return -1;}
 n=n/10;
}
return 1;
}
int main()
{ long long int a,b,i,j,x,y;
scanf("%lld %lld",&a,&b);
    x=0;
    for(i=a;i<=b;i++)
    { if (i%9==0||solve(i)==-1) {continue;}
        else x++;
    }
    printf("%lld",x);
}