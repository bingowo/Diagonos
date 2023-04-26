#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *getServer(char *a){
    char* ch = a;
    while(*ch != '@') ch++;
    return ch+1;
}

int cmp(const void * a, const void * b){
    int k = strcmp(getServer(*(char**)a),getServer(*(char**)b));
    return k?k:strcmp(*(char**)b,*(char**)a);
}

int main(){
    int cases;
    scanf("%d",&cases);

    char** a = (char**)malloc(cases*sizeof(char*));
    char temp[1000001];

    for(int k = 0; k < cases; k++){
        scanf("%s",temp);
        strcpy(a[k] = (char*)malloc(strlen(temp)+1),temp);
    }

    qsort(a,cases,sizeof(a[0]),cmp);

    for(int k = 0; k < cases; k++){
        printf("%s\n",a[k]);
    }

    return 0;
}
