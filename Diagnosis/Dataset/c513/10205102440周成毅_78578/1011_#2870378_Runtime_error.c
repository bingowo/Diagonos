#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

struct image {
    long long real;
    long long fake;
};

struct image multi(struct image a, struct image b) {
    struct image result;
    result.real = a.real * b.real - a.fake * b.fake;
    result.fake = a.real * b.fake + a.fake * b.real;
    return result;
}

struct image plus(struct image a, int b) {
    a.real += b;
    return a;
}

void fun10_2(int result[], long long sum) {
    int i = 0;
    while (sum) {
        result[i++] = sum % 2;
        sum /= 2;
    }
}

void fun16_2(char *s, int len, int result[]) {
    long long sum = 0, cet = 0;
    for (; len > 2; len--) {
        if (isdigit(s[len - 1])) {
            sum += (s[len - 1] - '0') * pow(16, cet);
        } else {
            sum += (s[len - 1] - 'A' + 10) * pow(16, cet);
        }
        cet++;
    }
    fun10_2(result, sum);
}

int main() {
    char s[65];
    int result[100];
    for (int i = 63; i >= 0; i--)
        result[i] = 0;
    scanf("%s", s);
    int len = strlen(s);
    fun16_2(s, len, result);
    struct image p = {0, 0};
    struct image bit = {-1, 1};
    int right=63;
    while(result[right]==0) right--;
    for(;right>=0;right--){
        p= plus(multi(p,bit),result[right]);
    }
    if(p.real==0 && p.fake==0)
        printf("0\n");
    else if(p.real==0 && p.fake!=0)
        printf("%lldi\n",p.fake);
    else if(p.real!=0 && p.fake==0)
        printf("%lld\n",p.real);
    else if(p.real!=0 && p.fake>1)
        printf("%lld+%lldi\n",p.real,p.fake);
    else if(p.real!=0 && p.fake==1)
        printf("%lld+i\n",p.real,p.fake);
    else if(p.real!=0 && p.fake==-1)
        printf("%lld-i\n",p.real,p.fake);
    else if(p.real==0 && p.fake==-1)
        printf("-i\n",p.real,p.fake);
    else if(p.real==0 && p.fake==1)
        printf("i\n",p.real,p.fake);
    else
        printf("%lld%lldi\n",p.real,p.fake);
    return 0;
}
