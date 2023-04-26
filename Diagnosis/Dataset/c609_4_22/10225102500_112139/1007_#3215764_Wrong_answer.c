#include <stdio.h>
#include <stdlib.h>
int cmp(const void* sb1,const void *sb2){
long long m,n;
m=*(long long *)sb1;
n=*(long long *)sb2;
unsigned long long m1,n1;
m1=(unsigned long long)m;
n1=(unsigned long long)n;
int sum1=0;
int sum2=0;
while(m1!=0){
if(m1%2==1) sum1++;
m1=m1/2;
}
while(n1!=0){
if(n1%2==1) sum2++;
n1=n1/2;
}
if(sum1>sum2) return -1;
else if(sum1<sum2) return 1;
else if(m>n) return 1;
else if(m<n) return -1;
else return 0;
}

int main()
{int n=0;
scanf("%d",&n);
for(int i=0;i<n;i++){
int t=0;
scanf("%d",&t);
long long* a=(long long *)malloc(t*sizeof(long long));
for(int j=0;j<t;j++){
scanf("%lld",&a[j]);
}
qsort(a,t,sizeof(long long),cmp);
for(int k=0;k<t;k++){
if(k!=t-1) printf("%lld ",a[k]);
else printf("%lld \n",a[k]);
}
}
return 0;
}
