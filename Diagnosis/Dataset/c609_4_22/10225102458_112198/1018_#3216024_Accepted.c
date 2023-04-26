#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void* b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb)return -1;
    else return 1;
}
int main()
{
    int n,max=0;
    scanf("%d",&n);
    int s[n];
    for(int i=0;i<n;i++)scanf("%d",s+i);
    qsort(s,n,sizeof(int),cmp);
    for(int i=0;i<n-1;i+=2){
        max+=s[i]-s[i+1];
    }
    printf("%d\n",max);

    return 0;
}
