#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const void *a,const void *b){
    char *s1=*(char**)a,*s2=*(char**)b;
    char *p1=strchr(s1,'@')+1,*p2=strchr(s2,'@')+1;
    if(strcmp(p1,p2)==0)return strcmp(s1,s2)<0?1:-1;
    return strcmp(p1,p2);
}
int main(){
    int n;
    scanf("%d",&n);
    char *s[1000001];
    char temp[1000001];
    for(int i=0;i<n;i++){
        scanf("%s",temp);
        s[i]=(char*)malloc(strlen(temp)+1);
        strcpy(s[i],temp);
    }
    qsort(s,n,sizeof(s[0]),cmp);
    for(int i=0;i<n;i++){
        printf("%s\n",s[i]);
        free(s[i]);
    }
}