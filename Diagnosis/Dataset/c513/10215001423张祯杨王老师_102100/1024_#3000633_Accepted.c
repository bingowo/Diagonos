#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int score;
    char id[20];
} Student;

int cmp( const void *a, const void *b )
{
    Student *p1 = (Student *)a;
    Student *p2 = (Student *)b;
    int temp;
    temp = p2 -> score - p1 -> score;
    if( temp != 0 )
        return temp;
    temp = strcmp( p1 -> id, p2 -> id );
    return temp;
}

int main()
{
    int t, i, j, k;
    scanf("%d",&t);
    for( i = 0 ; i < t ; i++ )
    {
        int n, m, g;
       
        scanf("%d%d%d",&n,&m,&g);
        int point[m];
        for( j = 0 ; j < m ; j++)
            scanf("%d",&point[j]);
            
        Student stu[n];
        
        for( j = 0 ; j < n ; j++)
        {
            stu[j].score = 0;
            int num_solve;
            scanf("%s%d",stu[j].id,&num_solve);
            for( k = 0 ; k < num_solve ; k++)
            {
                int temp;
                scanf("%d",&temp);
                stu[j].score += point[temp-1];
            }
        }

        qsort(stu,n,sizeof(Student),cmp);

        int pass = 0;
        for( j = 0 ; j < n ; j++)
        {
            if( stu[j].score >= g )
                pass++;
        }

        printf("case #%d:\n",i);
        printf("%d\n",pass);


        for (j = 0; j < pass; j++)
            printf("%s %d\n", stu[j].id, stu[j].score);
    }
}
