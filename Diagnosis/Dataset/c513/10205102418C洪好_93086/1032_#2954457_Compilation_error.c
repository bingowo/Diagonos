//#include <bits/stdc++.h>
//using namespace std;
#include<stdio.h>

struct rows_data{
    int data_value[100];
};

bool cmp(rows_data a, rows_data b){
    int i = 0;
    while (a.data_value[i] != -1 && b.data_value[i] != -1)
    {
        if(a.data_value[i] > b.data_value[i]) 
            return true;
        else if(a.data_value[i] < b.data_value[i]) 
            return false;
        else i++;
    }
    if(a.data_value[i] == -1) 
        return false;
    else return true;
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

int main(){
    int issue_num;
    scanf("%d", &issue_num);
    for (int i = 0; i < issue_num; ++i) {
        solve(i);
    }
    return 0;
}