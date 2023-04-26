#include <stdio.h>
int main(void) {
int t;
scanf("%d", &t);
for(int i = 0 ; i < t; i ++){
int n, cnt = 0;
scanf("%d", &n);
for(int w = 0; w <= n / 4; w ++){
for(int x = 0 ; x <= n / 3; x ++){
for(int y = 0 ;y <= n /2; y ++){
if(4 * w + 3 * x + 2 * y <= n){
cnt ++;
} } } }
printf("%d\n", cnt);
}
return 0; }

/*#include <stdio.h>
int main(void) {
int dp[1001] = {1, };
for(int i = 1; i <= 4; i ++){
for(int j = i; j <= 1000; j ++){
dp[j] += dp[j - i];
} }
int t;
scanf("%d", &t);
for(int i = 0 ; i < t; i ++){
int n;
scanf("%d", &n);
printf("%d\n", dp[n]);
}
编程思维与实践-07.md 2022/4/3
19 / 30
return 0; }*/