#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *p1, const void *p2)
{
    char *a = (char *)p1;
    char *b = (char *)p2;
    return strcmp(a, b); //up
}
int main()
{
    int m;
    scanf("%d", &m);
    getchar();
    for (int i = 0; i < m; i++)
    {
        int j = 0, k = 0;
        char al[501][30]={0};
        char c = getchar();
        while (c != '\n')
        {
            if (c == ' ' || c == ',' || c == '.' || c == '!' || c == '?')
            {
                al[j][k] = '\0';
                j++; //j records number of words
                k = 0;
            }
            else
                al[j][k++] = c;
            c = getchar();
        }
        qsort(al, j, sizeof(al[0]), cmp);        
        printf("case #%d:\n", i);
        k=0;
        while(al[k][0]=='\0')k++;
        printf("%s", al[k++]);
        for (; k < j ; k++)
        {
            if(al[k][0]=='\0')continue;
            if (strcmp(al[k-1],al[k])==0);
            else printf(" %s", al[k]);
            //if (strcmp(al[k],al[k+1])!=0&&al[k+1][0]!='\0')
            //printf(" ");
        }
        printf("\n");
    }
    return 0;
}