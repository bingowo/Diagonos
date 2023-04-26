#include <stdio.h>
#include <stdlib.h>

int cmp1(const void*a , const void* b){
    return *(int*)a-*(int*)b;
}

int cmp2(const void*a , const void* b){
    return *(int*)b-*(int*)a;
}

int main()
{   char s;
    scanf("%s",&s);
   int a[101],n=0,i,t,j;
   while(scanf("%d",&a[n++])!=EOF);
   if (s=='A') qsort(a,n-1,sizeof(int),cmp1);
   if(s=='D') qsort(a,n-1,sizeof(int),cmp2);
   for(int i=0;i<n-1;i++){
    if(i+1<=n && a[i]==a[i+1])
        continue;
    printf("%d ",a[i]);
   }
    return 0;
}
