#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void *getServer(const void *a){
    char* ch = (char*)a;
    while(*ch != '@') ch++;
    return ch+1;
}

int cmp(const void * a, const void * b){
    int k = strcmp((char*)getServer(a),(char*)getServer(b));
    return k?k:strcmp((char*)a,(char*)b);
}

int main(){
    int cases;
    scanf("%d",&cases);

    char** a = (char**)malloc(cases*sizeof(char*));
    char temp[1000001];

    for(int k = 0; k < cases; k++){
        scanf("%s",temp);
        strcpy(a[k] = (char*)malloc(strlen(temp)*sizeof(temp[0])),temp);
    }

    qsort(a,cases,sizeof(a[0]),cmp);

    for(int k = 0; k < cases; k++){
        printf("%s",a[k]);
    }

}
