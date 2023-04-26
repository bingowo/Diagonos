#include <stdio.h>
#include <stdlib.h>

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        int light[3][3];memset(light,0,3*3*sizeof(int));
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                light[j][k] = 1;
            }
        }
        int operation[3][3];memset(operation,0,3*3*sizeof(int));
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                scanf("%d",&operation[j][k]);
            }
        }
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                int tmp = operation[j][k]%2;
                //printf("tmp = %d\n",tmp);
                if(tmp==1){
                    if(j-1>=0){light[j-1][k] = light[j-1][k]==0? 1:0;}
                    if(k-1>=0){light[j][k-1] = light[j][k-1]==0? 1:0;}
                    light[j][k] = light[j][k]==0? 1:0;
                    if(k+1<3){light[j][k+1] = light[j][k+1]==0? 1:0;}
                    if(j+1<3){light[j+1][k] = light[j+1][k]==0? 1:0;}
                }
                //printf("%d,%d:\n",j,k);
                //for(int j1 = 0;j1<3;j1++){
                //    for(int k1 = 0;k1<3;k1++){
                //        printf("%d ",light[j1][k1]);
                //    }
                //    printf("\n");
                //}
            }
        }
        printf("case #%d:\n",i);
        for(int j = 0;j<3;j++){
            for(int k = 0;k<3;k++){
                printf("%d ",light[j][k]);
            }
            printf("\n");
        }
        //for(int j = 0;j<3;j++){
        //    for(int k = 0;k<3;k++){
        //        printf("%d ",operation[j][k]);
        //    }
        //    printf("\n");
        //}
    }
    return 0;
}
