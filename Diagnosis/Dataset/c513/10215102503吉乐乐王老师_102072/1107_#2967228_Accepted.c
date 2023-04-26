#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    int cas=0;
    while(t--){
        int light[4][4]={0};
        int ope[4][4]={0};
        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
                scanf("%d",&ope[i][j]);
                light[i][j]=1;
            }
            getchar();
        }
        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
                while(ope[i][j]--){
                    light[i][j]=!light[i][j];
                    if(i-1>0)light[i-1][j]=!light[i-1][j];
                    if(i+1<4)light[i+1][j]=!light[i+1][j];
                    if(j-1>0)light[i][j-1]=!light[i][j-1];
                    if(j+1<4)light[i][j+1]=!light[i][j+1];
                }
            }
        }
        printf("case #%d:\n",cas++);
        for(int i=1;i<4;i++){
            for(int j=1;j<4;j++){
                printf("%d",light[i][j]);
                if(j!=3)putchar(' ');
            }
            putchar('\n');
        }
    }
}