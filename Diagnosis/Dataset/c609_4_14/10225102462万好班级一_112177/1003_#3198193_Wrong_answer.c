#include <stdio.h>

int main() {

    int loop;
    int arr[10];

    scanf("%d",&loop);

    for (int i = 0; i < loop; ++i) {
        int number;
        scanf("%d",&number);
        int count = 0;
        while(number){
            arr[count++] = number%2333;
            number = number/2333;
        }
        for (int j = count - 1; j >= 0 ; --j) {
            printf("%d ",arr[j]);
        }printf("\n");

    }
    return 0;
}
