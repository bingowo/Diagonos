#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b )
{return *(int*)b-*(int*)a;}
int main()
{int B[1000],i=0,p=10,A[1000],u=0;
while(scanf("%d",&B[i])!=EOF){i++;}
qsort(B,i,4,cmp);
for(int j=1;j<=9;j++)
{for(int t=0;t<=i-1;t++)
  {if(B[t]/p==0&&(B[t]/(p/10))!=0){A[u]=B[t];u++;}  }
   p*=10;
}

for(int j=u-1;j>=0;j--)
{printf("%d ",A[j]);

}
return 0;
}
