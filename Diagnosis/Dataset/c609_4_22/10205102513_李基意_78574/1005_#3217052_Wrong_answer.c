#include <stdio.h>
int main(){   
    int t;
    scanf("%d",&t);
    for(int i = 0; i < t; i++){
        int ans = 0;
        char c;
        while((c=getchar())&&c!='\n')
            ans = (c=='-')?ans*3 - 1:ans*3 + c - '0';
        printf("case #%d:\n",i);
        printf("%d\n",ans);
    }
        return 0;
}
