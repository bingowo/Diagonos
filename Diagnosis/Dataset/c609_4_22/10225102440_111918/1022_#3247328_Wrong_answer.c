#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(void* a,void* b){
    char* m=(char*)a,*n=(char*)b;
    long long int i=0,j=0,k;
    while(m[i]!='@')i++;
    while(n[j]!='@')j++;
    if(strcmp(m+i,n+j)!=0)return strcmp(m+i,n+j);
    else return strcmp(m,n);
    return 0;
}
int main()
{
    int n,i;
    scanf("%d",&n);
    char **s;
    s=(char**)malloc(sizeof(char*)*n);
    for(i=0;i<n;i++){
        char* a=(char*)malloc(sizeof(char)*1000001);
        scanf("%s",a);
        s[i]=(char*)malloc(sizeof(char)*(strlen(a)+1));
        strcpy(s[i],a);
        free(a);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(i=0;i<n;i++)printf("%s\n",s[i]);
    return 0;
}
