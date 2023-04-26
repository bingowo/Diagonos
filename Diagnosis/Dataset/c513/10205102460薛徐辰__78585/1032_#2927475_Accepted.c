#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b) {
int* na = (int*)a;
int* nb = (int*)b;
for (int i = 0; ; i++) {
if (na[i] == -1 && nb[i] == -1) return 0;
if (na[i] == -1) return 1;
if (nb[i] == -1) return -1;
if (na[i] == nb[i]) continue;
return nb[i] - na[i];
}
}

void solve() {
int N, n[1000][51];
scanf("%d", &N);
for (int i = 0; i < N; i++) {
int len = 0, a;
while (1) {
scanf("%d", &a);
n[i][len++] = a;
if (a == -1) break;
}
}
qsort(n, N, sizeof(n[0]), cmp);
for (int i = 0; i < N; i++) {
int j = 0, a;
while (1) {
a = n[i][j++];
if (a == -1) break;
printf("%d ", a);
}
printf("\n");
}
}

int main() {
int T;
scanf("%d", &T);
while (T--) solve();
return 0;
}