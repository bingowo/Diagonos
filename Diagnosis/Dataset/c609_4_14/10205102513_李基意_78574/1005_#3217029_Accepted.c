#include <stdio.h>
int main(void){   
    int __;
    scanf("%d ",&__);
    for(int _ = 0; _ < __; _++){
        int ans = 0;char c;
        while((c=getchar())&&c!='\n')
            ans = (c=='-')?ans*3 - 1:ans*3 + c - '0';
        printf("case #%d:\n",_);
        printf("%d\n",ans);
    }
        return 0;
}