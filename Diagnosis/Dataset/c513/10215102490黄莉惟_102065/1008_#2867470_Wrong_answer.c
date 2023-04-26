#include <stdio.h>
#include<string.h>
int main(){
    int t,i;
    int sum;
    int x,y;
    int m=0;
    scanf("%d",&t);
    while(m<t){
        sum=0;
        scanf("%d %d",&x,&y);
        for(i=0;i<31;i++){
            if((x<<(31-i)>>31)!=(y<<(31-i)>>31)){
                sum+=1;
            }
        }
        printf("%d",sum);
        m++;
    }
}