#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct rows_data
{
    int data_value[100];
};

int cmp(const void* a, const void* b)
{
    struct rows_data* rowA = (struct rows_data*) a;
    struct rows_data* rowB = (struct rows_data*) b;
    int i = 0;
    while (rowA->data_value[i] != -1 && rowB->data_value[i] != -1)
    {
        if(rowA->data_value[i] > rowB->data_value[i]) return -1;
        else if(rowA->data_value[i] < rowB->data_value[i]) return 1;
        else i++;
    }
    if(rowA->data_value[i] == -1) return 1;
    else return -1;
}

void solve(int T)
{
    int N;//待排序行数
    scanf("%d", &N);
    struct rows_data rowsData[1000];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            scanf("%d", &rowsData[i].data_value[j]);
            if(rowsData[i].data_value[j] == -1) break;
        }
    }
    qsort(rowsData, N, sizeof(rowsData[0]), cmp);
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            if(rowsData[i].data_value[j] == -1) break;
            printf("%d ",rowsData[i].data_value[j]);
        }
        printf("\n");
    }
}

int main()
{
    int issue_num;
    scanf("%d", &issue_num);
    for (int i = 0; i < issue_num; ++i)
    {
        solve(i);
    }
    return 0;
}
