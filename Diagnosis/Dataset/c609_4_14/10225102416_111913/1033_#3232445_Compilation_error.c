#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int char2int(char *p);
char int2base(int a);
int main()
{
    int T,i,m;
    char a[T][101];
    scanf("%d",&T);
    for(i=0;i<T;i++){
        char b[404];
        scanf("%s",&a[i]);
        printf("case #%d:\n",i);
        m = char2int(a[i]);
        strcpy(b,int2base(m));
        printf("%s\n",b[i]);
    }
    return 0;
}


