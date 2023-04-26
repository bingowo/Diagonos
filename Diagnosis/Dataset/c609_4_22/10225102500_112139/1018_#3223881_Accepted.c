#include <stdio.h>
#include <stdlib.h>
int cmp(const void*e1,const void* e2){
int n1,n2;
n1=*(int*)e1;
n2=*(int*)e2;
if(n1>n2) return 1;
else if(n1<n2) return -1;
else return 0;

}
int main()
{int n;
scanf("%d",&n);
int*a=(int*)malloc(n*sizeof(int));
for(int j=0;j<n;j++){
scanf("%d",&a[j]);
}
qsort(a,n,sizeof(a[0]),cmp);
long long sum=0;
for(int j=0;j<n;j=j+2){
sum=sum+a[j+1]-a[j] ;
}
printf("%lld",sum);
free(a);
return 0;
}
