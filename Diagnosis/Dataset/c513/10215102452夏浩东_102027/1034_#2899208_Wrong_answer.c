#include <stdio.h>
#include <stdlib.h>
#include <string.h>
double L[26]={0.0};
int cmp(const void *a,const void *b)
{
    char *A=(char*)a;
    char *B=(char*)b;
    int NA=0,NB=0;
    if(*A<='Z') NA=*A-'A';
    else NA=*A-'a';
    if(*B<='Z') NB=*B-'A';
    else NB=*B-'a';
    if(L[NA]>L[NB]) return -2;
    else if(L[NA]>L[NB]) return 1;
    else return (int)(*A-*B);
}
int main()
{
    int cnt=0;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++)
    {
        char s[101];
        for(int k=0;k<26;k++)
        {
            scanf("%lf",&L[k]);
        }
        scanf("%s",s);
        qsort(s,strlen(s),sizeof(char),cmp);
        printf("case %d:\n",i);
        for(int k=0;k<strlen(s);k++)
        {
            printf("%c",s[k]);
        }
        printf("\n");
    }
    return 0;
}