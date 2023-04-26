#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void itoc(long long int a, char *c){
    int i = 0;a
    while(a > 0){
        c[i] = a % 10 + '0';
        a = a / 10;
        i++;
    }
}


int main()
{
    long long int ori;
    char c[10] = {'\0'};
    int ans = 0;

    scanf("%lld",&ori);

    itoc(ori,c);
    while(atoi(c) != ori){
        ans++;
        ori += atoi(c);
        itoc(ori,c);
    }

    printf("%d %s",ans,c);

    return 0;
}
