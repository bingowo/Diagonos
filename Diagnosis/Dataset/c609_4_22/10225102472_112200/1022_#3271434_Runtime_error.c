#include <stdio.h>
#include <string.h>

typedef struct
{
    char user[100];
    char domain[100];
} Email;

void myPrint(Email e)
{
    printf("%s", e.user);
    printf("@");
    printf("%s", e.domain);
    printf("\n");
}

int cmp(const void *a, const void *b)
{
    Email *A = (Email*)a;
    Email *B = (Email*)b;
    Email tempA = *A;
    Email tempB = *B;

    int flag1 = strcmp(tempA.domain, tempB.domain);

    if(!flag1)
    {
        int flag2 = strcmp(tempA.user, tempB.user);

        if (flag2 > 0) return -1;
        else return 1;
    }

    if(flag1 > 0)  return 1;

    else  return -1;

}

int main()
{
    int n;
    scanf("%d", &n);
    Email *es = (Email*)malloc(sizeof(Email)*(n+1));
    getchar();

    for(int i = 0; i < n; i++)
    {
        char ch;
        for(int j=0; (ch=getchar()) != '@'; j++)
        {
            es[i].user[j] = ch;
            es[i].user[j+1] = '\0';
        }

        for(int j=0; (ch=getchar()) != '\n'; j++)
        {
            es[i].domain[j] = ch;
            es[i].domain[j+1] = '\0';
        }
    }

    qsort(es, n, sizeof(Email), cmp);

    for(int i=0; i<n; i++)
    {
        myPrint(es[i]);
    }

    free(es);

    return 0;
}