#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char dic[100];
int pos(char a);
int cmp(const void * a,const void * b);
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
        qsort(arr,arri,sizeof(arr[0]),cmp);
        for(int i=0;i<arri;i++){
            printf("%s",arr[i]);
            if(i!=arri-1)putchar(' ');
            else putchar('\n');
        }
    }
}
int pos(char a){
    int i=0;
    for(i;i<strlen(dic);i++){//全局变量
        if(toupper(a)==dic[i])return i;
    }
    return i;
}
int cmp(const void * a,const void * b){
    // char *x=(char*)malloc(sizeof(char)*100);
    // char *y=(char*)malloc(sizeof(char)*100);
    // x=(char*)a;y=(char*)b;
    // int i=0;int posx,posy;
    // while(x[i]&&y[i]){
    //     for(int j=0;j<strlen(dic);j++){
    //         if(toupper(x[i])==dic[j]){posx=j;break;}
    //     }
    //     for(int j=0;j<strlen(dic);j++){
    //         if(toupper(y[i])==dic[j]){posy=j;break;}
    //     }
    //     if(posx!=posy)return posx<posy?1:-1;
    //     i++;
    // }
    
    for(int i=0;i<strlen(x)&&i<strlen(y);i++){
        if (toupper(x[i])==toupper(y[i]))continue;
        else return pos(x[i])-pos(y[i]);
    }
    return strlen(x)-strlen(y);
}