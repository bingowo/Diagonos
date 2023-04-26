#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(){
    char s[1001];
    gets(s);
    char now[1001],left[1001],right[1001];
    char *p=s;
    now[0]=toupper(*p);p++;now[1]='\0';
    while(*p){
        left[0]=toupper(*p);left[1]='\0';
        strcat(left,now);
        strcpy(right,now);
        right[strlen(now)]=toupper(*p);right[strlen(now)+1]='\0';
        if(strcmp(left,right)>0)strcpy(now,left);
        else strcpy(now,right);
        *left='\0';*right='\0';p++;
    }
    printf("%s",now);
}