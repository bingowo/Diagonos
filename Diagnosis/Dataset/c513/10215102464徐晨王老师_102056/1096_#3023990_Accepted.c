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
        int len=0;
        for(int i=0;i<n;i++){
            int x,y;
            int pc=1;
            scanf("%d%d",&x,&y);
            for(int j=i-1;j>=0;j--){
                if(x==p[j][0]&&y==p[j][1]){
                    pc=0;
                    break;
                }
            }
            if(pc==0)continue;
            else{
                p[len][0]=x;
                p[len][1]=y;
                len++;
            }
        }
        int flag=1;
        for(int i=0;i<len;i++){
            for(int j=0;j<len;j++){
                if(p[i][0]==p[j][1]&&i!=j){
                    flag=0;
                    break;
                }
            }
        }
        for(int i=0;i<len;i++){
            for(int j=i+1;j<len;j++){
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