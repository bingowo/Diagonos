#include<stdio.h>

int turn(int a){
    if(a==0)return 1;
    else if(a==1)return 0;
}
int main(){
    int t,a=0;
    scanf("%d",&t);
    int num[3][3],state[3][3];
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)state[i][j]=1;
    while(a<t){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                scanf("%d",&num[i][j]);
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)num[i][j]=num[i][j]%2;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++){
                if(num[i][j]==1){
                    state[i][j]=turn(state[i][j]);
                    if(i+1<=2)state[i+1][j]=turn(state[i+1][j]);
                    if(j+1<=2)state[i][j+1]=turn(state[i][j+1]);
                    if(i-1>=0)state[i-1][j]=turn(state[i-1][j]);
                    if(j-1>=0)state[i][j-1]=turn(state[i][j-1]);
                }
            }
        printf("case #%d:\n",a);
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)printf("%d ",state[i][j]);
        a++;
    }
}