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
    char s[1000];
    scanf("%d\n",&n);
    for(;n>0;n--){
       gets(s);
       c=strlen(s);
	   for(i=0;i<c;i++){
	   int d=1;
	   n=m+8;
	   for(int j=0;j<8;j++){
	   	if(d&s[i]) num++;
	   	d=d<<1;
	   }
}
         a=num/gcd(num,m);
         b=m/gcd(num,m);
         printf("%d/%d\n",a,b);
       }return 0;
    }
