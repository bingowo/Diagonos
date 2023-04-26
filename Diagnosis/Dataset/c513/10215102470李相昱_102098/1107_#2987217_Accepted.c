#include <stdio.h>
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        int light[3][3]={1,1,1,1,1,1,1,1,1};
        for(int j=0;j<3;j++){
            for(int p=0;p<3;p++){
                int temp;
                scanf("%d",&temp);
                light[j][p] = light[j][p]+temp;
                if(j-1>=0){
                    light[j-1][p] = light[j-1][p]+temp;
                }
                if(j+1<3){
                    light[j+1][p] = light[j+1][p]+temp;
                }
                if(p-1>=0){
                    light[j][p-1] = light[j][p-1]+temp;
                }
                if(p+1<3){
                    light[j][p+1] = light[j][p+1]+temp;
                }
            }
        }
        for(int j=0;j<3;j++){
            for(int p=0;p<3;p++){
                printf("%d%c",light[j][p]%2,p==2?'\n':' ');
            }
        }
    }
    return 0;
}
