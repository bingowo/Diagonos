#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char *name;
    char *domain;
}EMAIL;

int cmp1(const void *a, const void *b){
    EMAIL x1=*(EMAIL*)a, x2=*(EMAIL*)b;
    if(strcmp(x1.domain,x2.domain)!=0)
        return strcmp(x1.domain,x2.domain);
    return strcmp(x2.name, x1.name);
}
int main(){
    int n, temp;
    scanf("%d", &n);
    EMAIL *emails;
    char *pos, *s;
    emails = (EMAIL*)malloc(sizeof(EMAIL)*n);
    s = (char*)malloc(sizeof(char)*1000000);
    for(int k=0; k<n; k++){
        scanf("%s", s);
        pos = strchr(s,'@');
        emails[k].name = (char*)malloc(sizeof(char)*(pos-s+1));
        emails[k].domain = (char*)malloc(sizeof(char)*(strlen(s)-(pos-s+1)+1));
        strcpy(emails[k].domain,pos+1);
        strncpy(emails[k].name,s,pos-s);
        emails[k].name[pos-s] = '\0';
    }
    qsort(emails,n,sizeof(emails[0]),cmp1);
    for(int k=0; k<n; k++){
        printf("%s%c%s\n", emails[k].name,'@',emails[k].domain);
        free(emails[k].name);
        free(emails[k].domain);
    }
    free(emails);
    free(s);
    return 0;
}
