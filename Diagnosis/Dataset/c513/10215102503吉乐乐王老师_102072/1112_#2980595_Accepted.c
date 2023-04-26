#include<stdio.h>
#include<stdlib.h>
int main(){
    int t;
    scanf("%d",&t);getchar();
    while(t--){
        int n;
        scanf("%d",&n);getchar();
        int ret=0;
        for(int w=0;w<=n/4;w++){
            for(int x=0;x<=n/3;x++){
                for(int y=0;y<=n/2;y++){
                    if(4*w+3*x+2*y<=n)ret++;
                }
            }
        }
        printf("%d\n",ret);
    }
}
