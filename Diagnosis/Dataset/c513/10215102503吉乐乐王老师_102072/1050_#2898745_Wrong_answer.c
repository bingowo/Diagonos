#include<stdio.h>
#include<string.h>
void rev(char s[]){
    int i=0,j=strlen(s)-1;
    while(i<j){
        char t=*(s+i);
        *(s+i)=*(s+j);
        *(s+j)=t;
        i++;j--;
    }
}
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char s1[100],s2[100],s[100];
        gets(s1);
        gets(s2);
        gets(s);
        int ret=0;
        char p1=strstr(s,s1)-s;
        char p2=strstr(s,s2)-s;
        if(p1>p2){
            rev(s);rev(s1);
            p1=strlen(s)-(strstr(s,s1)-s);
            ret=p1-p2-strlen(s1)-strlen(s2);}
        if(p1<p2){
            rev(s);rev(s2);
            p2=strlen(s)-(strstr(s,s2)-s);
            ret=p2-p1-strlen(s1)-strlen(s2);}
        printf("case #%d:\n%d\n",cas++,ret);
    }
}