#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a,int b)
{
    if(a%b)
        return gcd(b,a%b);
    return b;
}
int cnt(int x){
   int i=0,j=0;
   while(x>0){
      j=x%2;
      x=x/2;
      if(j==1)
      i++;
   }return i;
}
int main()
{
    int n,c,a,b,m;
    char s[120];
    scanf("%d\n",&n);
    for(;n>0;n--){
       scanf("%s\n",s);
       c=sizeof(s);
	   m=8*(sizeof(s)-1);
       int num=0;
       for(int i=0;i<c;i++){
       num+=cnt(atoi(s[i]));}
         a=num/gcd(num,m);
         b=num/gcd(num,m);
         printf("%d/%d",a,b);
       }return 0;
    }
