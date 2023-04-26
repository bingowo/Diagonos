#include <stdio.h>
#include <stdlib.h>
int p = 0,num;
int res(int a,int b)
{
    int n,m;
    n = a>b?a:b;
    m = a>b?b:a;
    if(m==0) return a;
    else return res(m,n%m);
}
void answer(int m,int *a)
{
    p++;
    int n = a[p]-a[p-1];
    if(p==num||m<p*n) {
        printf("%d",a[p-1]+m/p);
        if(m%p!=0)
        {
            int A = res(m,p);
            printf("+%d/%d",(m%p)/A,p/A);
        }}
    else {a[p-1] = a[p];return answer(m-p*n,a);}
}
int cmp(const void *a,const void*b)
{
    return (*(int *)a)-(*(int*)b);
}
int main()
{
   int n,i,s;
   scanf("%d %d",&n,&s);
   num = n;
   int a[n];
   for(i = 0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    answer(s,a);
    return 0;
}
