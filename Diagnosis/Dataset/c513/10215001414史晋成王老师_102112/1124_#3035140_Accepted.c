#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ans(int a,int b)
{ int max,min;
  if(a>b) {max=a;min=b;} else {max=b;min=a;}
  if(max%min==0) return min;
  else return ans(max%min,min);
}

int main()
{ int T,f,i,j,n,m,s,a[1200],b[1200],k,count,flag;
  scanf("%d",&T);
  for(i=0;i<T;i++)
  { scanf("%d\n",&n);
    count=0;
    for(j=0;j<n;j++)
    { scanf("%d\n",&a[j]);
    }
    f=0;
    for(j=0;j<n;j++)
    { flag=1;
      for(k=j+1;k<n;k++)
      {if(a[j]==a[k]) {flag=0;break;}}
      if(flag==1) {b[f]=a[j];f++;}
    }
    for(j=0;j<f;j++)
     { for(k=j+1;k<f;k++)
         if(ans(b[j],b[k])==1) count++;
     }
     printf("case #%d:\n",i);
     printf("%d\n",count);
  }
    
}