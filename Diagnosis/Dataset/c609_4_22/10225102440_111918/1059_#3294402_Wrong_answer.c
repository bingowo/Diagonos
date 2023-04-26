#include <stdio.h>
#include <stdlib.h>
int cmp(void* a,void* b){
    char* m=(char*)a,*n=(char*)b;
    return atof(m)-atof(n);
}
int main()
{
    int n,i;
    scanf("%d",&n);
    char s[n][110];
    for(i=0;i<n;i++) scanf("%s",&s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    for(i=0;i<n;i++){
        printf("%s\n",s[i]);
    }
    return 0;
}
