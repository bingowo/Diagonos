#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define ll long long
#define ull unsigned long long
int min(int a, int b){ return a > b ? b: a; }
int max(int a, int b){ return a < b ? b: a; }
int gcd(int a, int b){ return b ? gcd(b, a % b): a;}


int solve(int t) {
    char ch;
    int cmp=0;
    int cnt=0;
    int j=0;
    char s[10006];
    gets(s);
    int y = strlen(s);
    for (int i = 0; i < y; i++)
    {
        unsigned char ch = (unsigned char)s[i];
        int c = 0;
        while (ch)
        {
            c += (ch & 1);
            ch /= 2;
        }
        cnt += c;
    }
    y *= 8;
    int x = gcd(cnt, y);
    cnt=cnt/x;
    y=y/x;
    printf ("%d/%d\n", cnt,y);
}
int main () {

 int n;
 scanf ("%d", &n);
 getchar();
 int i=0;
 for (;i<n;i++) {
    solve(i);
 }
 return 0;
}

