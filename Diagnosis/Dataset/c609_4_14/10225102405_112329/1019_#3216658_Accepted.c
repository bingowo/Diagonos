#include<stdio.h>
#include<stdlib.h>
int cmp(const void *_a,const void *_b)
{
    int a=*(int*)_a;
    int b=*(int*)_b;
    int cnt1=0,cnt2=0;
    while(a){
        cnt1++;
        a/=10;
    }
    while(b){
        cnt2++;
        b/=10;
    }
    if (cnt1>cnt2) return -1;
    else if(cnt1<cnt2) return 1;
    return *(int*)_a-*(int*)_b;
}
int main()
{
    int i=0,a[1000000],j;
    while(scanf("%d",&a[i])!=EOF){
            i++;
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(j=0;j<i;j++){
        printf("%d ",a[j]);
    }
    return 0;
}
