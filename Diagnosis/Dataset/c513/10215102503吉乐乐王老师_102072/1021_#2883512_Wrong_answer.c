#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char dic[100];
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
int cmp(const void * a,const void * b){
    char *x=(char*)a;char* y=(char*)b;
    int i=0;int posx,posy;
    while(*(x+i)&&*(y+i)){
        if(*(x+i)>='a'&&*(x+i)<='z')*(x+i)=toupper(*(x+i));
        if(*(y+i)>='a'&&*(y+i)<='z')*(y+i)=toupper(*(y+i));
        posx=dic[*(x+i)-'A'];
        posy=dic[*(y+i)-'A'];
        if(posx!=posy)return posx-posy;
        i++;
    }
    if(*(x+i)=='\0')return -1;
    return 1;
}