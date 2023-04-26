#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++){
        int n,r,a,c=0;
        char ans[33];
        scanf("%d %d\n",&n,&r);
        if(n<0) {
            printf("-");
            n=0-n;}
        do{
            if(n%r<=9){
                 ans[c++]=n%r+'0';
            }
            else{
                ans[c++]=n%r-10+'A';
            }
            n=n/r;
        }while(n!=0);
        for(int c;c>=0;c--){
            printf("%c",ans[c]);
        }
        printf("\n");
    }
    return 0;
}
