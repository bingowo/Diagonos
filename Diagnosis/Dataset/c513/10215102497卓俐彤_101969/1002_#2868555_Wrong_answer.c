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
        int table[Maxlength];
        for(int i=0;i<Maxlength;i++){
            table[i]=-1;
        }
        int digit=0,N=1;
        char *p=secret;
        table[*p]=1;
        while(*++p){
            if(table[*p]==-1){
                table[*p]=digit;
                if(digit==0)digit=2;
                else digit+=1;
                N++;
            }
        }
        if(N<2)N=2;
        long long int truth=0;
        p=secret;
        while(*p){
            truth=truth*N+table[*p++];
        }
        printf("%lld\n",truth);
        printf("\n");
    }

    return 0;
}


