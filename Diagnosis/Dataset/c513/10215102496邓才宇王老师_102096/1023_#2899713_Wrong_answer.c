#include <stdio.h>
#include <stdlib.h>

 int number(char* str) {
    int len, I, sum = 0, flag = 0;
    len = strlen(str);
    for (int i = 0; i < len; i++)
        {if (str[i] >= '0' && str[i] <= '9') {
            sum = 10*sum + str[i] - 48;
            flag = 1;
        }}
        if (flag == 0) sum = -1;
    return sum;
    }
int strnumcmp(const void* a, const void* b) {
    int s1,s2;
    char* str1, *str2;
    str1 = (char*)a;
    str2 = (char*)b;
    s1 = number(str1);
    s2 = number(str2);
    if(s1 == s2)  return strcmp(str1, str2);
    else {
        if(s1 > s2) return 1;
        else  return -1;
    }
}
int main()
{
    char str[100][30];
    int count= 0;
    while (scanf("%s", str[count]) != EOF)
        count++;
   qsort(str, count, sizeof(str[0]), strnumcmp);
 for (int i = 0; i < count -1; i++)
        printf("%s ", str[i]);
    printf("%s\n", str[count-1]);

}
