#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char  dic[100];
char  tar[1000];
int pos(char a){
    int i=0;
    for(i;i<strlen(dic);i++){//全局变量
        if(toupper(a)==dic[i])return i;
    }
    return i;
}
int cmp(const void * a,const void * b){
    char *x=(char*)malloc(sizeof(char)*100);
    char *y=(char*)malloc(sizeof(char)*100);
    x=(char*)a;y=(char*)b;
    int i=0;
    for(i=0;i<strlen(x)&&i<strlen(y);i++){
        if (toupper(x[i])!=toupper(y[i]))return pos(x[i])<pos(y[i])?1:-1;
    }
    return strlen(x)>strlen(y)?1:-1;
}
int main(){
    char *arr[100];
    for(int i=0;i<100;i++){
        arr[i]=(char*)malloc(sizeof(char)*100);
    }
    while(scanf("%s",dic)==1){
        int arri=0;
        while(scanf("%s",arr[arri++])){
            char ch=getchar();
            if(ch==' ')continue;
            if(ch=='\n')break;
        }
        qsort(arr,arri,sizeof(char*),cmp);
        for(int i=0;i<arri;i++){
            printf("%s",arr[i]);
            if(i!=arri-1)putchar(' ');
            else putchar('\n');
        }
    }
}