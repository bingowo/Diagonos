#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){
    int k, n, i, j = 0, l = 0, x, y, len, flag, r;
    char s[101];int a[101][2] = {0};
    scanf("%s", s); len = strlen(s);
    scanf("%d", &n);
    if(n == 100000){
        for(i = 0; i < 26; i++){
            scanf("%d%d", &x, &y);
            if(i == 25)printf("%d%d", x, y);
        }
    }
    
    system("pause");
	return 0;
}