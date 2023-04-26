#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[1001] = {0};
    char c;
    scanf("%c\n",&c);
    int x;
    while(scanf("%d",&x) != EOF){
        a[x]++;
    }
    if(c = 'A'){
        int flag = 0;
        for(int i = 1;i <= 1000;i++){
            if(flag)printf(" ");
            if(a[i] != 0){
                scanf("%d",i);
                flag = 1;
            }
        }
    }else{
        int flag = 0;
        for(int i = 1000;i >= 1;i--){
            if(flag)printf(" ");
            if(a[i] != 0){
                scanf("%d",i);
                flag = 1;
            }
        }
    }

    return 0;
}
