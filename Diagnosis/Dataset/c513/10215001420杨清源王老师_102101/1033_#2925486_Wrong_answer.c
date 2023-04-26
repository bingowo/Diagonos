#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int val;
    int date;
    int year;
    char month[10];
} maya;

int cmp( const void *a, const void *b)
{
    return  ((maya *)a) -> val -  ((maya *)b) -> val;
}

int month2val( char* m )
{
    int ans;
    char* month[] =
    {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
    for( ans = 0 ; ; ans++)
    {
        if( ! strcmp( m , month[ans] ))
            return ans;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for( int i = 0 ; i < T ; i++)
    {
        int N;
        scanf("%d",&N);
        maya a[N];
        for( int j = 0 ; j < N ; j++)
        {
            scanf("%d.%s %d",&a[j].date,a[j].month,&a[j].year);
            a[j].val = a[j].year * 10000 + month2val(a[j].month) * 100 + a[j].date;
        }

        qsort( a , N , sizeof(maya) , cmp);

        for( int k = 0 ; k < N ; k++)
            printf("%d. %s %d\n",a[k].date,a[k].month,a[k].year);
    }
}

