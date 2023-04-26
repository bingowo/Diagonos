#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char str[1000001];
    char name[1000001];
    char com[1000001];
    int len1;
    int len2;
}String;
int cmp(const void *p1,const void *p2){
    String *a=(String *)p1;
    String *b=(String *)p2;
    if(strcmp(a->com,b->com)!=0){
        return strcmp(a->com,b->com);
    }
    return -strcmp(b->name,a->name);
}
int main() {
    int n;
    scanf("%d",&n);
    String a[n];
    for(int i=0;i<n;i++){
        scanf("%s@%s",a[i].name,a[i].com);
        a[i].len1 = strlen(a[i].name);
        a[i].len2 = strlen(a[i].com);
    }
    qsort(a,n,sizeof(a[0]),cmp);
    for(int j=0;j<n;j++){
        printf("%s@%s\n",a[j].name,a[j].com);
    }
    return 0;
}
