#include <stdio.h>
#include<string.h>
#include <stdio.h>
#include<string.h>
#include<stdlib.h>
const int maxn = 1e6+5;
typedef struct {
    char* user;
    char* domain;
}node;
int  cmp(const void* x,const void* y){
    node a=*(node*)x;
    node b=*(node*)y;
    char *p1=a.domain;char *p2=b.domain;
    while(*p1&&*p2){
        if(*p1==*p2){p1++;p2++;continue;}
        return *p1<*p2?1:-1;}
    *p1=a.user,p2=b.user;
    while(*p1&&*p2){
        if(*p1==*p2){p1++;p2++;continue;}
    }
    return *p1>*p2?1:-1;
}
int main() {
    int n;
    scanf("%d",&n);getchar();
    node *t=(node*)malloc(sizeof(node)*n);
    // for(int i=0;i<n;i++){
    //     t[i].domain=(char*)malloc(sizeof(char)*5000000);
    //     t[i].user=(char*)malloc(sizeof(char)*5000000);
    // }
    for(int i=0;i<n;i++){
        char temp[5000010],ch=getchar(),idx=0;
        while(ch!='@'){
            temp[idx]=ch;idx++;ch=getchar();
        }
        temp[idx]='\0';
        t[i].user=(char *)malloc(sizeof(char)*(strlen(temp)+1));
        strcpy(t[i].user,temp);
        ch=getchar();idx=0;
        while(ch!='\n'){
            temp[idx]=ch;idx++;ch=getchar();
        }
        temp[idx]='\0';
        t[i].domain=(char *)malloc(sizeof(char)*(strlen(temp)+1));
        strcpy(t[i].domain,temp);
    }
    qsort(t,n,sizeof(t[0]),cmp);
    for (int j = 0; j < n; ++j) {
        printf("%s@%s\n",t[j].user,t[j].domain);
    }
    for(int i=0;i<n;i++){
    free(t[i].user);
    free(t[i].domain);
    }
    return 0;
}