#include <stdio.h>
char  s[26];
char m[100];
int main(){
    //预先初始化好两个数组
    for(int k = 0; k < 10;k++){
        s[k] = '0'+k;
    }

    for (int m= 10; m < 36;m++){
        s[m] = 'A'+m-10;
    }

    //确认一共有多少组数据
    int set = 0;
    scanf("%d",&set);
    for(int i = 0; i < set;i++){
        int N = 0;
        int R = 0;
        int flag = 0;
        scanf("%d",&N);
        scanf("%d",&R);
        if(N < 0){
            flag = 1;
            N = -N;
        }

        int p = 0;
        int left = 0;
        while(N  > 0) { //计算每一位 //非常基础的定理，取余数求得到那一串数字后反向输出
            left = N % R;//余数
            m[p] = s[left];
            p++;
            N = N/R;
        }

        if(flag == 1){
            printf("-");
        }

        for(int j =p-1; j >= 0;j--){//一位一位打印出来
            printf("%c",m[j]);
        }
        printf("\n");


    }
}
