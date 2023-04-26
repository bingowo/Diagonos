#include<stdio.h>
#include<string.h>
int main(){
    char s[51],*c,c1,c2;
    int max=1,now=1;
    scanf("%s",s);
    c=s;
    if(strlen(s)==1){
        printf("1");
        return 0;
    }
    c1=*c;
    c++;
    c2=*c;
    while(*c){
        if(c1!=c2)now+=1;
        else now =1;
        if(now>max)max=now;
    }
    printf("%d",max);
    return 0;
}