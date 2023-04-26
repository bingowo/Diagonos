#include<stdio.h>
typedef struct
{int val;
 char dir;
} Elem;

void shortpath(Elem A[205][205],int M,int N)//最短路径长度以及方向
{int i,j;
 if(j==0)
 {for(i=1;i<M;i++)
  {A[i][0].val+=A[i-1][0].val;
   A[i][0].dir='D';
  }
 }
 else if(i==0)
 {for(j=1;j<N;j++)
  {A[0][j].val+=A[0][j-1].val;
   A[0][j].dir='R';
  }
 }
 else
 {for(i=1;i<M;i++)
  {for(j=1;j<N;j++)
   {if(A[i-1][j].val<A[i][j-1].val)
    {A[i][j].val+=A[i-1][j].val;
     A[i][j].dir='D';
    }
    else
    {A[i][j].val+=A[i][j-1].val;
     A[i][j].dir='R';
    }
   }
  }
 }
}

void outpath(Elem A[205][205],int M,int N,int r,int c)//递归输出到A【r】【c】的最短路径
{if(r==0&&c==0) return ;
 if(A[r][c].dir=='D')
 {outpath(A,M,N,r-1,c);
  putchar('D');
 }
 else
 {outpath(A,M,N,r,c-1);
  putchar('R');
 }
}

int main()
{int M,N,r,c;
 Elem A[205][205];
 int i=0,j=0;
 scanf("%d %d",&M,&N);
 for(i=0;i<M;i++)
 {for(j=0;j<N;j++)
  {scanf("%d",&A[i][j]);
   A[i][j].dir=0;
  }
 }
 shortpath(A,M,N);
 printf("%d\n",A[M-1][N-1].val);
 outpath(A,M,N,M-1,N-1);
 putchar('\n');
 return 0;
}
