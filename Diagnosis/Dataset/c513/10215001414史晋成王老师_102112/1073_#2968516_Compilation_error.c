#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int solve (int n)
{ int x,y,i,j;
while(n!=0)
{ x=n%10;
 if(x==9) {break; return 1;}
 n=n/10
}
return 1;
}
int main()
{ int a,b,i,j,x,y;
scanf("%d %d",&a,&b);
    x=0;
    for(i=a;i<=b;i++)
    { if (i%9==0||solve(i)==1) {continue;}
        else x++
    }
    printf("%d",x);
}