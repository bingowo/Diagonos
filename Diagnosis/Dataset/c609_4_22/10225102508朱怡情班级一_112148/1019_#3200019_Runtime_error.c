#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int target;
    int num;
}A;

int f(int n)
{
    int cnt=0;
    while(n>0){
        cnt++;
        n/=10;
    }
    return cnt;
}

int cmp(const void* x,const void* y)
{
    A c=*(A*)x;
    A d=*(A*)y;
    if(c.num!=d.num)return d.num-c.num;
    else return c.target-d.target;
}

int main()
{
    A *a=(A*)malloc(1000009*sizeof(int));
    int i=0;
    int temp;
    while(scanf("%d",&temp)!=EOF){
        a[i].target=temp;
        if(a[i].target<0){
            temp=-temp;
        }
        a[i].num=f(temp);
        i++;
    }
    qsort(a,i,sizeof(a[0]),cmp);
    for(int j=0;j<i;j++){
        printf("%d ",a[j].target);
    }
    free(a);
    return 0;
}
