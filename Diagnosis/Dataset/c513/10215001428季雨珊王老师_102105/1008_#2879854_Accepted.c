#include<stdio.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        int x,y;
        scanf("%d%d",&x,&y);
        int z;
        z=x^y;
        int count=0;
        while(z){
            z&=(z-1);
            count++;
        }
        printf("%d\n",count);
    }
    return 0;
}
