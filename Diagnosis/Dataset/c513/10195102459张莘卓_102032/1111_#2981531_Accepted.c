#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char a[41][41];
void set(void) {
    for(int i=0; i<41; ++i) {
        if(i == 20) ++i;
        for(int j=0; j<41; ++j) a[i][j] = '.';
        a[i][20] = '|';
    }
    for(int j=0; j<40; ++j) a[20][j] = '-';
    a[20][20] = '+'; a[0][20] = '^';  a[20][40] = '>';
}

long long* catch(char* s) {
    int i = 0;
    long long *k = (long long *) malloc(4*sizeof(long long));
    k[0] = k[1] = k[2] = k[3] = 0;
    while(s[i]) {
        int flag = 1;
        if(s[i]=='+' || s[i]=='-') {
            if(s[i] == '-') flag = -1;
            ++i;
        }
        long long sum = 0;
        if(! isdigit(s[i])) sum = 1;
        else for(; isdigit(s[i]); ++i) sum = sum*10 + s[i] - '0';
        sum *= flag;
        if(s[i] != 'x') k[0] = sum;
        else if(s[i+1] != '^'){
            k[1] = sum;  ++i;
        }else{
            k[s[i+2]-'0'] = sum;  i += 3;
        }
    }
    return k;
}

int main()
{
    char s[60];
    while(scanf("%s",s) != EOF) {
        set();
        long long* k = catch(s+5), y;
        for(int x=1; x<=20; ++x) {
            y = k[0] + k[1]*x + k[2]*x*x + k[3]*x*x*x;
            if(y>=-20 && y<=20) a[20-y][20+x] = '*';
            else break;
        }
        for(int x=0; x>=-20; --x) {
            y = k[0] + k[1]*x + k[2]*x*x + k[3]*x*x*x;
            if(y>=-20 && y<=20) a[20-y][20+x] = '*';
            else break;
        }
        for(int i=0; i<41; ++i) {
            for(int j=0; j<41; ++j) printf("%c",a[i][j]);
            printf("\n");
        }
        printf("\n");
        free(k);
    }
    return 0;
}
