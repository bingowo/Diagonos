#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int itos(int *temp, long long int item){
    int index = 0;
    if (item < 0) item = -item;
    do{
        temp[index++] = item % 10;
        item /= 10;
    }while(item);
    return index - 1;
}

int compare(const void *p1, const void *p2){
    long long int t1 = *(long long int*)p1, t2 = *(long long int*)p2;
    int s1[18], s2[18];
    int idx1 = itos(s1, t1), idx2 = itos(s2, t2);
    if (s1[idx1] == s2[idx2]) return (t1 > t2)? 1: -1;
    return (s1[idx1] > s2[idx2])? -1: 1; 
}

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i != n; i++){
        int len;
        scanf("%d", &len);
        long long int *numbers = (long long int*)malloc(sizeof(long long int)*len);
        for (int j = 0; j != len && scanf("%lld", &numbers[j]); j++);
        qsort(numbers, len, sizeof(numbers[0]), compare);
        printf("case #%d:\n", i);
        for (int j = 0; j != len; j++)
            if (j != len - 1) printf("%lld ", numbers[j]);
            else printf("%lld\n", numbers[j]);
        free(numbers);
    }
    return 0;
}