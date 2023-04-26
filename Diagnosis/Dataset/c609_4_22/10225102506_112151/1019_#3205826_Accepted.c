#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a,const void *b){
    int cnt1=1,cnt2=1;
    int x,y;
    x=*(int *)a;
    y=*(int *)b;
    while(x/=10)
        cnt1++;
    while(y/=10)
        cnt2++;
    if(cnt1!=cnt2)
        return cnt2-cnt1;
    else
        return *(int *)a-*(int *)b;
}

int main()
{
    int a[1000000];
    int i=0;
    while(scanf("%d",&a[i])!=EOF)
        i++;
    qsort(a,i,sizeof(int),cmp);
    for(int j=0;j<i;j++)
        printf("%d ",a[j]);
    return 0;
}
