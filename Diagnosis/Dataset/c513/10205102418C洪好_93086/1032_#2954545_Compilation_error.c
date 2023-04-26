//#include <bits/stdc++.h>
//using namespace std;
#include<stdio.h>
#include<stdlib.h>

typedef struct row
{
    int data_value[100];
}rows_data;

//bool cmp(rows_data a, rows_data b)
int cmp(const void *a1, const void *b1)
{
    int i = 0;
    rows_data *a=(rows_data *)a1;
    rows_data *b=(rows_data *)b1;
    while (a.data_value[i] != -1 && b.data_value[i] != -1)
    {
        if(a.data_value[i] > b.data_value[i]) 
            //return true;
            return *(int*)a-*(int*)b;
        else if(a.data_value[i] < b.data_value[i]) 
            //return false;
            return *(int*)b-*(int*)a;
        else i++;
    }
    if(a.data_value[i] == -1) 
        //return false;
        return *(int*)b-*(int*)a;
    //else return true;
    else return *(int*)a-*(int*)b;
}

void solve(int T)
{
    int N;
    scanf("%d", &N);
    rows_data rowsData[1000];
    for (int i = 0; i < N; ++i) 
    {
        for (int j = 0; j < 100; ++j) {
            scanf("%d", &rowsData[i].data_value[j]);
            if(rowsData[i].data_value[j] == -1) break;
        }
    }
    sort(rowsData,rowsData+N,cmp);
    for (int i = 0; i < N; ++i){
        for (int j = 0; j < 100; ++j){
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
    for (int i = 0; i < issue_num; ++i) {
        solve(i);
    }
    return 0;
}