#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
char dic[100];
int cmp(const void * a,const void * b);
int main(){
    char **arr=(char**)malloc(sizeof(char*)*100);
    while(scanf("%s\n",dic)==1){
        int arri=0;char s[1000];char *p;
        while(scanf("%s",s)){
            p=(char*)malloc(sizeof(char)*(strlen(s)+1));
            strcpy(p,s);
            arr[arri++]=p;
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
int cmp(const void * a,const void * b){
    char *x=*(char**)a;char* y=*(char**)b;
    int posx,posy;
    while(*x&&*y){
        char ch1,ch2;ch1=*x,ch2=*y;
        if(ch1>='a'&&ch1<='z')ch1=(char)toupper(ch1);
        if(ch2>='a'&&ch2<='z')ch2=(char)toupper(ch2);
        for(int i=0;i<strlen(dic);i++){
            if(ch1==dic[i]){posx=i;break;}
        }
        for(int i=0;i<strlen(dic);i++){
            if(ch2==dic[i]){posy=i;break;}
        }
        if(posx!=posy)return posx>posy?1:-1;
        x++;y++;
    }
    if(*x=='\0')return -1;
    return 1;
}