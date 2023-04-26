#include <stdio.h>
int main()
{int a,i,p,P,t;
char A[100];
scanf("%d\n",&a);
for(i=0;i<a;i++)
{p=0,P=0,t=1;
 fgets(A,100,stdin);
while(A[p]!='\n'){p++;}
p=p-1;
for(int u=p;u>=0;u--)
{  if(A[u]=='-'){P+=(A[u]-46)*t;}
   else {P+=(A[u]-48)*t;}
    t*=3;
}
printf("case #%d:\n%d\n",i,P);
}


return 0;
}
