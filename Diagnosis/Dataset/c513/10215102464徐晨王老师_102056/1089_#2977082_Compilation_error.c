#include <stdio.h>
#include <math.h>


int main(){
    int T;
    scanf("%d",&t);
    for(int t=0;t<T;t++){
        unsigned long long int A;
        scanf("%llu",&A);
        int B,N;
        scanf("%d%d",&B,&N);
        unsigned long long int NN=1;
        for(int n=0;n<N;n++){
            NN=NN*10;
        }
        unsigned long long int AA=A%NN;
        for(int i=1;i<B;i++){
            AA=AA*AA;
            AA=AA%NN;
        }
        printf("%llu",AA);
    }
    return 0;
}


