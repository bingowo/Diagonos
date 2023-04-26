#include <stdio.h>
#include <stdlib.h>

#define Maxlength 128

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char secret[Maxlength];
        scanf("%s",secret);
        long long int truth=0;
        char *p=secret;
        while(*p){
            truth=truth*3;
            if(*p=='-')truth-=1;
            else if(*p=='1')truth+=1;
            p++;
        }
        printf("%lld\n",truth);
    }

    return 0;
}


