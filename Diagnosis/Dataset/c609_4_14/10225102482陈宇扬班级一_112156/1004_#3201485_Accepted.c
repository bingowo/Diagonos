#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char* convert(char* num, int from_base, int to_base) {
  // 检查输入是否合法
  if (num == NULL || from_base < 2 || from_base > 36 || to_base < 2 || to_base > 36)
  {
    return NULL;
  }

  char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char* result = (char*)malloc(33 * sizeof(char)); //最多32位加上结束符'\0'
  result[0] = '\0'; // 初始化结果为空字符串

  int r;  //余数
  long long quotient = strtoll(num, NULL, from_base);

  if (quotient == 0)
  {
    strcpy(result, "0");
    return result;
  }

  while (quotient > 0)
  {
    r = quotient % to_base; // 计算余数
    quotient /= to_base; // 计算商

    memmove(result + 1, result, strlen(result) + 1);
    result[0] = digits[r];
   }

   return result;
}

int main() {

   char num[33];
   int from_base;
   int to_base;

   scanf("%d", &from_base);
   scanf("%s", num);
   scanf("%d", &to_base);

   char* result = convert(num, from_base, to_base);

   if (result == NULL)
   {
     printf("输入不合法！\n");
     return -1;
   }
   printf("%s\n", result);
   free(result);
   return 0;
}
