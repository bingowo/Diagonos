#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a,int b)
{ return a?gcd(b%a,a):b;
    
}

int main()
{ int n,i,size_,j,c,d,b,k; char s[130]; unsigned char p;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {scanf("%s",s);
   b=0; if(s[k]!='\0') b++;
   c=0;
   for(j=0;j<b;j++)
   { p=s[j];
   for(int m=0;m<8;m++)
     {
     c+=p%2;
     p>>=1;}
       
   }
   d=gcd(c,b*8);
   printf("%d/%d\n",c/d,b*8/d);
}
return 0;}