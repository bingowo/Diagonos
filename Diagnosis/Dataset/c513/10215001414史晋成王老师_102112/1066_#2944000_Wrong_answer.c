#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int count,n,t;
void level(int p, int m)
{ if(m==0)
{ if (p==t) 
  count++; 
return;
}
  else if (m>0)
  { if (p==1)  level(2,m-1);
    else if (p==n) level(n-1,m-1);
    else if(p<n&&p>1)
    { level(p-1,m-1);
      level(p+1,m-1);
    }
  }
}
int main()
{ int cas,n,p,m,t,i,j;
scanf("%d",&cas);
for(i=0;i<cas;i++)
{ scanf("%d %d %d %d",&n,&p,&m,&t);
  count=0;
  level(p,m);
  printf("%d\n",count);
}
    
}
