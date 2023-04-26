#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char a[60];
        scanf("%s",a);
        int b[128];
        for (int i=0;i<128;i++){
            b[i]=-1;
        }
        char* c=a;
        b[*a]=1;
        b[*++c]=0;
        int d=2;
        while(*++c){
            if(b[*c]==-1){
                b[*c]=d;
                d=d+1;
            }
        }
        long long int sum=0;
        char* f=a;
        while(*f){
            sum=sum*d+b[*f++];
        }
        printf("case #%d:\n%d\n",T,sum);

    }
    return 0;
}
