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
    int posx,posy;
    while(*x&&*y){
        char ch1,ch2;ch1=*x,ch2=*y;
        if(ch1>='a'&&ch1<='z')ch1=toupper(ch1);
        if(ch2>='a'&&ch2<='z')ch2=toupper(ch2);
        posx=dic[ch1-'A'];
        posy=dic[ch2-'A'];
        if(posx!=posy)return posx<posy?1:-1;
        x++;y++;
    }
    if(*x=='\0')return -1;
    return 1;
}