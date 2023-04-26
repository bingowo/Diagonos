#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char str[101];
        scanf("%s",str);
        int lights[4]={0};
        printf("case #%d:\n");
        for(int i=0;i<4;i++){
            printf("%d%c",lights[i],i==3?' ':'\n');
        }
    }
    return 0;
}
