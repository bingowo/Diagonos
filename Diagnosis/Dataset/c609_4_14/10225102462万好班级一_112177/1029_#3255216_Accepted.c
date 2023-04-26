#include<stdio.h>
#include <stdlib.h>

int cmp(const void* a,const void* b){
    return *(int*)a - *(int*)b;
}

int main() {
    int end = 0;//记录目前特殊序列的最后一位
    int i,j;//记录检查元素的位置

    int m;scanf("%d",&m);int arr_a[m];
    for (int q = 0; q < m; ++q) {scanf("%d",&arr_a[q]);}
    int n;scanf("%d",&n);int arr_b[n];
    for (int z = 0; z < n; ++z) {scanf("%d",&arr_b[z]);}

    for (i = 0; i < m; ++i) {//遍历数组a中的所有元素
        for (j = 0; j < n; ++j) {//遍历数组b中的所有元素
            if(arr_a[i] == arr_b[j])
            {int tmp;tmp = arr_b[end];arr_b[end] = arr_b[j];arr_b[j] = tmp;end++;}
        }
    }
    for (int w = 0; w < end; ++w) {printf("%d ",arr_b[w]);}
    int tmp_p[n-end];
    for (int k = end; k < n; ++k)
    {tmp_p[k - end] = arr_b[k];}
    qsort(tmp_p,n-end,sizeof(int),cmp);
    for (int k = 0; k < n-end; ++k) {printf("%d ",tmp_p[k]);}
}