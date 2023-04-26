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
}
int cmp(const void * a,const void * b){
    char *p;
    p=(char*)a;char x[100];int idx=0;
    while(*(p+idx)!='\0'){
        x[idx]=*(p+idx);
        idx++;
    }
    x[idx]='\0';
    idx=0;p=(char *)b;char y[100];
    while(*(p+idx)!='\0'){
        y[idx]=*(p+idx);
        idx++;
    }
    y[idx]='\0';
    for(int i=0;i<strlen(x)&&i<strlen(y);i++){
        if (toupper(x[i])!=toupper(y[i]))return pos(x[i])<pos(y[i]);
    }
    return strlen(x)<strlen(y);
}
int main(){
    char *arr[100];
    for(int i=0;i<100;i++){
        arr[i]=(char*)malloc(sizeof(char)*100);
    }
    while(scanf("%s",dic)){
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