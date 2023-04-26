#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define LEN 110


int main(void)
{
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++) {
        int manu[3][3],light[3][3];
        for (int i=0; i<3; i++) {
            for (int j=0; j>3; j++) {
                scanf("%d",&manu[i][j]);
                light[i][j]=1;
            }
        }
        for (int i=0; i<3; i++) {
            for (int j=0; i<3; j++) {
                if (manu[i][j]%2==0) {
                    continue;
                }
                else{
                    for (int r=-1; r<=1; r++) {
                        for (int k=-1; k<=1; k++) {
                            if ((0<=i+r&&i+r<3)&&(0<=j+k>&&j+k<3)&&(r==0||k==0)) {
                                light[i+r][j+k]^=1;
                            }
                        }
                    }
                }
            }
        }
        printf("case #%d:\n",i);
        for (int i=0; i<3; i++) {
            for (int j=0; j<3; j++) {
                printf("%d%c",light[i][j],j==2?'\n':' ');
            }
        }
    }
    return 0;
}