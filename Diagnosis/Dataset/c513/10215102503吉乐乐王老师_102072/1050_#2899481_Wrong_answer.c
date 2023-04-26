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
int min(int a,int b){
    return a<b?a:b;
}
int main(){
    int t;scanf("%d",&t);getchar();int cas=0;
    while(t--){
        char s1[100],s2[100],s[100];
        gets(s1);
        gets(s2);
        gets(s);
        int ret=0;
        char p11=strstr(s,s1)-s;
        char p21=strstr(s,s2)-s;
        rev(s),rev(s1),rev(s2);
        char p12=strstr(s,s1)-s;
        char p22=strstr(s,s2)-s;
        char p1=min(p11,p12);
        char p2=min(p21,p22);
        printf("case #%d:\n%d\n",cas++,strlen(s)-p1-p2-strlen(s1)-strlen(s2));
    }
}