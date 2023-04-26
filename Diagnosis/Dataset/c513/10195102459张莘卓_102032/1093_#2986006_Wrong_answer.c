#include <stdio.h>
#include <string.h>

void catch(int* num, int* p) {
    char s[101];
    scanf("%s",s);
    int len = strlen(s);
    for(*p=0; *p<len; ++(*p))
        num[*p] = s[len-1-*p] - '0';
}

void plus1(int* num, int* p) {
    int i = 0, carry = 1;
    while(carry && i<*p) {
        num[i] += carry;
        carry = num[i] / 9;
        num[i++] %= 9;
    }
    if(carry) num[(*p)++] = carry;
}

int islegal(int* num, int cnt) {
    int sum = 0;
    for(int i=0; i<cnt; ++i)
        sum += num[i];
    return sum % 9;
}

int main()
{
    int num[110] = {0}, cnt = 0;
    catch(num, &cnt);
    do{
        plus1(num, &cnt);
    }while(! islegal(num, cnt));
    for(int i=cnt-1; i>=0; --i) printf("%d",num[i]);
    printf("\n");
    return 0;
}
