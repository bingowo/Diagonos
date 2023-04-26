#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(void* a,void* b){
    char* m=*(char**)a,n=*(char**)b;
    if(f(m)!=f(n)) return f(m)-f(n);
    else return strcmp(a,b);
}
int f(char* s){
    int x=0,i,l=strlen(s);
    for(i=0;i<l;i++){
        if((s[i]>='0')&&(s[i]<='9')){
            x=x*10+atoi(s[i]);
        }
    }
    return x;
}
int main()
{
    int j,i=0;
    char* x[100][32];
    while(scanf("%s",&x[i])!=EOF) i++;
    qsort(x,i,sizeof(x[0]),cmp);
    for(j=0;j<i;j++) printf("%s ",x[j]);
    return 0;
}
