#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int p[26];
char alpha[27];

int cmp(const void *a,const void *b){
    char *s1,*s2;
    char ch1,ch2;
    s1=*(char(*)[21])a;s2=*(char(*)[21])b;
    while (*s1 && *s2){
        ch1 = (*s1)>='a'? *s1-32 : *s1;//转换为大写字母；
        ch2 = (*s2)>='a'? *s2-32 : *s2;//转换为大写字母；[
        if(p[ch1-'A'] != p[ch2-'A']) return p[ch1-'A'] - p[ch2-'A'];
        else{s1++;s2++;}
    }
    if(*s1==0) return -1;
    else return 1;
}

int main() {
    while (scanf("%s",alpha) != EOF){
        for(int i=0;i<26;i++){
            p[alpha[i]-'A']=i;
        }
        getchar();//读入字母顺序表；
        char a[100][21];
        int count=0,k=0,status=0;
        char c;
        do {
            c=getchar();
            if(c!=' ' && c!='\n') {a[count][k++]=c;status=1;}
            else if(status){
                a[count][k]='\0';count++;k=0;status=0;
            }
        } while (c!='\n');
        qsort(a,count,sizeof(a[0]),cmp);
        for(int i=0;i<count;i++){
            printf("%s",a[i]);
            if(i != count-1) printf(' ');
        }
    }
    return 0;
}
