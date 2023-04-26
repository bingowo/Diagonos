#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int a,b,c;
    while(!(n == 0 && m == 0)){
        int score[10][4] = {0};
        for(int i = 0;i < m;i++){
            scanf("%d%d%d",&a,&b,&c);
            switch(c){
            case 1:
                score[a - 1][0] += 3;
                score[a - 1][1] ++;
                score[b - 1][0]--;
                score[b - 1][2] ++;
                break;
            case -1:
                score[b - 1][0] += 3;
                score[b - 1][1] ++;
                score[a - 1][0]--;
                score[a - 1][2] ++;
                break;
            case 0:
                score[a - 1][0]++;
                score[b - 1][0]++;
                break;
            }
        }
        for(int i = 0;i < n;i++){
            score[i][3] = i + 1;
        }
        for(int i = 0;i < n - 1;i++){
            for(int j = i + 1;j < n;j++){
                int temp;
                if(score[i][0] < score[j][0]){
                    for(int k = 0;k < 4;k++){
                        temp = score[i][k];
                        score[i][k] = score[j][k];
                        score[j][k] = temp;
                    }
                }else if(score[i][0] == score[j][0]){
                    if(score[i][1] < score[j][1]){
                        for(int k = 0;k < 4;k++){
                            temp = score[i][k];
                            score[i][k] = score[j][k];
                            score[j][k] = temp;
                        }
                    }else if(score[i][1] == score[j][1]){
                        if(score[i][2] > score[j][2]){
                            for(int k = 0;k < 4;k++){
                                temp = score[i][k];
                                score[i][k] = score[j][k];
                                score[j][k] = temp;
                            }
                        }else if(score[i][2] == score[j][2]){
                            if(score[i][3] > score[j][3]){
                                for(int k = 0;k < 4;k++){
                                    temp = score[i][k];
                                    score[i][k] = score[j][k];
                                    score[j][k] = temp;
                                }
                            }
                        }
                    }
                }
            }
        }
        for(int i = 0;i < n;i++){
            printf("%d ",score[i][3]);
        }
        printf("\n");
        scanf("%d%d",&n,&m);
    }
    return 0;
}
