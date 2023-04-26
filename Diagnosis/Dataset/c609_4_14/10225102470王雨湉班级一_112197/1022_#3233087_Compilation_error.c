#include <stdio.h>
#include <stdlib.h>

int cmp(const void** a, const void** b);
{
        if()
}

int main()
{
        int n;
        scanf("%d",&n);
        char** s;
        s=(char**)malloc(n*sizeof(char*));
        for(int i=0; i<n; i++)
                scanf("%s",&s[i]);
        qsort(s,n,sizeof(s[0]),cmp);
        for(int i=0; i<n; i++)
                printf("%s\n",s[i]);
        free(s);
        return 0;
}
