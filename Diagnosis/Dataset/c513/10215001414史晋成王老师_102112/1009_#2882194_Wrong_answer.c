#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int gcd(int a,int b)
{ return a?gcd(b%a,a):b;
    
}

int main()
{ int n,i,size_,j,c,d; char s[130]; unsigned char p;
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {scanf("%s",s);
   int b=strlen(s); c=0;
   for(j=0;j<b;j++)
   { p=s[j];
   for(int m=0;m<8;m++)
     {
     c+=p%2;
     p>>=1;}
       
   }
   printf("%d/%d\n",c,c);
}
return 0;}