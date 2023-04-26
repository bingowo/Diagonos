#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *a){
    int len = strlen(a);
    for(int i = 0; i < len/2; i++){
        char temp = a[i];
        a[i] = a[len-i-1];
        a[len-i-1] = temp;
    }
}

/*void itoc(long long int a, char *c){
    int i = 0;
    while(a > 0){
        c[i] = a % 10;
        a = a / 10;
        i++;
    }
}*/


int main()
{
    long long int ori;
    char c[10] = {'\0'};
    int ans = 0;

    scanf("%lld",&ori);

    itoa(ori,c,10);
    reverse(c);
    while(atoi(c) != ori){
        ans++;
        ori += atoi(c);
        itoa(ori,c,10);
        reverse(c);
    }

    printf("%d %s",ans,c);

    return 0;
}
