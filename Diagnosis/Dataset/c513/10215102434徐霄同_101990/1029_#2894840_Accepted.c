#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int cmp(const void *a,const void *b)
{
    if(*(char*)a>*(char*)b)
        return 1;
    return -1;
}
int main()
{
    char s1[201],s2[201];
    int t,i,j,k,l1,l2;
    scanf("%d\n",&t);
    for(i=0;i<t;i++){
        gets(s1);
        l1=strlen(s1);
        l2=0;
        for(j=0;j<l1;j++)
            if(isalpha(s1[j])){
                s2[l2]=s1[j];
                l2++;
            }
        qsort(s2,l2,sizeof(s2[0]),cmp);
        k=0;
        for(j=0;j<l1;j++)
            if(isalpha(s1[j])){
                s1[j]=s2[k];
                k++;
            }
        printf("case #%d:\n",i);
        printf("%s\n",s1);
    }
    return 0;
}
