#include <stdio.h>
#include <string.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t;t<T;t++){
        char s1[500];
        scanf("%s",s1);
        printf("case #%d:\n",t);
        char a=s1[0];
        int b=1;
        int i;
        int flag=1;
        for(i=1;i<255&&i<strlen(s1)+1;i++){
            if(s1[i]==a)b=b+1;
            else{
                printf("%d%c",b,a);
                a=s1[i];
                b=1;
                flag=0;
            }
        }
        if(flag){
                printf("%d%c",b,a);
                flag=1;
        }
        //printf("\n%d\n",i);
        if(i==255){
            a=s1[255];
            b=1;
            for(i=256;i<strlen(s1)+1;i++){
                if(s1[i]==a)b=b+1;
                else{
                printf("%d%c",b,a);
                a=s1[i];
                b=1;
                flag=0;
                }
            }
        if(flag){
                printf("%d%c",b,a);
                flag=1;
        }
        }
        printf("\n");
    }
    return 0;

}
