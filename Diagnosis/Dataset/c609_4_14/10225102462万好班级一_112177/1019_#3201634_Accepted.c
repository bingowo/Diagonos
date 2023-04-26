#include <stdio.h>
#include <stdlib.h>

int cmpA(const void* e1,const void* e2){
    return *(int*)e1 - *(int*)e2;
};

int cap(long long int);
int main() {

    long long int arr[1000001];


    int i = 0;


    do{scanf("%lld",&arr[i]);i++;}while(getchar() != '\n');


    for (int max = 9;max >= 0;max--) {
        long long int text[1000001];int count = 0;
        for (int j = 0; j < i; ++j) {
            if(cap(arr[j]) == max)
            {
                text[count++] = arr[j];
            }
        }
        qsort(text,count,sizeof(long long int),cmpA);
        for (int j = 0; j < count; ++j) {
            printf("%lld ",text[j]);
        }
    }

}

int cap(long long int a){
    int count = 0;
    while(a)
    {
        a=a/10;
        count++;
    }
    return count;
}