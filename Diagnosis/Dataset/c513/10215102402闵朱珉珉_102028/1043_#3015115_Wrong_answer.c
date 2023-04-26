#include <stdio.h>
#include <string.h>

int erase(char *str) {
  char *p = str;
  while (*str) {
    if (str[1] == str[0]) {
      while (str[1] == str[0]) ++str;
    } else {
      *p = *str;
      ++p;
    }
    ++str;
  }
  *p = '\0';
  return str - p;
}

int main() {
  char str[102], nstr[102];
  int T;
  scanf("%d", &T);
  while (T--) {
    printf("case #%d:\n", T);
    scanf("%s", str);
    int len = strlen(str);
    int ans = 0;
    char abc[] = "ABC";
    for (int i = 0; i < len; ++i) {
      for (int k = 0; k < 3; ++k) {
        for (int j = 0; j < i; ++j) nstr[j] = str[j];
        nstr[i] = abc[k];
        for (int j = i; j < len; ++j) nstr[j + 1] = str[j];
        nstr[len + 1] = '\0';
        int nans = 0;
        for (int temp = erase(nstr); temp; temp = erase(nstr)) nans += temp;
        ans = nans > ans ? nans : ans;
      }
    }
    printf("%d\n", ans);
  }
}