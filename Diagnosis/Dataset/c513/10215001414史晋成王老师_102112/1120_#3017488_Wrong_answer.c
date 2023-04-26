#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int T,i,j,n,m1,m2,r,c,k,x[20],y[20],f1,f2,count,ans;
  scanf("%d",&T);
  for(i=0;i<T;i++)
  { scanf("%d %d %d %d\n",&r,&c,&n,&k);
     for(j=0;j<n;j++)
     scanf("%d %d\n",&x[j],&y[j]);
     ans=0;
     for(f1=1;f1<=r;f1++)
       { for(f2=1;f2<=c;f2++)
          {  count=0;
             for(m1=1;m1<=f1;m1++)
              { for(m2=1;m2<=f2;m2++)
                  { for(j=0;j<n;j++)
                      if(m1==x[j]&&m2==y[j]) count++;
                  }
              }
              if(count==k)  ans++;
          }
           
       }
       printf("case #%d:\n",i);
       printf("%d\n",ans);
  }
    
}