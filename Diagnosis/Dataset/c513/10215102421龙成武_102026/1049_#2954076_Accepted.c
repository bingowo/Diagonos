#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int isfor(char a);
int compar(const void* p1, const void* p2);
int main()
{
    int i, j, k,x, T, lens;
    char s[501], ** a;
    a = (char**)malloc(501 * sizeof(char*));
    scanf("%d", &T);getchar();
    //for (i = 0;i < T;i++) 论我总是把for循环里面的i又继续用这回事
    for(x=0;x<T;x++)
    {
        s[0] = ' ';         //后面的操作会覆盖掉这个空格，所以需要放到循环里
        gets(s + 1);
        lens = strlen(s);
        k = 0;                //记录了单词的个数
        for (j = 0;j < lens;j++)                      //最后一个单词后面必然是符号
        {
            if (isfor(s[j]))            //如果当前是符号
            {
                s[j]=0;
                if (!isfor(s[j+1]))         //如果后一位不是符号，才指向后一位
                {
                    a[k++] = s + j + 1;
                }

            }
        }
        qsort(a, k, sizeof(char*), compar);
        printf("case #%d:\n", x);
        printf("%s ", a[0]);
        for (i = 1;i < k;i++)
        {
            if (strcmp(a[i], a[i - 1]) != 0)
                printf("%s ", a[i]);
        }
        printf("\n");
    }
    free(a);
    return 0;
}
int isfor(char a)
{
    if (a == ' ' || a == ',' || a == '.' || a == '!' || a == '?'||a==0)
        return 1;
    else
        return 0;
}
int compar(const void* p1, const void* p2)
{
    char* a = *(char**)p1, * b = *(char**)p2;
    if (strcmp(a, b) < 0)
        return -1;
    else
        return 1;
}
