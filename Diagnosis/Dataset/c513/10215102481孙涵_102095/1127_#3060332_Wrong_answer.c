#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gcd(int a, int b);
int lcm(int a, int b);

struct data{
    int up;
    int down;
};

int main()
{
    int n;
    scanf("%d",&n);
    struct data s[100];
    for(int i = 0; i < n; i++){
        char str[500];
        char above[500];
        char below[500];
        scanf("%s",str);
        int j = 0;
        while(str[j] != '/'){
            j++;
        }
        strncpy(above,str,j+1);
        strcpy(below,(str + j + 1));
        s[i].up = atoi(above);
        s[i].down = atoi(below);
    }
    struct data ans;
    int r = lcm(s[0].down, s[1].down);
    ans.down = r;
    ans.up = ( r / s[0].down ) * s[0].up + ( r / s[1].down ) * s[1].up;
    for(int i = 2; i < n; i++){
        r = lcm(ans.down, s[i].down);
        ans.down = r;
        ans.up = (r / ans.down) * ans.up + (r / s[i].down) * s[i].up;
    }
    int k = gcd(ans.up, ans.down);
    printf("%d/%d",ans.up/k, ans.down/k);
    return 0;
}

int gcd(int a, int b){
    // a / b = c ...... d
    int c, d;
    c = a / b;
    d = a % b;
    while(d != 0){
        a = b;
        b = d;
        c = a / b;
        d = a % b;
    }
    return b;
}


int lcm(int a, int b){
    int gcdab;
    gcdab = gcd(a,b);
    return a * b / gcdab;
}
