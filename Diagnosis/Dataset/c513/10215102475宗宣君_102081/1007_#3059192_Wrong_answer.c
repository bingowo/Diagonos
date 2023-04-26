#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    int A = *(int *)a,B = *(int*)b;
    if(A<B) return 1;
    else return -1;
}
int main()
{
    int T,i;
    scanf("%d",&T);
    for(i = 0;i<T;i++)
    {
        int n,a[32],num[100]={1},j = 0,k = 0;
        scanf("%d",&n);
        do{
            a[j++] = n%2;
            n/=2;
            if(j!=1)
            {if(a[j-1]!=a[j-2]) num[k]++;
            else {k++;num[k] = 1;}}
        }while(n!=0);
        qsort(num,k,sizeof(int),cmp);
        printf("case #%d:\n%d\n",i,num[0]);
    }
    return 0;
}
