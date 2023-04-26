#include <stdio.h>
#include <stdlib.h>


int cap(long long int);

int cmp(const void* a ,const void* b){
    if(cap(*(long long int* )a) == cap(*(long long int *) b))
        return (*(long long int *) a  -  *(long long int *) b);
    return cap(*(long long int *) b)  - cap(*(long long int* )a);
};
int main()
{
    int loop;
    scanf("%d",&loop);
    for (int i = 0; i < loop; ++i) {
        int number;
        scanf("%d",&number);
        long long int arr[number];
        for (int j = 0; j < number; ++j) scanf("%lld",&arr[j]);
        qsort(arr,number,sizeof(long long int),cmp);printf("case #%d:\n",i);
        for (int j = 0; j < number; ++j) printf("%lld ",arr[j]);printf("\n");
    }

}

int cap(long long int num){
    int count = 0;
    if(num >= 0){
    while(num){
        if(num %2 == 1)count ++;
        num/= 2;
    }return count;}
    else{
        num = ~num;
        while(num){
            if(num%2 != 0){
                count++;
            }num = num/2;
        }count = 64 - count;
    }return count;
}