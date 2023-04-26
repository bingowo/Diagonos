#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *a,const void *b){
    char *s1 = *((char **)a),*s2 = *((char **)b);
    while(*(s1++) != '@');
    while(*(s2++) != '@');
    if(strcmp(s1,s2) == 0)return strcmp(*((char **)b),*((char **)a));
    else return strcmp(s1,s2);
}

int main()
{
    int n;
    scanf("%d",&n);
    char **email;
    email = (char **)malloc(n * sizeof(char *));
    char s[1000001];
    for(int i = 0;i < n;i++){
        scanf("%s",s);
        email[i] = (char *)malloc(strlen(s));
        strcpy(email[i],s);
    }
    qsort(email,n,sizeof(char *),cmp);
    for(int i = 0;i < n;i++){
        printf("%s\n",email[i]);
    }
    for(int i = 0;i < n;i++){
        free(email[i]);
    }
    free(email);
    return 0;
}
