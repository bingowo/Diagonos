#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char a[61];
        scanf("%s",a);
        int b[128];
        for (int i=0;i<128;i++){
            b[i]=-1;
        }
        char* c=a;
        b[*c]=1;
        int d=0,D=1;
        while(*++c){
            if(b[*c]==-1){
                b[*c]=d;
                if(d=D)d=d+2;
                else d=d+1;
                D=D+1;
            }
        }
        if(D<2)D=2;
        long long int sum=0;
        char* f=a;
        while(*f){
            sum=sum*D+b[*f++];
        }
        printf("case #%d:\n%lld\n",i,sum);

    }
    return 0;
}
