// ACMTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//注释的printf都是debug用的 你以后自己debug也是用 可以用printf检查阶段性输出 输入一个简单的例子 看看到哪一步才出的错
int number(char* s) {
 int cnt = 0;
 char flag[26] = { 0 };//26个字母
 while (*s!='\0') {//判断条件
     // printf("%c:%d", s,*s);
   if (flag[*s - 'A'] == 0) {
    cnt++;
    flag[*s - 'A'] = 1;//=
   }s++;
  }
 return cnt;
}
int cmp(const void* a, const void* b) {
 int s1, s2;
 char* str1, * str2;
 str1 = (char*)a;
 str2 = (char*)b;
 s1 = number(str1);
 s2 = number(str2);
 //printf("%s:%d:\n", str1,s1);
 //printf("%s:%d:\n", str2, s2);
 if (s1 == s2) return strcmp(str1, str2);
 if (s1 > s2) return -1;
 if (s1 < s2) return 1;

}
int main(int argc, char* argv[]) {
 int n, m, k;
 char s[100][20];
 scanf("%d", &n);//scanf去掉\n
 for (k = 0; k < n; k++) {
  scanf("%d", &m);
  for (int i = 0; i < m; i++) {
   scanf("%s", s[i]);
  }
  qsort(s, m, sizeof(s[0]), cmp);
  printf("case #%d:\n", k);
  for (int i = 0; i < m; i++)
   printf("%s\n", s[i]);
 }
 return 0;
}

