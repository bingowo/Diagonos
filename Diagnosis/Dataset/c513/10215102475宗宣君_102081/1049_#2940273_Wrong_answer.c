#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void*a,const void*b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    int T,i;
    scanf("%d\n",&T);
    for(i = 0;i<T;i++)
    {
        char s[501];
        gets(s);
        char a[200][20];
        int j = 0,k = 0,m = 0;
        while(s[j]!='\0')
        {
            if(s[j]==' '||s[j]=='?'||s[j]==','||s[j]=='.'||s[j]=='!') {a[k][m] = '\0';k++;m= 0;}
            else {a[k][m] = s[j];m++;}
            j++;
        }
        qsort(a,k,20,cmp);
        printf("case #%d:\n%s ",i,a[0]);
        for(j = 1;j<k;j++)
            {if(strcmp(a[j],a[j-1])==0);
            else printf("%s ",a[j]);}
        printf("\n");


    }
    return 0;
}
