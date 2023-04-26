#include <stdio.h>
#include <stdlib.h>

struct t{
    int x;
    int flag;
};

int cmp1(const void* a,const void* b);
int cmp2(const void* a,const void* b);

int main()
{
    char c;
    scanf("%c",&c);
    int n;
    struct t table[1000];
    for(int i = 0;i < 1000;i++){
        table[i].x = i+1;
        table[i].flag = -1;
    }
    int j = 0,a[100],k=0;
    while(scanf("%d",&n)!= EOF){
        if(table[n-1].flag == -1){
            a[k++]=table[n-1].x;
            table[n-1].flag = 1;
        }
        j++;
    }
    if(c=='A'){
        qsort(a,k,sizeof(int),cmp1);
    }
    else{
        qsort(a,k,sizeof(int),cmp2);
    }
    for(int t = 0;t < k;t++){
        printf("%d ",a[t]);
    }
    return 0;
}

int cmp1(const void* a,const void* b)
{
    int x = *((int *)a);
    int y = *((int *)b);
    return x-y;
}

int cmp2(const void* a,const void* b)
{
    int x = *((int *)a);
    int y = *((int *)b);
    return y-x;
}
