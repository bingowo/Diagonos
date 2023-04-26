#include <stdio.h>
#include <stdlib.h>

int A[110][110];
 int common_flag[110];
  int common[110];

  int cmp(const void*a,const void* b){
        int *A = (int*)a;
        int *B= (int*)b;
        return(*A-*B);
  }

int main(){
    int round = 0;
    scanf("%d",&round);
    for(int i = 0; i <round;i++){
        scanf("%d",&A[i][0]);
        for(int j = 1; j <A[i][0];j++){
            scanf("%d",&A[i][j]);
        }

    }

    int common_num = A[0][0];

    for(int i = 0; i <A[0][0];i++){
        common[i] = A[0][i];
    }
    int change = 0;
    for(int i = 1; i <round;i++){
        for(int j = 1; j <A[i][0];j++){
            for(int k = 0;k <common_num;k++){
                if(A[i][j] == common[k]){
                    common_flag[k] = 1;
                    change = 1;
                    break;
                }
            }

        }
        int len = 0;

        if(change == 1){
            for(int m = 0; m<common_num;m++){
                if(common_flag[m] == 1){
                    common[len++] = common[m];
                    common_flag[m] = 0;
                }else{;

                }
            }
            common_num = len;
            change = 0;
        }else if(change == 0){
                common_num  = 0;
            break;
        }
    }

    qsort(common,common_num,sizeof(common[0]),cmp);
    for(int j = 0; j <common_num;j++){
        printf("%d ",common[j]);
    }
}
