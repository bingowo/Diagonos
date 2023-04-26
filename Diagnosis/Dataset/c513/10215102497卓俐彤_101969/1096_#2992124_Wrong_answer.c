#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int isEqual=1,a,b,n;
        int command[101][101]={{0,0}},num_a[101],num_b[101];
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d %d",&a,&b);
                if(!command[a][b]){
                    command[a][b]=1;
                    num_a[a]++;
                    num_b[b]++;
                }
        }
        for(int i=0;i<101;i++){
            if(num_a[i]&&num_b[i]){
                isEqual=0;
                break;
            }
            else if(num_a[i]>1){
                isEqual=0;
                break;
            }
        }
        if(isEqual)printf("Lucky dxw!\n");
        else printf("Poor dxw!\n");
    }
    return 0;
}
