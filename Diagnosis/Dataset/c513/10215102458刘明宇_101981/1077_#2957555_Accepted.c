#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int cmp(const void *a, const void *b)
{
    int *p1,*p2;
    p1 = (int *)a;
    p2 = (int *)b;
    return *p1 - *p2;
}


int main()
{
    int m,n;
    int A[501],B[501];
    scanf("%d",&m);
    for(int i = 0;i<m;i++){
        scanf("%d",&A[i]);
    }
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d",&B[i]);
    }
    //盛放相同的元素
    int same[501];
    int cnt = 0;
    for(int k = 0;k<m;k++){
        for(int j = 0;j<n;j++){
            if(A[k] == B[j]){
                same[cnt++] = B[j];
                B[j] = -1;
            }
        }
    }
    //盛放剩余的元素，B中有A中没有的
    int dif[501];
    int cntt = 0;
    for(int i = 0;i < n;i++){
        if(B[i] != -1){
            dif[cntt++] = B[i];
        }
    }
    for(int i = 0;i < cnt;i++){
        printf("%d ",same[i]);
    }
    qsort(dif,cntt,sizeof(dif[0]),cmp);
    for(int i = 0;i<cntt;i++){
        printf("%d ",dif[i]);
    }

}
