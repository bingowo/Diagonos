#include <stdio.h>
#include <stdlib.h>

#define N 100
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int src[N];memset(src,0,N*sizeof(int));
        int des[N];memset(des,0,N*sizeof(int));
        int n = 0;
        scanf("%d",&n);
        int operation[n][2];memset(operation,0,n*2*sizeof(int));
        for(int j = 0;j<n;j++){
            scanf("%d%d",&operation[j][0],&operation[j][1]);
        }

//        printf("operation\n");
//        for(int j = 0;j<n;j++){
//            printf("%d %d\n",operation[j][0],operation[j][1]);
//        }

        for(int j = 0;j<n;j++){
            int flag = 1;
            for(int k = 0;k<j;k++){
                if(operation[k][0]==operation[j][0]&&operation[k][1]==operation[j][1]){
                    flag = 0;
                    break;//排除重复操作
                }
            }
            if(flag==1){
                src[operation[j][0]]++;
                des[operation[j][1]]++;
            }
        }

//        printf("src\n");
//        for(int j = 0;j<=10;j++){
//            printf("%d ",src[j]);
//        }
//        printf("\ndes\n");
//        for(int j = 0;j<=10;j++){
//            printf("%d ",des[j]);
//        }
//        printf("\n");

        int flag1 = 1;
        for(int j = 0;j<N;j++){
            if(src[j]==1&&des[j]==1){
                flag1 = 0;
                break;
            }
        }
        if(flag1==1){
            printf("Lucky dxw!\n");
        }
        else{
            printf("Poor dxw!\n");
        }
    }
    return 0;
}
