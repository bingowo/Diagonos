#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decode(char* s, char end, long long* p1, long long* p2) {
    int i=0;
    long long k1 = 0, k2 = 0;
    while(s[i] != end) {
        int flag = 1;
        if(s[i]=='+' || s[i]=='-') {
            if(s[i] == '-') flag = -1;
            ++i;
        }
        long long k = 0;
        if(isalpha(s[i])) k = 1;
        else for(; isdigit(s[i]); ++i)
            k = k*10 + s[i] - '0';
        if(isalpha(s[i])) {
            k1 += k * flag;
            ++i;
        }else k2 += k * flag;
    }
    *p1 = k1;  *p2 = k2;
}

int main()
{
    char s[81];
    scanf("%s",s);
    long long k1, k2, k3, k4;
    decode(s, '=', &k1, &k2);
    decode(strchr(s, '=')+1, '\0', &k3, &k4);
    for(int i=0; s[i]; ++i)
        if(isalpha(s[i])) {
            printf("%c=%.3f\n",s[i],1.0*(k4-k2)/(k1-k3));
            break;
        }
    return 0;
}
