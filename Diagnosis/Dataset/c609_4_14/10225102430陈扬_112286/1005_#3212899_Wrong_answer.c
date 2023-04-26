#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    int T,temp;
    char *arr;
    long long sum;
    arr = malloc(sizeof(char)*10000);
    scanf("%d", &T);
    for(int i=0; i<T; i++){
        scanf("%s", arr);
        sum = 0;
        for(int j=0; j<strlen(arr); j++){
            if(arr[j]=='-')
            {
                temp=-1;
                
            }
            else {
                temp = (int)arr[j]-48;
            }
            sum = sum*3+temp;
        }
        printf("case #%d:\n", i);
        printf("%lld", sum);
    }
    free(arr);
    return 0;
}