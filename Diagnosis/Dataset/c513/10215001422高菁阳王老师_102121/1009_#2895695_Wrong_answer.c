#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int GCD(int a,int b)
{
    if(a%b==0) return b;
   else return GCD(a,a%b);
}

int main()
{
    int n,c,a,b,m=0,num=0,i,j;
    char s[1000];
    scanf("%d\n",&n);
    for(;n>0;n--){
       gets(s);
       c=strlen(s);
	   for(i=0;i<c;i++){
	   int d=1;
	   m=m+8;
	  for(j=0;j<8;j++){
	   	if(s[i]>>j&1==1) num++;
	  }	   
}
         a=num/GCD(num,m);
         b=m/GCD(num,m);
         printf("%d/%d\n",a,b);
       }return 0;
    }