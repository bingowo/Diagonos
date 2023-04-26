#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    void comb(char* S,char* char_comb)
{
    if (S[0])
    {
        char left[17]={0};
        sprintf(left,"%s%c",char_comb,S[0]);
        printf("%s\n",left);
        comb(S+1,left);
        comb(S+1,char_comb);
    }
}
    int cmp(const void*a,const void *b)
    {
        char *a1=(char*)a,*b1=(char*)b;
        return *a1-*b1;
    }
    int T;
    scanf ("%d",&T);
    for (int i=0;i<T;i++)
    {
        char S[17],char_comb[17]="";
        scanf("%s",S);
        int len=strlen(S);
        qsort (S,len,sizeof(S[0]),cmp);
        printf("case #%d:\n",i);
        comb(S,char_comb);
    }
    return 0;
}
