#include <stdio.h>
#include <string.h>
int main(){
    int T;
    scanf("%d",T);
    for(int t;t<T;t++){
        printf("case #%d:\n",t);
        char s1[500];
        scanf("%s",s1);
        char a=s1[0];
        int b=1;
        int i;
        for(i=1;i<255||i<strlen(s1);i++){
            if(s[i]==a)b=b+1;
            else{
                printf("%d%c",b,a);
                a=s[i];
                b=1;
            }
        }
        if(i>=254){
            a=s[255];
            b=1;
            for(;i<strlen(s1);i++){
                if(s[i]==a)b=b+1;
                else{
                printf("%d%c",b,a);
                a=s[i];
                b=1;
                }
            }
        }
        printf("\n");
    }
    return 0;
    
}