#include <stdio.h>
#include <stdlib.h>
int cmp2(int a){
    int k;
    if(a<0)a=-a;
    for(k=1;a>0;)
    {
       a=a/10;
       k++;
    }
    return k;
}
int cmp(const void*a,const void*b)
{
   int n1=*(int*)a;int n2=*(int*)b;
   if(cmp2(n1)>cmp2(n2))return -1;
   else if(cmp2(n1)<cmp2(n2))return 1;
   else if(cmp2(n1)==cmp2(n2))return n2-n1;
}
int main(){
int a[100];
int n;
for(int i=0;i<100&&scanf("%d",&n)!=EOF;i++){
    a[i]=n;
}
int leng=sizeof(a)/sizeof(a[0]);
qsort(a,leng,sizeof(a[0]),cmp);
for(int j=0;j<leng;j++)
printf("%d ",a[j]);
}