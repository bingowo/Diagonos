#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a,int b)
{
    if(a%b)
        return gcd(b,a%b);
    return b;
}

int main()
{
    int n,c,a,b,m,num,i;
    char s[120];
    scanf("%d\n",&n);
    for(;n>0;n--){
       gets(s);
       c=sizeof(s);
	   m=8*(sizeof(s)-1);
       for(i=0;i<c-1;i++){
	   int d=1;
	   for(int j=0;j<8;j++){
	   	if(d&s[i]) num++;
	   	d=d<<1;
	   }
}
         a=num/gcd(num,m);
         b=num/gcd(num,m);
         printf("%d/%d",a,b);
       }return 0;
    }
