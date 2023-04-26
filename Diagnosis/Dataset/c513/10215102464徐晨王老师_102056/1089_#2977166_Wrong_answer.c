#include <stdio.h>
#include <math.h>


int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        unsigned long long int A;
        scanf("%llu",&A);
        int B,N;
        scanf("%d%d",&B,&N);
        unsigned long long int NN=1;
        for(int n=0;n<N;n++){
            NN=NN*10;
        }
        unsigned long long int AA=A%NN;
        unsigned long long int AAA=AA;
        for(int i=1;i<B;i++){
            AAA=AAA*AA;
            AAA=AAA%NN;
        }
        unsigned long long int x=1,y=0;
        while(x<AAA){
            x=x*10;
            y=y+1;
        }
        if(AAA==0){
        for(int i=y+1;i<N;i++){
            printf("0");
        }
        }
        else{
        for(int i=y+2;i<N;i++){
            printf("0");
        }
        }
        printf("%llu\n",AAA);
    }
    return 0;
}


