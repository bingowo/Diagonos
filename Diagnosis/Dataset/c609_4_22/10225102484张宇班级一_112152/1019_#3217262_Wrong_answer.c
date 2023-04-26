#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
int i=0;
while(scanf("%d",&n)!=EOF){
    a[i++]=n;
}
qsort(a,i,sizeof(a[0]),cmp);
for(int j=0;j<i;j++)
printf("%d ",a[j]);
return 0;
}