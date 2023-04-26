#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void*a,const void*b)
{
    char ia=*(char *)a,ib=*(char *)b;
    return ia-ib;
}
int main()
{
    int t;
    scanf("%d",&t);
    getchar();
    for(int i=0;i<t;i++)
    {
        char s[250]={'0'};
        gets(s);
        printf("case #%d:\n",i);
        int len=strlen(s);
        char *A=(char* ) malloc(len*sizeof(char));
        int k=0;
        for(int j=0;j<len;j++)
        {
            if(isalpha(s[j])) {A[k]=s[j],k++;}
        }
        qsort(A,k,sizeof(char),cmp);
        for(int j=0,p=0;j<len;j++)
        {
            if(isalpha(s[j])) {s[j]=A[p],p++;}
        }
        printf("%s\n",s);
        free(A);
    }
    return 0;
}
