#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

double table[26] = {0};

int cmp(const void * a,const void *b)
{
    char x,y;
    x = *((char *)a);
    y = *((char *)b);
    if(toupper(x)==toupper(y)){
        return y-x;
    }
    else{
        if(table[toupper(x)-'A']>table[toupper(y)-'A'])return -1;
        else
            return 1;
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        printf("case #%d:\n",t);
        for(int i=0;i<26;i++){
            scanf("%lf",&table[i]);
        }
        char str[102];
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp);
        printf("%s\n",str);
    }
    return 0;
}
