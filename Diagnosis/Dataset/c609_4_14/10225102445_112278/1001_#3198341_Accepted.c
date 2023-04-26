#include<stdio.h>
int main()
{int T,N,R,m,p,g;
char A[36]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int B[100];
scanf("%d",&T);
for(p=0;p<T;p++)
{scanf("%d %d",&N,&R);

  if(N>=0)
 {g=0;while((N/R!=0&&N%R==0)||(N/R==0&&N%R!=0)||(N/R!=0&&N%R!=0))
   {m=N%R;
    N=N/R;
    B[g]=m;
    g++;
    }
 for(int i=g-1;i>=0;i--)
 {printf("%c",A[B[i]]);}
printf("\n");
 }

 else
{N=-N;
 printf("%c",'-');
  g=0; while((N/R!=0&&N%R==0)||(N/R==0&&N%R!=0)||(N/R!=0&&N%R!=0))
   {m=N%R;
    N=N/R;
    B[g]=m;
    g++;
   }
for(int i=g-1;i>=0;i--)
 {printf("%c",A[B[i]]);}
printf("\n");
}

}
return 0;
}
