#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int num[50];
    int len;
}Num;

int compare(const void *p1, const void *p2){
    Num num1 = *(Num*)p1, num2 = *(Num*)p2;
    int len1 = num1.len, len2 = num2.len;
    int len = (len1 > len2)? len2: len1;
    for (int i = 0; i != len; i++){
        if (num1.num[i] == num2.num[i]) continue;
        return num2.num[i] - num1.num[i];
    }
    return len2 - len1;
}
int main(){
    int pro;
    scanf("%d", &pro);
    for (int i = 0; i != pro; i++){
        int n; 
        scanf("%d", &n);
        Num *nums = (Num*)malloc(sizeof(Num) * n);
        for (int j = 0; j != n; j++){
            nums[j].len = 0;
            while(1){
                int temp;
                scanf("%d", &temp);
                if (temp == -1) break;
                nums[j].num[nums[j].len++] = temp;
            }
        }
        qsort(nums, n, sizeof(nums[0]), compare);
        for (int j = 0; j != n; j++)
            for (int k = 0; k != nums[j].len; k++)
                if (k != nums[j].len - 1) printf("%d ", nums[j].num[k]);
                else printf("%d\n", nums[j].num[k]);
        free(nums);
    }

}