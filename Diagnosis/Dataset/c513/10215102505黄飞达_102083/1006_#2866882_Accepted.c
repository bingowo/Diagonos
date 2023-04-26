#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
    int t;
    char c;
    int arr[100] = {0};
    scanf("%d ", &t);
    for (int i = 0; i < t; i++){
        int len = 0;

        while ((c = getchar()) != '\n'){
            if (c == '-') arr[len] = -1;
            else if (c == '0') arr[len] = 0;
            else if (c == '1') arr[len] = 1;
            len++;
        }
        int res = 0, value = len;
        for (int j = 0; j < len; j++){
            res += arr[j] * pow(3, --value);
        }

        printf("case #%d:\n%d\n", i, res);
    }
    return 0;
}