#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cmp(const void *p1,const void *p2){
    char *a=*(char **)p1;
    char *b=*(char **)p2;
    int i=0;
    while (*(a+i)!='@')
        i++;
    char *a1=a+i+1;
    i=0;
    while (*(b+i)!='@')
        i++;
    char *b1=b+i+1;
    if(strcmp(a1,b1)==0){
        return strcmp(b,a);
    } else
        return strcmp(a1,b1);
}
int main(){
    int n;
    scanf("%d",&n);
    char **email = (char **)malloc(n*sizeof(char *));
    char *p;
    char s[1000001];
    for(int i=0;i<n;i++){
        scanf("%s",s);
        int len = strlen(s);
        p = (char *)malloc((len+1)*sizeof(char));
        strcpy(p,s);
        *(email+i)=p;
    }
    qsort(email,n,sizeof(char *),cmp);
    for(int j=0;j<n;j++){
        printf("%s\n",email[j]);
    }
    for(int j=0;j<n;j++){
        p = email[j];
        free(p);
    }
    free(email);

    return 0;
}