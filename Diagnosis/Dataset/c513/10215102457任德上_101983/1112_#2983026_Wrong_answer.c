#include<stdio.h>
int main(){
    int t,x1,x2,x3,x4,sum=0;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n;
        scanf("%d",&n);
        x1=n,x2=n/2+1,x3=n/3+1,x4=n/4+1;
        for(int i4=x4;x4>=0;x4--){
            for(int i3=x3;x3>=0;x3--){
                for(int i2=x2;x2>=0;x2--){
                    for(int i1=x1;x1>=0;x1--){
                        if(4*i4+3*i3+2*i2+i1==t)sum++;
                    }
                }
            }   
        }
        printf("%d\n",sum);
    }
    return 0;
}