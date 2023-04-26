#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[51] = {'\0'};
    scanf("%s",a);

    int len = strlen(a);
    int ans = 0, i = 1, temp = 0;
    char flag = a[0];

    if(len == 1){
        printf("1");
        return 0;
    }

    while(i < len){
        while(a[i] == flag) {
            i++;
        }
        temp = 1;
        while(i < len && a[i] != flag){
            flag = a[i];
            i++;
            temp++;
        }
        ans = ans > temp ? ans : temp;
    }

    printf("%d",ans);


    return 0;
}
