#include <stdio.h>
#include <stdlib.h>

int main()
{long long n=0;
scanf("%lld",&n);
for(long long i=0;i<n;i++){
long long a;
scanf("%lld",&a);
int b[50]={0};
int k=0;
while(a/2333>0){
b[k]=a%2333;
k++;
a=a/2333;
}
b[k]=a;
if(a==0){
    printf("%lld\n",a);
    continue;
}
int j;
for( j=49;j>=0;j--)  {
if(b[j]!=0) break;
}

for(;j>=0;j--){
printf("%d ",b[j]);

}
printf("\n")  ;

}
return 0;
}