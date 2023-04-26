#include <stdio.h>

int main() {

    int loop;
    long long int arr[1000];

    scanf("%d",&loop);

    for (int i = 0; i < loop; ++i) {
        long long int number;
        scanf("%lld",&number);
        if(number == 0){
            printf("%d",number);
            break;
        }
        int count = 0;
        while(number){
            arr[count++] = number%2333;
            number = number/2333;
        }
        for (int j = count - 1; j >= 0 ; --j) {
            printf("%lld ",arr[j]);
        }printf("\n");

    }
    return 0;
}


