#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b)
{ return a?gcd(b%a,a):b;
    
}

int main()
{ int n,i,size_,j,c=0,d; char s[120];
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {scanf("%s",s);
   size_=sizeof(s); int b=size_-1;
   for(j=0;j<b;j++)
   { unsigned char p=s[b];
     c+=p%2;
     p=p/2;
       
   }
   d=gcd(c,size_*8);
   printf("%d/%d",d,d/c*8*size_);
}
return 0;