#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char s[101];
    char domain[100];
}EMAIL;

int cmp1(const void *a, const void *b){
    EMAIL x1=*(EMAIL*)a, x2=*(EMAIL*)b;
    if(strcmp(x1.domain,x2.domain)!=0)
        return strcmp(x1.domain,x2.domain);
    return strcmp(x2.s, x1.s);
}
int main(){
    int n;
    scanf("%d", &n);
    EMAIL *emails;
    char *pos;
    emails = (EMAIL*)malloc(sizeof(EMAIL)*n);
    for(int k=0; k<n; k++){
        scanf("%s", emails[k].s);
        pos = strchr(emails[k].s,'@')+1;
        strcpy(emails[k].domain,pos);
    }
    qsort(emails,n,sizeof(emails[0]),cmp1);
    for(int k=0; k<n; k++) printf("%s\n", emails[k].s);
    return 0;
}
