#include<stdio.h>
int main()
{int n,m,i,A[100]={0},B[3],j,C[100]={0},F[100]={0},v,p,k;
while(scanf("%d %d\n",&n,&m))
{if(m==0&&n==0){break;}
int D[n];
for(i=0;i<=n-1;i++)
{D[i]=i;}

for(i=0;i<=m-1;i++)
{for(j=0;j<=2;j++)
{scanf("%d",&B[j]);}
if(B[2]==1){A[B[0]-1]+=3;A[B[1]-1]-=1;C[B[0]-1]+=1;F[B[1]-1]+=1;}
else if(B[2]==-1){A[B[1]-1]+=3;A[B[0]-1]-=1;C[B[1]-1]+=1;F[B[0]-1]+=1;}
else{A[B[0]-1]+=1;A[B[1]-1]+=1;}
}

for(v=0;v<=n-1;v++)
{for(p=0;p<=n-2;p++)
    {if(A[p]<A[p+1])
        {k=A[p];A[p]=A[p+1];A[p+1]=k;
      k=C[p];C[p]=C[p+1];C[p+1]=k;
      k=F[p];F[p]=F[p+1];F[p+1]=k;
      k=D[p];D[p]=D[p+1];D[p+1]=k;
        }
      else if(A[p]==A[p+1]&&C[p]<C[p+1])
      {k=A[p];A[p]=A[p+1];A[p+1]=k;
      k=C[p];C[p]=C[p+1];C[p+1]=k;
      k=F[p];F[p]=F[p+1];F[p+1]=k;
      k=D[p];D[p]=D[p+1];D[p+1]=k;

      }
      else if(A[p]==A[p+1]&&C[p]==C[p+1]&&F[p]>F[p+1])
      {k=A[p];A[p]=A[p+1];A[p+1]=k;
      k=C[p];C[p]=C[p+1];C[p+1]=k;
      k=F[p];F[p]=F[p+1];F[p+1]=k;
      k=D[p];D[p]=D[p+1];D[p+1]=k;

      }
      else  if(A[p]==A[p+1]&&C[p]==C[p+1]&&F[p]==F[p+1]&&D[p]>D[p+1])
       {k=A[p];A[p]=A[p+1];A[p+1]=k;
      k=C[p];C[p]=C[p+1];C[p+1]=k;
      k=F[p];F[p]=F[p+1];F[p+1]=k;
      k=D[p];D[p]=D[p+1];D[p+1]=k;

        }

      }
}

for(i=0;i<=n-2;i++)
{printf("%d ",D[i]+1);}
printf("%d\n",D[i]+1);


}
return 0;
}
