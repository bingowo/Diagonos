#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int a,int b)
{
    if(a%b==0) return b;
   else return GCD(b,a%b);
}

int main()
{
    int n,c,a,b,m=0,num=0,i,j,ma;
    char s[1000];
    scanf("%d\n",&n);
    for(;n>0;n--){
       gets(s);
       c=strlen(s);
       m=c*8;
	   for(i=0;i<c;i++){
	       ma=s[i];
	  for(j=0;j<8;j++){
	   	if((ma>>j)&1==1) num++;
	  }	   }

         a=num/GCD(m,num);
         b=m/GCD(m,num);
         
         printf("%d/%d\n",a,b);}
       return 0;}
