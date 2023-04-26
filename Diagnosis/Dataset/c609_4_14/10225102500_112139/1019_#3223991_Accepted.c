#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp(const void*e1,const void* e2){
int n1,n2;
n1=*(int*)e1;
n2=*(int*)e2;
int n3,n4;
n3=fabs(n1);
n4=fabs(n2);
int num1=0,num2=0;
while(n3>0){
n3=n3/10;
num1++;
}
while(n4>0){
n4=n4/10;
num2++;
}
if(num1!=num2) return num2-num1;
else if(n1>n2) return 1;
else if(n2>n1) return -1;
else return 0;
}
int main()
{int a[1000000];
int t=0;
while(scanf("%d",&a[t])!=EOF){
t++;
}
qsort(a,t,sizeof(a[0]),cmp);
for(int j=0;j<t;j++){
printf("%d ",a[j]);
}
return 0;
}
