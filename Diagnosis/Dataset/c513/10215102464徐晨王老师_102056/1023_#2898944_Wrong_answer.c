#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[110][40];

int strnumcmp(const void* a, const void* b) {
    int sum1,sum2;
    char* str1, *str2;
    str1 = (char*)a;
    str2 = (char*)b;
    sum1 = number(str1);
    sum2 = number(str2);
    if(sum1 == sum2)  return strcmp(str1, str2);
    else {
        if(sum1 > sum2) return 1;
        else  return -1;
    }
}

int number(char* str) {
    int len, I, sum = 0, flag = 0;
    len = strlen(str);
    for (int i = 0; i < len; i++)
        if (str[i] >= '0' && str[i] <= '9') {
            sum = 10*sum + str[i] - 48;
            flag = 1;
        }
        if (flag == 0) sum = -1;
    return sum;
}


int main(){

int count = 0;
while (scanf("%s", str[count]) != EOF){
    count++;
}
int i;
qsort(str, count, sizeof(str[0]), strnumcmp);
for ( i = 0; i < count - 1; i++){
        printf("%s", str[i]);
}
printf("%s\n", str[i]);

return 0;
}
