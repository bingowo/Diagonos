#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void* b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb)return 1;
    else return -1;
}
int cmp1(const void*a,const void* b)
{
    int aa=*(int*)a;
    int bb=*(int*)b;
    if(aa>bb)return -1;
    else return 1;
}
int main()
{
    char c;
    scanf("%c",&c);
    int aa[100],cnt=0,n,max;
    scanf("%d",&n);
    aa[cnt++]=n;
    max=n;
    while(scanf("%d",&n)==1){
        if(n!=max){max=n;aa[cnt++]=n;}

    }
    if(c=='A')qsort(aa,cnt,sizeof(int),cmp);
        else qsort(aa,cnt,sizeof(int),cmp1);

    for(int i=0;i<cnt;i++){
        printf("%d",aa[i]);
        i==cnt-1?printf("\n"):printf(" ");
    }

    return 0;
}
