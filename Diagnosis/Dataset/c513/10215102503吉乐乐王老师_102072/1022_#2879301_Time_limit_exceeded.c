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
    if (strcmp(a.domain,b.domain)==0) return strcmp(b.user,a.user);
    return strcmp(a.domain,b.domain);
}
int main() {
    int n;
    scanf("%d",&n);getchar();
    node *t=(node*)malloc(sizeof(node)*n);
    for(int i=0;i<n;i++){
        t[i].domain=(char*)malloc(sizeof(char)*2000);
        t[i].user=(char*)malloc(sizeof(char)*2000);
    }
    for(int i=0;i<n;i++){
        char temp[3000],ch=getchar(),idx=0;
        while(ch!='@'){
            temp[idx]=ch;idx++;ch=getchar();
        }
        temp[idx]='\0';strcpy(t[i].user,temp);
        ch=getchar();idx=0;
        while(ch!='\n'){
            temp[idx]=ch;idx++;ch=getchar();
        }
        temp[idx]='\0';strcpy(t[i].domain,temp);
    }
    qsort(t,n,sizeof(t[0]),cmp);
    for (int j = 0; j < n; ++j) {
        printf("%s@%s\n",t[j].user,t[j].domain);
    }
    return 0;
}