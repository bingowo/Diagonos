#include<stdio.h>
#include<stdlib.h>

int n, m, k, count = 0;
int dis[10] = {0,-1,1,-1,-1,1,-1,1,1};
// int table[200][200][4][200] = {0};
int arr[200][200] = {0};

void func(int a, int b, int c){//对单点（a，b）进行四个方向所有边长的计数
    int res = 0;
    for (int d = 2; d < 200; d++){
        if ((a+d*dis[c])>n || (a+d*dis[c])<-1 || (b+d*dis[c+1])>m || (b+d*dis[c+1])<-1) return;
        int jd = d;
        for (int i = 0; i < d; i++){
            for (int j = 0; j < jd; j++){
                res += arr[a+i*dis[c]][b+j*dis[c+1]];
            }
            jd--;
        }    
        if (res >= k) count++;
    }
    return;
}

int main(){
    //int a, b, c, d; //a行 b列 c4个方向 d边长
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) scanf("%d", &arr[i][j]);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            //四个方向
            func(i,j,1);
            func(i,j,3);
            func(i,j,5);
            func(i,j,7);
        }
    }
    printf("%d\n", count);
    return 0;
}