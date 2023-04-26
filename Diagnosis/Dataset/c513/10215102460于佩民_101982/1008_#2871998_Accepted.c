#include <stdio.h>
int main(){
    int num,x,y,a=0,z,c=0;
    scanf("%d",&num);
    while(a<num){
        scanf("%d%d",&x,&y);
        z=x^y;
        while(z!=0){
            if(z&1) c++;
            z=z>>1;
        }
        printf("%d\n",c);
        a++;
        c=0;
    }
    return 0;
}