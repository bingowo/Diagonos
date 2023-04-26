#include <stdio.h>
#include <stdlib.h>

void change(const int time, int light[5][5], const int i,const int j){
    //light[i-1][j-1] += time;
    light[i-1][j] += time;
    //light[i-1][j+1] += time;

    light[i][j-1] += time;
    light[i][j] += time;
    light[i][j+1] += time;

    //light[i+1][j-1] += time;
    light[i+1][j] += time;
    //light[i+1][j+1] += time;
}

int main()
{
    // ori 0 = yes
    // change 1 = no

    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        int lights[5][5] = {{0},{0},{0}};
        int time;
        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                scanf("%d",&time);
                time = time%2;
                change(time,lights,i,j);
            }
        }

        for(int i = 1; i <= 3; i++){
            for(int j = 1; j <= 3; j++){
                if(lights[i][j]%2 == 0) lights[i][j] = 1;
                else lights[i][j] = 0;
            }
        }

        printf("case #%d:\n",R);
        for(int i = 1; i <= 3; i++)
            printf("%d %d %d\n",lights[i][1],lights[i][2],lights[i][3]);

    }


    return 0;
}
