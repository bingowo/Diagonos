#include<stdio.h>
#include<stdlib.h>
int gcd(int a,int b)
{ return a?gcd(b%a,a):b;
    
}

int main()
{ int n,i,size_,j,c,d; char s[120]; unsigned char p;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {scanf("%s",s);
   size_=sizeof(s); int b=size_-1; c=0;
   for(j=0;j<b;j++)
   { p=s[b];
   for(int m=0;m<8;m++)
     {
     c+=p%2;
     p/=2;}
       
   }
  d=gcd(c,size_*8);
   printf("%d/%d\n",c,d);
}
return 0;}