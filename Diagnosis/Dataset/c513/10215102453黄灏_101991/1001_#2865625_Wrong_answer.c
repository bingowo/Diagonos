#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        int n,r,a,c=0;
        char ans[32];
        scanf("%d %d",&n,&r);
        if(n<0) {
            printf("-");
            n=-n;}
        a=n;
        do{
            if(a%r<=9){
                 ans[c++]=a%r;
            }
            else{
                ans[c++]=a%r-10+'A';
            }
            a=a/r;
        }while(a!=0);
        for(int c;c>=0;c--){
            printf("%c",ans[c]);
        }
    }
    return 0;
}
