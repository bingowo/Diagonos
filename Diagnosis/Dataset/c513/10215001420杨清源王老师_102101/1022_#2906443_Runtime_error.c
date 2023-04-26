#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char get_name( char *s)
{
    while( *s != '@')
        s++;
    return s+1;
}

int cmp( const void *a, const void *b )
{
    char *p1 = *(char *)a;
    char *p2 = *(char *)b;
    int temp = strcmp( get_name(*p1), get_name(*p2) );
    return temp ? temp : strcmp( p2, p1 );
}

int main()
{
    int n;
    scanf("%d",&n);
    char str[1000][1000];
    int count = 0, i;
    while(scanf("%s",str[count]) != EOF)
        count++;
    qsort(str,count,sizeof(str[0]),cmp);
    for( i = 0 ; i < count ; i++)
        printf("%s\n",str[i]);
}
