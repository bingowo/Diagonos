#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int gcd(int a, int b)
{
    return a ? gcd(b % a, a) : b;
}
int main()
{int n=0;
scanf("%d",&n);
char c;
c=getchar();
for(int i=0;i<n;i++){
char a[121]={0};
fgets(a,120,stdin);
int flag=0;
int sum=0;
int j;
for( j=0;j<121;j++){
if(a[j]=='\n'){
flag=1;
break;
}else if(a[j]==0) break;
else{
unsigned char t=(unsigned char)a[j];
for(int m=0;m<8;m++){
sum=sum+t%2;
t=t>>1;

}
}
}
int g= gcd(sum,j*8);
printf("%d/%d\n",sum/g,(j*8)/g);
}





return 0;
}
