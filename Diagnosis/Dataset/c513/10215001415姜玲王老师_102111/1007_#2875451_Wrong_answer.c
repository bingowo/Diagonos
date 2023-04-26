#include <stdio.h>
#include <stdlib.h>

int answer( )
{int p,j,l,max,temp;
scanf("%d",&p);
int two[33];
while(p)
{j=0;
two[j]=p%2;
p=p/2;
j++;}
max=1;
for(l=0;l<j-2;l++)
{temp=1;
while(two[l]!=two[l+1])
{temp++;l++;}
if(max<temp) max=temp;
}
return max;
}
int main()
{int n,i;
scanf("%d",&n);
for(i=0;i<n;i++)
{printf("case #%d:\n",i);
printf("%d\n",answer());
}
}




