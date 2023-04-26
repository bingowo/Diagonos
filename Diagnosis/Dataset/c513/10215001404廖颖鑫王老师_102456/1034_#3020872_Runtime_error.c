#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  int number;
  char letter;
}LETTER;

int cmp(const void *a,const void *b)
{
    LETTER *x=(LETTER*)a;
    LETTER *y=(LETTER*)b;
    if(x->number!=y->number)
        return (x->number-y->number);
    else
        return ('x->letter'-'y->letter');
}

int main()
{
    int T,i,j,k,N;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        int a[26]={8.19,1.47,3.83,3.91,2.25,2.26,1.71,4.57,7.10,0.14,0.41,3.77,3.34,7.06,7.26,2.89,0.09,6.85,6.36,9.41,2.58,1.09,1.59,0.21,1.58,0.08};
        LETTER let[100];
        for(j=0;scanf("%c",let[j].letter)!=EOF;j++)
        {
            if(let[j].letter<'a')
            let[j].number=a[let[j].letter-'A'];
                else
                let[j].number=a[let[j].letter-'a'];
        }
        N=j;
        qsort(let,N,sizeof(LETTER),cmp);
        printf("case #%d:\n",i);
        for(k=0;k<N-1;k++)
        {
            printf("%c",let[k].letter);
        }
        printf("%c\n",let[k].letter);

    }
    return 0;
}