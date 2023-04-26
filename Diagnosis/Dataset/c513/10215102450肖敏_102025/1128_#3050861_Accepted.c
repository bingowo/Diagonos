#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[101][301];

int cmp(const void*a, const void *b){
    char *a1=*(char (*)[301])a;
    char *b1=*(char (*)[301])b;
    if(a1[4]!=b1[4])
        return a1[4]-b1[4];
    else
        return strcmp(a1,b1);
}

int main() {
    int n;
    int num=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s",s[i]);
        if(s[i][4]==':')
            num++;
    }
    qsort(s,n,sizeof (s[0]),cmp);
    for(int i=0;i<num;i++)
        printf("%s\n",s[i]);
    return 0;
}
