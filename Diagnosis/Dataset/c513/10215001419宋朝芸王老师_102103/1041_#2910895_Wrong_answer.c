#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[51] = {'\0'};
    scanf("%s",a);

    int len = strlen(a);
    int ans = 1, i = 0, temp = 1;
    char flag = a[0];

    while(i < len){
        while(a[i] == flag) {
            i++;
            ans = ans > temp ? ans : temp;
        }
        temp = 1;
        while(a[i] != flag){
            flag = a[i];
            i++;
            temp++;
        }
    }

    printf("%d",ans);


    return 0;
}
