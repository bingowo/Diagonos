#include<stdio.h>
int main()
{int T,N,i,j,k,l,e,t;
 int s[1000]={0};
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {scanf("%d",&N);
  if(N==0)  {printf("case #%d:\n",i);printf("1\n");}
  else
  {s[0]=1;
  for(t=0,k=0;t<N;t++)
  {
    for(j=0;j<=k;j++)
   {s[j]*=2;}
   for(j=0;j<=k;j++)
      {if(s[j]>=10)
          {s[j+1]+=s[j]/10;
           s[j]%=10;
           if(j==k) k++;
          }

      }
  }
   if(s[k]==0) k--;
   for(l=0;l<=k/2;l++)
       {e=s[l];s[l]=s[k-l];s[k-l]=e;}
   printf("case #%d:\n",i);
   for(l=0;l<=k;l++)
    printf("%d",s[l]);
    printf("\n");
   for(l=0;l<=k;l++)
    s[l]=0;
  }
 }
return 0;
}
