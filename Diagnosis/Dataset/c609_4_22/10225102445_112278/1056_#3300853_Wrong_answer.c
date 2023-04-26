#include<stdio.h>
long long int p(int m,int n)
{long long int k=1,u=1;
int i,j;
if(m<2*n)
{j=1;for(i=n+1;i<=m;i++){k=i*k/j;}}
else
{
j=1;for(i=m-n+1;i<=m;i++){k=i*k/j;j++;}

}
return k;
}
int main()
{int m,n,i;
long long int e;
scanf("%d",&i);
for(int v=0;v<i;v++)
{scanf("%d %d",&m,&n);
e=p(m,n);
  printf("case #%d:\n",v);
  printf("%I64d\n",e);
}

}
