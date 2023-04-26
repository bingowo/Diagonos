#include <stdio.h>
int main(){
    int T;
    scanf("%d ",&T);
    for(int t = 0; t < T; t++){
        int ans = 0;char c;
        while((c=getchar())&&c!='\n')
            ans = (c=='-')?ans*3 - 1:ans*3 + c - '0';
        printf("case #%d:\n",t);
        printf("%d\n",ans);
    }
        return 0;
}

