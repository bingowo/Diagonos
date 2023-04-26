#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char* user, main;
} Address;

int cmp( const void *a, const void *b )
{
    struct Address p1, p2;
    p1 = *((struct Address *)a);
    p2 = *((struct Address *)b);
    int temp = strcmp( p1.main, p2.main);
    return temp ? temp : strcmp( p1.user, p2.user);
}

int main()
{
    long long int n;
    int count, i, j;
    scanf("%lld",&n);

}
