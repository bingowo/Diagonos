#include <stdio.h>
#include <stdlib.h>


int cap(int);

int cmp(const void* a ,const void* b){
    if(cap(*(int* )a) == cap(*(int *) b))
        return (*(int *) a  -  *(int *) b);
    return cap(*(int *) b)  - cap(*(int* )a);
};
int main()
{
    int loop;
    scanf("%d",&loop);
    for (int i = 0; i < loop; ++i) {
        int number;
        scanf("%d",&number);
        int arr[number];
        for (int j = 0; j < number; ++j) scanf("%d",&arr[j]);
        qsort(arr,number,sizeof(int),cmp);printf("case #%d:\n",i);
        for (int j = 0; j < number; ++j) printf("%d ",arr[j]);printf("\n");
    }

}

int cap(int num){
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