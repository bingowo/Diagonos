#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{int n=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
char c;
c=getchar();
char a[121]={0};
fgets(a,120,stdin) ;
int sum=0;

for(int j=0;j<121;j++){
if(a[j]==0)  break;
else{
 char t=a[j];
 while(t>0){
 if(t%2==1) sum++;
 t=t/2;
 }
}}
int l= strlen(a)*8;
int m=0,n=0;
m=sum;
n=l;
while(m%n!=0){
int o=0;
o=m%n;
m=n;
n=o;

}
printf("%d/%d\n",sum/n,l/n);

}





return 0;
}
