#include<stdio.h>
#include <stdlib.h>
#include<string.h>
char *strlast(const char *s1,const char *s2){
    char *ret=NULL;
    char *p1=s1;
    char *p2=s2;
    while(strstr(s1,s2)!=NULL){
        ret=strstr(p1,p2);
        p1+=strlen(s2);
    }
    return ret;
}
int main(){
    int t,i;
    int len1,len2,max;
    scanf("%d",&t);
    char s1[100];
    char s2[100];
    char s3[100];
    for(i=0;i<t;i++){
        scanf("%s %s %s",s1,s2,s3);
        char *p1=strstr(s3,s1);
        char *p2=strlast(s3,s2);
        char *p3=strstr(s3,s2);
        char *p4=strlast(s3,s1);
        if(p1==p2){
            len1=0;
        }else if(p1==NULL||p2==NULL){
            len1=0;
        }else{
            len1=p2-p1-(strlen(s1));
        }
        if(p3==p4){
            len2=0;
        }else if(p3==NULL||p4==NULL){
            len2=0;
        }else{
            len2=p4-p3-(strlen(s2));
        }
        if(len1>=len2){
            max=len1;
        }else{
            max=len2;
        }
        printf("case #%d:\n", i);
        printf("%d\n",max);
    }
}