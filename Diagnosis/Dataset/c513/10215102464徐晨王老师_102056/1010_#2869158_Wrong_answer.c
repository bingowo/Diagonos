#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char a[500];
    int i=0;
    char b;
    while(scanf("%c",&b)!=EOF){
        a[i]=b;
        i++;
    }

    printf("%c",a[0]);
    return 0;
}
