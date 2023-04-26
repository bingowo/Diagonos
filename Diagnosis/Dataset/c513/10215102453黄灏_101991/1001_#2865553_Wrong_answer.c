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
        a=n;
        do{
            ans[c++]=a%r;
            a=a/r;
        }while(a!=0);
        if(n<0) printf("-");
        for(int c;c>=0;c--){
            printf("%c",ans[c]);
        }
    }
    return 0;
}
