#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a, const void *b){
    return strcmp((char *)b, (char *)a);
}
int main()
{
    int n;
    scanf("%d", &n);
    char a[n][200];
    int i;
    for (i = 0; i < n; i++)
        scanf("%s",a[i]);
    
    qsort(a, n, sizeof(a[0]), cmp);

    for (i = 0; i < n; i++)
        printf("%s\n", a[i]);

    return 0;
}