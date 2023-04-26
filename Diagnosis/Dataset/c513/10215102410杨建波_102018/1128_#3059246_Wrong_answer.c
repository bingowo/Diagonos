#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int cmp(const void *a, const void* b){
    char* p1, *p2;
    p1 = *(char**)a;
    p2 = *(char**)b;
    return strcmp(p1, p2);
}

int main(){
    int n;
    scanf("%d",&n);
    char** http;
    http = (char**)malloc(n*sizeof(char*));
    int j = 0;
    for(int i = 0;n > i;i++){
        char a[301], *p1;
        scanf("%s", a);
        if(a[4] != 's'){
            p1 = (char*)malloc(strlen(a));
            strcpy(p1, a);
            http[j++] = p1;
        }
    }
    qsort(http, j, sizeof(char**), cmp);
    for(int i = 0;i < j;i++){
        printf("%s\n",http[i]);
    }
    
}