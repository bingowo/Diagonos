#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const void *a,const void *b){
    char *p1=strstr((char*)a,"//")+1,*p2=strstr((char*)b,"//")+1;
    if(strcmp(p1,p2)==0){
        p1=strstr((char*)a,"/")+1,p2=strstr((char*)b,"/")+1;
    }
    return strcmp(p1,p2);
}
int main(){
    char s[101][301];
    int n;
    scanf("%d",&n);
    int idx=0;
    for(int i=0;i<n;i++){
        scanf("%s",s[idx]);
        if(s[idx][4]==':')idx++;
    }
    qsort(s,idx,sizeof(s[0]),cmp);
    for(int i=0;i<idx;i++){
        printf("%s\n",s[i]);
    }
}