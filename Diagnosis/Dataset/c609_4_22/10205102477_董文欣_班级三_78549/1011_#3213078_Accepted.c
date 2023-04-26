#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long long int gcd(long long int a, long long int b) {return a ? gcd(b % a, a) : b;}

int main()
{
    long long ansA = 0, ansB = 0, ansC = 1;//整数;分子;分母
    unsigned int i = 0;
    char s[31];
    scanf("%s",s);
    int len = strlen(s);
    while (i < len) {
        if (s[i] == '.') break;
        ansA *= 3;
        if (s[i] == '1') ansA += 1;
        if (s[i] == '2') ansA -= 1;
        i++;
    }
    i++;
    while (i < len) {
        ansB *= 3;
        if (s[i] == '1') ansB += 1;
        if (s[i] == '2') ansB -= 1;
        ansC *= 3;
        i++;
    }
    long long int tmp = gcd(abs(ansB), abs(ansC));
    if (ansA > 0 && ansB < 0) {ansA--; ansB = ansC + ansB;}
    if (ansA < 0 && ansB > 0) {ansA++; ansB = ansC - ansB;}

    if (ansB == 0) printf("%lld\n",ansA);
    else {
        if (ansA != 0) printf("%lld ", ansA);
        printf("%lld %lld\n", ansB/tmp, ansC/tmp);
    }
    return 0;
}
