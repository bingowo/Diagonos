#include <stdio.h>
#include <stdlib.h>

int *aa,a;
int cmp(const void* m,const void *n)
{
    int am=*(int*)m;
    int bm=*(int*)n;
    int a1=a+1,b1=a+1;
    for(int i=0;i<a;i++){
        if(am==aa[i]){a1=i;break;}
    }
    for(int i=0;i<a;i++){
        if(bm==aa[i]){b1=i;break;}
    }
    if(a1==a+1 && b1==a+1)return am-bm;
    else return a1-b1;



}
int main()
{
    int b;
    scanf("%d",&a);
    aa=(int*)malloc(sizeof(int)*a);
    for(int i=0;i<a;i++)scanf("%d",aa+i);
    scanf("%d",&b);
    int bb[b];
    for (int i=0;i<b;i++)scanf("%d",bb+i);
    qsort(bb,b,sizeof(int),cmp);
    for(int i=0;i<b;i++)printf("%d ",bb[i]);
    return 0;
}
