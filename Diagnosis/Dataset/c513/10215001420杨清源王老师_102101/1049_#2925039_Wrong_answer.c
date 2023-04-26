#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp( const void *a, const void *b)
{
    return strcmp( (char *)a, (char *)b );
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    for( int temp = 0 ; temp < T ; temp++)
    {
        char text[600], word[600][50];
        scanf("%s",text);
        int i = 0, j = 0, k = 0;
        for( ; i < strlen(text) ; i++)
        {
            if( text[i] >= 'a' && text[i] <= 'z')
            {
                word[j][k] = text[i];
                k++;
            }
            else
            {
                j++;
                k = 0;
            }
        }
        printf("case #%d:\n",temp);

        qsort( word, j, sizeof(word[0]), cmp );

        printf("%s",word[0]);
        for( i = 1 ; i < j ; i++)
        {
            if(strcmp( word[ i ] , word[ i-1 ] ) !=0 )
                printf(" %s", word[ i ] );
        }
        printf("\n");
    }

    return 0;
}
