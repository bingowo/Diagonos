#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int ishw(int x)
{ int a[100],i,j,flag=1;;
i=0;j=0;
while(x)
{ a[i]=x%10;
  x=x/10;
  i++;
}
for(j=0;j<i/2;j++)
{ if(a[j]!=a[i-1-j]) flag=0;
}
return flag;
}

int gethw(int x)
{ int a[100],y,i,j;
i=0;j=0;y=0;
 while (x)
 { a[i]=x%10;
 x=x/10;
 i++;
 }
 for(j=0;j<i;j++)
 { y=y*10+a[j];
 }
 return y;
}

int main()
{ int n,a[1000],m,i,j;
 scanf("%d",&n);
 i=0;
 while(ishw(n)!=1)
 { n=n+gethw(n);
  i++;
 }
 printf("%d %d",i,n);
    
}