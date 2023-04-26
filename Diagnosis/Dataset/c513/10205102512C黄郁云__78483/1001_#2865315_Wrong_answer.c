#include <stdio.h>
char a[1000];
int main(){
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
        int Ncopy = N;
        int highest = 0;
        int highestnum = 1;
        //得出最高位和最高位数
        while(Ncopy>highestnum*R){
            highest++;
            highestnum *= R;
        }

        int save = highest;//数组反向输出

        while(N%highestnum > 0){ //计算每一位
            int anum = 0;
            anum = N/highestnum;
            if (anum <= 9){
                a[highest] = anum+48;
            }else{
                a[highest] = anum+55;
            }

            N = N-anum*(highestnum);
            highest -= 1;
            highestnum = highestnum/R;
        }
        if (N <= 9){
            a[0] = N+48;
        }else{
            a[0] = N+55;
        }

        if(flag == 1){
            printf("-");
        }

        for(int j =save; j >= 0;j--){//一位一位打印出来
            printf("%c",a[j]);
        }
        printf("\n");


    }
}
