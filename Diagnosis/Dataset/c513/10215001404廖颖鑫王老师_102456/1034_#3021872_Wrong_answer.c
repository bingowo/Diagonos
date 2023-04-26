#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
  float number;
  char letter;
}LETTER;

int cmp(const void *a,const void *b)
{
    LETTER *x=(LETTER*)a;
    LETTER *y=(LETTER*)b;
    if(x->number!=y->number)
        return (x->number-y->number);
    else
    {
        if(abs(x->letter-y->letter)==32)
            return (x->letter-y->letter);//如果对应频率相同，则小写字母在前
        else
            {if(toupper(x->letter)!=toupper(y->letter))
            return (toupper(x->letter)-toupper(y->letter));}
    }
        
}

int main()
{
    int T,i,j,k,N;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        float a[26];
        for(j=0;j<26;j++)
        {scanf("%f",&a[j]);}
        char str[100];scanf("%s",str);
        N=strlen(str);
        LETTER let[100];
        for(j=0;j<N;j++)
        {
          let[j].letter=str[j];
            if(let[j].letter<'a')
            let[j].number=a[let[j].letter-'A'];//令频率和字母对应起来
                else
                let[j].number=a[let[j].letter-'a'];
        }
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
