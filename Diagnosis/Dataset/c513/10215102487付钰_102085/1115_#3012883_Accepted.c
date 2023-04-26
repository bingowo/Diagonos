#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *a, const void *b){ return *(int *)a - *(int *)b;}
int main(void)
{
int t;
scanf("%d", &t);
for(int i = 0 ; i < t; i ++){
int n[30] = {0};
char s[30];
scanf("%s", s);
int len = strlen(s);
for(int i = 0 ; i < len; i ++){
n[i + 1] = s[i] - '0';
}
int ps1/*最you侧极小值you边的次小值*/, p1/*最you侧极小值下标*/;
for(int i = len - 1 ; i >= 0 ; i --){
if(n[i] < n[i + 1]){
p1 = i;
break;
}
}
ps1 = p1 + 1;
for(int i = len; i >= p1; i --){
if(n[i] > n[p1] && n[i] <= n[ps1]){
ps1 = i;
}
}
int temp;
temp = n[ps1];
n[ps1] = n[p1];
n[p1] = temp;
qsort(n + p1 + 1, len - p1, sizeof(int), cmp);
int idx = 0;
printf("case #%d:\n", i);
if(n[idx] == 0){ idx ++;}
for(; idx < len + 1; idx ++){
printf("%d", n[idx]);
}
printf("\n");
}
return 0;
}
