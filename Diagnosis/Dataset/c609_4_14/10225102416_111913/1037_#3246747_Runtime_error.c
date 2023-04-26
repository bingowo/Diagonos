#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    char *s = (char *)malloc(10e6*sizeof(char));
    scanf("%s",&s);
    if(strlen(s)==1){
        printf("%s",s);
    }
    return 0;
}
