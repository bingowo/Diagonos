#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int n;
        scanf("%d",&n);
        int p[100][2]={'0'};
        for(int i=0;i<n;i++){
            scanf("%d%d",&p[i][0],&p[i][1]);
        }
        int flag=1;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         if(p[i][0]==p[j][1]&&i!=j){
        //             flag=0;
        //             break;
        //         }
        //     }
        // }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(p[i][0]==p[j][0]){
                    flag=0;
                    break;
                }
            }
        }
        if(flag){
            printf("Lucky dxw!\n");
        }
        else{
            printf("Poor dxw!\n");
        }
    }
    return 0;
}