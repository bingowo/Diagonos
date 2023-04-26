#include <stdio.h>
#include <stdlib.h>

int main()
{int n;
int t;
scanf("%d %d",&n,&t);
if(n==0) printf("0");else{
int rem,quo;
int k=0;
int a[999]={0};
while(n!=0){
rem=n%t;
quo=n/t;
if(rem<0){
rem=rem-t;
quo++;
}
a[k]=rem;
k++;
n=quo;
}
int j;
for( j=998;j>=0;j--){
if(a[j]!=0)  break;

}
for(;j>=0;j--){
if(a[j]<=9){
printf("%d",a[j]);
}
else printf("%c",a[j]-10+'A');


}
}
return 0;
}
