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
                int tmp = operation[j][k];
                while(tmp>0){
                    light[j-1][k] = light[j-1][k]==0? 1:0;
                    light[j][k-1] = light[j][k-1]==0? 1:0;
                    light[j][k] = light[j][k]==0? 1:0;
                    light[j][k+1] = light[j][k+1]==0? 1:0;
                    light[j+1][k] = light[j+1][k]==0? 1:0;
                    tmp--;
                }
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
