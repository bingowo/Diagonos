#include <stdio.h>
#include <stdlib.h>

int main()
{int n=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
int a[33]={0}  ;
int x=0;
scanf("%d",&x);
int k=0;
while(x/2>0){
a[k]=x%2;
k++;
x=x/2;
}
a[k]=x;
int j;
for( j=33;j>=0;j--){
if(a[j]!=0) break;
}
int sum=1;
for(;j>=0;j--){
int n1=1;
int l=j;
for(;l>0;l--){
if(a[l]!=a[l-1]) n1++;
else break;
}
if(n1>sum) sum=n1;
}
printf("case #%d:\n%d\n",i,sum);

}

return 0;
}
