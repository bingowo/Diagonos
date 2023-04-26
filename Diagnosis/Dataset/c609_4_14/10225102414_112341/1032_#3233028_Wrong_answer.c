#include <stdio.h>
#include <string.h>

int main()
{
    char I[51];
    int i, lnow = 1, lres = 0;
    scanf("%s", I);
    for (i = 0;i < strlen(I) - 1;i++){
        if(I[i] != I[i + 1]){
            lnow += 1;
        }else{
            lnow = 1;
        }
        if (lnow > lres){
            lres = lnow;
        }
    }
    printf("%d", lres);
    return 0;
}