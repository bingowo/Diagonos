#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct HTTP{
    char url[300];
    char domain[300];
    char vAddress[300];
}http;

void splitUrl(char* url, char* domain, char* vAddress){
    char urlCpy[300];
    memset(urlCpy, 0, sizeof(urlCpy));
    strcpy(urlCpy, url);

    char split[] = "/";
    char *ptr = strtok(urlCpy, split);
    // printf("test : %s\n", ptr);
    ptr = strtok(NULL, split);
    // printf("test : %s\n", ptr);
    strcpy(domain, ptr);
    ptr = strtok(NULL, split);

    int diff = ptr - urlCpy;
    // printf("diff : %d\n", diff);
    strcpy(vAddress, "/");
    strcat(vAddress, url+diff);
}

int cmp(const void* a, const void* b){
    http* A = (http*)a, *B = (http*)b;
    if(strcmp(A->domain, B->domain)==0){
        return strcmp(A->vAddress, B->vAddress);
    }
    return strcmp(A->domain, B->domain);
}

int isHttp(char* url){
    char urlCpy[300];
    memset(urlCpy, 0, sizeof(urlCpy));
    strcpy(urlCpy, url);

    char split[] = "/";
    char *ptr = strtok(urlCpy, split);
    // printf("test : %s\n", ptr);
    // printf("len : %d\n", strlen(ptr));
    return strlen(ptr) == 5;
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    http inputs[n];
    memset(inputs, 0, n*sizeof(http));

    http inputHttp[n];
    memset(inputHttp, 0, n*sizeof(http));
    int cnt = 0;

    for(int i = 0;i<n;i++){
        scanf("%s",&inputs[i].url);
        splitUrl(inputs[i].url, inputs[i].domain, inputs[i].vAddress);
        // printf("is : %d\n", isHttp(inputs[i].url));
        if(isHttp(inputs[i].url)){
            inputHttp[cnt++] = inputs[i];
        }
    }

    qsort(inputHttp, cnt, sizeof(inputHttp[0]), cmp);

    // printf("res : \n");
    for(int i = 0;i<cnt;i++){
        printf("%s\n",inputHttp[i].url);
    }
    return 0;
}
