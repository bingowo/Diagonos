#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b )
{return *(int*)a-*(int*)b;}
int main()
{int a,n=0,A[100000],k=0,m;
scanf("%d\n",&a);
while(scanf("%d",&A[n])!=-1){n++;}
qsort(A,n,4,cmp);
for(int i=0;i<=n-2;i=i+2)
{m=A[i]-A[i+1];
 if(m<0){m=-m;}
 k+=m;
}
printf("%d",k);
return 0;
}
