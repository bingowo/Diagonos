#include <stdio.h>
#include <string.h>

int main () {

    int n, m, i, sum = 0, time = 1;
    char a[30];
    int b[30];
    int c[30];

    scanf("%d%s\n%d", &n, a, &m);
    for(i = 0; a[i]; i ++ )
        if(isdigit(a[i]))
            b[i] = a[i] - '0';
        if(a[i]>='a'&&a[i]<='z')
            b[i] = (a[i] - 'a') + 10;
        if(a[i]>='A'&&a[i]<='Z')
            b[i] = (a[i] - 'A') + 10;

    int len1 = i;
    for(i = len1 - 1; i >= 0; i -- ) {
        sum += b[i] * time;
        time *= n;
    }

    int len2 = 0;

    while(sum >= 1) {
        c[len2] = sum % m;
        sum /= m;
        len2 ++ ;
    }

    for(int i = len2 - 1; i >= 0; i -- )
        if(c[i] < 10) printf("%d", c[i]);
        else printf("%c", c[i] - 10 + 'A');
    return 0;
}