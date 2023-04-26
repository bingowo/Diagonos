#include<stdio.h>
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    int ret=0;
    while(x&&y){
        int min=x<y?x:y;
        int max=x>y?x:y;
        ret+=min*4;
        x=max-min;
        y=min;
    }
    printf("%d",ret);
}