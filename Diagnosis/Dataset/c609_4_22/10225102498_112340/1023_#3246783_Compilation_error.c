#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int year;
    char month[6];
    int day;
}date;

int main()
{
    int T, N, i, j;
    scanf("%d", &T);
    for(i=0; i<T; i++)
    {
        scanf("%d", &N);
        date cal[N];
        char[19][6] = {"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen"};
        for(j=0; j<N; j++)
        {
            scanf("%d", &cal[j].day);
            scanf("%s", &cal[j].month);
            scanf("%d", &cal[j].year);
        }

        
        











        printf("case #%d:\n", T);



    }

    return 0;
}
