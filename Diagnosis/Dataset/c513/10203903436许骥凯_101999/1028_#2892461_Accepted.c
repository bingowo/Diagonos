#include<stdio.h>
#include<stdlib.h>

char way[2];

int compare(const void *p1, const void *p2){
    if (way[0] == 'A') return *(int*)p1 - *(int*)p2;
    return *(int*)p2 - *(int*)p1;
}
int main(){
    scanf("%s", way);
    int nums[100];
    int i = 0;
    do{
        scanf("%d", &nums[i++]);
    }while(getchar() != '\n');
    qsort(nums, i, sizeof(nums[0]), compare);
    for (int j = 0; j != i - 1; j++)
        if (nums[j] != nums[j+1])
            printf("%d ", nums[j]);
    printf("%d\n", nums[i-1]);
    return 0;
}   