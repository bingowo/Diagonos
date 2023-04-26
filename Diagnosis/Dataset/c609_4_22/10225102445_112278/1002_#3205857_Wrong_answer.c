#include <stdio.h>
int M(int A,int B[],int i)
{int c=1,t=0;
    while(A!=0)
   {B[i]=A%2;
    A/=2;
    i++;}
for(int e=0;e<=i-1;e++)
{if(B[e]==B[e+1]){if(c>t)t=c;c=1;}
else c++;
}
if(c>t)t=c-1;

return t;
}
int main()
{int a,m,b[100],p;
scanf("%d",&a);
for(m=1;m<=a;m++)
{scanf("%d",&p);
 printf("case #%d:",m);
 printf("\n");
printf("%d",M(p,b,0));
}
return 0;
}
