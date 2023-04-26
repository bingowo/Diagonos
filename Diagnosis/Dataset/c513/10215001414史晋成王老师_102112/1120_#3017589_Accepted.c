#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{ int T,i,j,n,m1,m2,r,c,k,x[20],y[20],f1,f2,count,ans,l1,l2;
  scanf("%d",&T);
  for(i=0;i<T;i++)
  { scanf("%d %d %d %d\n",&r,&c,&n,&k);
     for(j=0;j<n;j++)
     scanf("%d %d\n",&x[j],&y[j]);
     ans=0;
     for(f1=0;f1<r;f1++)
       { for(f2=0;f2<c;f2++)
          for(l1=1;l1<=r-f1;l1++)
            for(l2=1;l2<=c-f2;l2++)
          {  count=0;
             for(m1=l1;m1<=l1+f1;m1++)
              { for(m2=l2;m2<=l2+f2;m2++)
                  { for(j=0;j<n;j++)
                      {if(m1==x[j]&&m2==y[j]) count++;}
                  }
              }
              if(count==k||count>k)  ans++;
          }
           
       }
       printf("case #%d:\n",i);
       printf("%d\n",ans);
       memset(x,0,sizeof(x));
       memset(y,0,sizeof(y));
  }
    
}