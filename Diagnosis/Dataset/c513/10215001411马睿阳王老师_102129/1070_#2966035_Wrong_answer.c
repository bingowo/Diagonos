#include<stdio.h>
int main()
{int d00[21],d01[21],d1[21],i,v,n;
 d01[2]=1,d00[2]=1,d1[2]=2,d00[1]=0,d01[1]=0,d1[1]=1;
 for(i=3;i<=20;i++)
 {d00[i]=d01[i-1]+d00[i-1];
  d01[i]=d1[i-1];
  d1[i]=d00[i-1]+d1[i-1];
 }
 while(1)
 {scanf("%d",&n);
 if(n==-1) break;
  v=d00[n]+d01[n]+d1[n];
  printf("%d\n",v);
 }
 return 0;
}