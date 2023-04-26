#include <stdio.h>
#include <stdlib.h>

int cmpA(const void* e1,const void* e2){
    return *(int*)e1 - *(int*)e2;
};

int cap(long long int);
int main() {

    long long int arr[100000];


    int i = 0;


    do{scanf("%d",&arr[i]);i++;}while(getchar() != '\n');

    int max;
    for (int j = 1; j < i; ++j) {
        max = cap(arr[0]);
        if(max < cap(arr[j]))max = cap(arr[j]);
    }

    for (;max >= 0;max--) {
        long long int text[100000];int count = 0;
        for (int j = 0; j < i; ++j) {
            if(cap(arr[j]) == max)
            {
                text[count++] = arr[j];
            }
        }
        qsort(text,count,sizeof(int),cmpA);
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