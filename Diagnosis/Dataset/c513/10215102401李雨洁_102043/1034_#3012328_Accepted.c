#include <stdio.h>
#include <stdlib.h>

struct alpha
{
    double fre;
    char letter;
    int ord;
};
struct alpha A[52];
int cmp(const void *_a,const void *_b)
{
    struct alpha a,b;
    a = *((struct alpha *)_a);
    b = *((struct alpha *)_b);
    if(a.fre == b.fre)
    {
        return(a.ord - b.ord);
    }
    else if(a.fre > b.fre)
        return -1;
    else
        return 1;
}

int scmp(const void *_a,const void *_b)
{
    char a = *((char *)_a);
    char b = *((char *)_b);
    int aloc, bloc;
    for(int i = 0; i < 52; i++)
    {
        if(a == A[i].letter)
        aloc = i;
        if(b == A[i].letter)
        bloc = i;
    }
    return aloc - bloc;
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0; i < T; i++)
    {
        for(int j = 0; j < 52; j+=2)
        {
            double temp;
            scanf("%lf",&temp);
            A[j].fre = A[j + 1].fre = temp;
            A[j].letter = j / 2 + 'a';
            A[j].ord = j;
            A[j + 1].ord = j + 1;
            A[j + 1].letter =  j / 2 + 'A';

        }
        qsort(A,52,sizeof(A[0]),cmp);
        getchar();
        char str[200] = {0};
        int len = 0;
        char c = getchar();
        while(c != '\n')
        {
            str[len++] = c;
            c = getchar();
        }
        qsort(str,len,sizeof(str[0]),scmp);
        printf("case #%d:\n",i);
        printf("%s\n",str);
    }
    return 0;
}



