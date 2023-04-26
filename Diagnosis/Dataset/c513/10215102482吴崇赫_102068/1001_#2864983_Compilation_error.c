#include<stdio.h>
#include<string.h>
char Tra(int n) {
    char ret;
    if (n < 10)ret = n + '0';
    else ret = n - 10 + 'A';
    return ret;
}
void reverse(char* s) {
    int i, j;char temp;
    for (i = 0, j = strlen(s) - 1;i < j;++i, --j) {
        temp = s[i];s[i] = s[j];s[j] = temp;
    }
}
void Transform(int n, int r) {
    char ret[100]={'\0'};
    int i = 0;
    int sign = 1;
    if (n < 0) { sign = -1;n = -n; }
    while (n) {
        ret[i++] = Tra(n % r);
        n /= r;
    }
    if (sign == -1)ret[i++] = '-';
    reverse(ret);
    cout << ret << endl;
}
int main() {
    int T,n,r;
    cin >> T;
    while (T--)
    {
        scanf("%d %d".&n,&r);
        Transform(n, r);
    }
    return 0;
}