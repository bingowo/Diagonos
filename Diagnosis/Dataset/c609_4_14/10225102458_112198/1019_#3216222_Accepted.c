#include <stdio.h>
#include <stdlib.h>
int cmp(const void*a,const void* b)
{
    int a2=*(int*)a;
    int b2=*(int*)b;
    int aa,bb;
    if(a2>0)aa=a2;else aa=-a2;
    if(b2>0)bb=b2;else bb=-b2;

    int a1=0,b1=0;
    do{
        a1++;
        aa/=10;
    }while(aa!=0);
    do{
        b1++;
        bb/=10;
    }while(bb!=0);
    if(a1==b1){
        if(a2>b2)return 1;
        else return -1;
    }
    else if(a1>b1)return -1;
    else return 1;
}
int main()
{
    int n,cnt=0;
    int* m=(int*)malloc(sizeof(int)*1000000);
    while(scanf("%d",&n)==1){
        m[cnt++]=n;
    }
    qsort(m,cnt,sizeof(int),cmp);
    for(int i=0;i<cnt;i++){
        printf("%d",m[i]);
        i==cnt-1?printf("\n"):printf(" ");
    }
    return 0;
}
