#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
int find(char *c1,char *c2,char **s1,int n){
    if(c1==c2){
        printf("%c ",*c2);
        return 1;
    }
    char c=*(c2+1);
    int flag=0;
    *(c2+1)=0;
    for(int i=0;i<n;i++){
        if(strcmp(c1,*(s1+i))==0){
            printf("%s ",*(s1+i));
            flag=1;
            break;
        }
    }
    *(c2+1)=c;
    return flag;
}
int main(){
    int n,len=0;
    char **s1;
    scanf("%d",&n);
    s1=(char**)malloc(n*sizeof(char*));
    for(int i=0;i<n;i++){
        char *s;
        s=(char *)malloc(15*sizeof(char));
        scanf("%s",s);
        *(s1+i)=s;
        len=strlen(s)>len?strlen(s):len;
    }
    char s2[5001],*c1,*c2;
    scanf("%s",s2);
    c1=s2;
    c2=s2+len-1;
    while(*c2!=0){
        if(find(c1,c2,s1,n)){
            c1=c2+1;
            if(c2+len>s2+strlen(s2)-1){
                c2=s2+strlen(s2)-1;
            }
            else c2=c2+len;

        }
        else c2--;
    }
    return 0;
}