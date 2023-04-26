#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned long long int f(int n)
{ if(n==0||n==1) return 1;
   else     return n*f(n-1);
}
unsigned long long int g(int x,int y)
{ if(x==y) return y;
  else return x*g(x-1,y);
}
int main()
{ int t,i,j,n,s,k,m,small,large;
unsigned long long int ans;
scanf("%d",&t);
for(i=0;i<t;i++)
{ scanf("%d %d",&m,&n);
  if(m>2*n) {large=m-n;small=n;}
  else {large=n;small=m-n;}
  printf("case #%d:\n",i);
  if(n==0) printf("1\n");
  else
  { ans=1;
      for(j=m;j>large;j--)
  { if(j==small*2)
      {ans=ans*2;small--;}
      else ans=ans*j;
  }
  while(small>1)
  { ans=ans/small;
      small--;
  }
    printf("%llu\n",ans);  
  }
}
    
}