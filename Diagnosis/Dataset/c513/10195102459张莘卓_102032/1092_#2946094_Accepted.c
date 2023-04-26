#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num[1000] = {1};
void plus(int k, int cnt, int* plen) {
    for(int j=0; j<cnt; ++j) {
        int carry = 0;
        for(int i=0; i<*plen; ++i) {
            int t = num[i] * k + carry;
            num[i] = t % 10;
            carry = t / 10;
        }
        if(carry) num[(*plen)++] = carry;
    }
}

int main()
{
    char word[1001];
    scanf("%s",word);
    if(strlen(word) == 1) {
        printf("1\n");
        return 0;
    }
    int c2 = 0, c3 = 0;
    for(int i=0; word[i]; ++i) {
        if(i == 0){
            if(word[1]!=word[0]) ++c2;
        }else if(word[i+1] == '\0') {
            if(word[i-1]!=word[i]) ++c2;
        }else {
            if(word[i+1]!=word[i] && word[i-1]!=word[i] && word[i-1]!= word[i+1]) ++c3;
            else if(word[i+1]!=word[i] || word[i-1]!=word[i]) ++c2;
        }
    }
    int len = 1;
    plus(2, c2, &len);
    plus(3, c3, &len);
    for(int i=len-1; i>=0; --i) printf("%d",num[i]);
    printf("\n");
    return 0;
}
