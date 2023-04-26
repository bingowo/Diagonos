#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a>*(int *)b?1:-1;
}
int main()
{
    int n,s;scanf("%d %d",&n,&s);
    int a[n+1];
    for(int i=0;i<n;scanf("%d",&a[i++]));
    for(int m=s;m>0;m--){
        qsort(a,n,sizeof(int),cmp);
        a[0]++;
    }
    
    return 0;
}
