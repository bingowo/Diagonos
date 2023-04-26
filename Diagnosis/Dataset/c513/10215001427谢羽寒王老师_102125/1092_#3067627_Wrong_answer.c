#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char a[3];
    int cnt;
}STRUCT;

int main()
{
    char s[1000];
    scanf("%s",s);
    int len,i,j;
    len=strlen(s);
    STRUCT n[len];
    for(i=0;i<len;i++){
        n[i].a[0]=s[i];
        n[i].cnt=1;
    }
    for(i=1;i<len;i++){
        if(s[i]!=n[i-1].a[0]){ n[i-1].a[1]=s[i]; n[i-1].cnt++;}
    }

   for(i=0;i<len-1;i++){
        if((s[i]!=n[i+1].a[0])&&(s[i]!=n[i+1].a[1])){ n[i+1].a[2]=s[i]; n[i+1].cnt++;}
    }
    int result=1;
    for(j=0;j<len;j++){
        result=result*(n[j].cnt);
    }
    printf("%d",result);




}