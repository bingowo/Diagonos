#include<stdio.h>
#include<stdlib.h>
int cmp(const void*a,const void*b)
{ int *x,*y; int i=0;
    x=(int*)a;
    y=(int*)b;
    while(x[i]&&y[i])
    { if(x[i]==y[i]) i++
      else return y[i]-x[i];    }
}
int main()
{int T,N,i,j,a[1001][51],k,x,y;
scanf("%d",&T);
for(i=0;i<T;i++)
{ scanf("%d",&N);
  for(j=0;j<N;j++)
  {   k=0;
      while(scanf("%d",&a[j][k]))
      { if(a[j][k]==-1) break;
          k++;
      }
  }
  qsort(a,N,sizeof(a[0]),cmp);
  for(x=0;x<N;x++)
  { y=0;
  while(a[x][y]!=-1)
  {printf("%d ",a[x][y]); y++;
      }
      printf("\n");
}
    
}
}