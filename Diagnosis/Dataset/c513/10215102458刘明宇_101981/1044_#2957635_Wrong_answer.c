#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char *s = (char*)malloc(10001*sizeof(char));
    scanf("%s",s);
    printf("%s",s);
}
