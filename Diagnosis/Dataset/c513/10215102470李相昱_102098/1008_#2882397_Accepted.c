#include <stdio.h>
int main() {
    int t;
    scanf("%d",&t);
    int i ;
    for(i = 0;i<t;i++){
        int a,b,c,num;
        scanf("%d%d",&a,&b);
        c= a^b;
        num = 0;
        while(c){
            if(c&1){
                num ++;
            }
            c =  c>>1;
        }
        printf("%d\n",num);
    }
    return 0;
}
