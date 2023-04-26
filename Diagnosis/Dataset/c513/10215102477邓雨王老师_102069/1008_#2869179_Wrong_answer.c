#include<stdio.h>
int main(){
    int chance;
    scanf("%d",&chance);
    int i;
    for(i=0;i<chance;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        int sum=0;
        while(x!=0 | y!=0){
            if((x%2)==y%2) sum=sum+1;
            x=x/2;
            y=y/2;
        }
        printf("%d\n",sum);
    }
}