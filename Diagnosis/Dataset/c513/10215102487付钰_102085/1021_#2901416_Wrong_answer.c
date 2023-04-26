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

int cmp(const void *a,const void *b)
{
    int p[26];
    char *s1,*s2;
    char ch1,ch2;
    s1=(char *)a;
    s2=(char *)b;
    while(*s1&&*s2){
        ch1=(*s1)>='a'?*s1-32:*s1; //转换为大写字母
        ch2=(*s2)>='a'?*s2-32:*s2; //转换为大写字母
    if(p[ch1-'A']!=p[ch2-'A']) //按字母顺序表比较字母
        return p[ch1-'A']-p[ch2-'A'];
    else {s1++;s2++;}

    }
        if(*s1==0) return -1;
    else return 1;

}
