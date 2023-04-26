#include<stdio.h>
long long int p(int n)
{
if(n==1) return 1;
else if(n==2)return 2;
else if(n==3)  return 4;
else if(n==4) return 8;
else return p(n-1)+p(n-2)+p(n-3)+p(n-4);

}
int main()
{int i,v,n;
long long int k;
scanf("%d",&i);
    for(v=0;v<i;v++)
    {scanf("%d",&n);
    k=p(n);
      printf("case #%d:\n",v);
      printf("%lld\n",k);
    }

}
