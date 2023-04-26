#include <stdio.h>
#include <stdlib.h>

int main()
{int total,i,n,m,add,answer;
scanf("%d",&total);
for(i=0;i<total;i++)
{answer=0;
scanf("%d %d",&n,&m);
add=n^m;
while(add)
{if(add%2) answer++;
add/=2;
}
printf("%d\n",answer);}
}
