#include <stdio.h>
#include <stdlib.h>
#include <string.h>
static char *A;
int cmp1(const void *a, const void *b){
    int x1=*(int*)a, x2=*(int*)b;
    char s1[5], s2[5];
    sprintf(s1,"%d",x1);
    sprintf(s2,"%d",x2);
    char *p1= strstr(A,s1), *p2=strstr(A,s2);
    if(p1&&p2){
        if(p1>p2) return 1;
        else return -1;
    }else if(!p1&&p2) return 1;
    else if(p1&&!p2) return -1;
    else return x1-x2;
}
int main(){
    int m, n, num;
    scanf("%d", &m);
    char temp[6];
    long long size = 6;
    A = (char*)calloc(6,sizeof(char));
    scanf("%d", &num);
    sprintf(temp, "%d/", num);
    strcpy(A,temp);
    for(int i=1; i<m; i++){
        scanf("%d", &num);
        sprintf(temp, "%d/", num);
        size += strlen(temp);
        A = (char*)realloc(A, sizeof(char)*size);//动态调整A的内存大小
        strcat(A,temp);
    }
    scanf("%d", &n);
    int *B;
    B = (int*)malloc(sizeof(int)*n);
    for(int i=0; i<n; i++) scanf("%d", &B[i]);
    qsort(B, n, sizeof(B[0]), cmp1);
    for(int i=0; i<n-1; i++) printf("%d ", B[i]);
    printf("%d", B[n-1]);
    free(B);
    free(A);
    return 0;
}