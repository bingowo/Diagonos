#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i!=T;i++){
        int x=0,y=0,count=0;
        scanf("%d %d",&x,&y);
        while(x!=0 || y!=0){
            if((1&x)!=(1&y)) 
                count++;
            x >>= 1 ; 
            y >>= 1 ;
        }
        printf("%d\n",count);
    }
}