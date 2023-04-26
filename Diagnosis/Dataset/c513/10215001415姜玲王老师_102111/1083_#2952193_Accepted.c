#include <stdio.h>
#include <stdlib.h>

int main()
{int n;
scanf("%d",&n);
for(int i=0;i<n;i++)
{printf("case #%d:\n",i);
int k;
scanf("%d",&k);
int sum=0;
while(k)
{sum+=k/5;
k/=5;
}
printf("%d\n",sum);}
}
