#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
struct data{
    char ss[50];
};
int cmp(const void* a,const void*b){
    struct data x=*(struct data*)a;
    struct data y=*(struct data*)b;
    if(strcmp(x.ss,y.ss)>=0)return 1;
    else return -1;
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char c;
        struct data p[100];
        int len=0;
        int len1=0;
        c=getchar();
        while((c=getchar())!='\n'){
            if(isalpha(c)){
                p[len].ss[len1]=c;
                len1++;
            }
            else{
                p[len].ss[len1]='\0';
                len1=0;
                len++;
            }
        }
        for(int i=0;i<len;i++){
            //printf("%d%s",i,p[i].ss);
        }
        //printf("%d",len);
        qsort(p,len+1,sizeof(p[0]),cmp);
        printf("case #%d:\n",t);
        int flag=1;
        for(int i=0;i<len;i++){
            if(strcmp(p[i].ss,p[i+1].ss)==0){
                flag=0;
            }
            else{
                flag=1;
            }
            if(flag){
                printf("%s %d",p[i].ss,i);
            }
        }
        printf("%s",p[len].ss);
        printf("\n");
    }
    return 0;
}
