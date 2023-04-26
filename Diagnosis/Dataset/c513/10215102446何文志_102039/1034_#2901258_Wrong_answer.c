#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Mychar
{
    double f;
    int index;
    char c;
}mychar;

int cmp1(const void *a,const void *b)
{
    mychar A = *(mychar*)a, B = *(mychar*)b;
    return A.f>B.f;
}

int cmp2(const void *a,const void *b)
{
    mychar A = *(mychar*)a,B = *(mychar*)b;
    return B.index-A.index;
}

int getIndex(char c, char table[])
{
    int len =strlen(table);
    for(int i = 0;i<len;i++)
    {
        if(c == table[i]){return i+1;}
    }
    return 0;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        mychar alpha[26];memset(alpha,0,26*sizeof(mychar));
        char temp = 'a';
        for(int j = 0;j<26;j++)
        {
            scanf("%lf",&alpha[j].f);
            alpha[j].c = temp;
            //printf("%c ",alpha[j].c);
            temp++;
        }
        //printf("\n");
        qsort(alpha,26,sizeof(alpha[0]),cmp1);
        char table[60];memset(table,0,60*sizeof(char));
        int cnt = 0;
        for(int j = 0;j<52;j+=2)
        {
            table[j] = alpha[cnt].c;
            table[j+1] = alpha[cnt].c-32;
            //printf("%c %c ",table[j],table[j+1]);
            cnt++;
        }
        char s[101];memset(s,0,101*sizeof(char));
        scanf("%s",s);
        int len = strlen(s);
        mychar res[len];memset(res,0,len*sizeof(mychar));
        for(int j = 0;j<len;j++)
        {
            res[j].c = s[j];
            res[j].index = getIndex(res[j].c,table);
        }
        qsort(res,len,sizeof(res[0]),cmp2);
        printf("case #%d:\n",i);
        for(int j = 0;j<len;j++)
        {
            printf("%c",res[j].c);
        }
        printf("\n");
        //printf("%s",table);
    }
    return 0;
}
