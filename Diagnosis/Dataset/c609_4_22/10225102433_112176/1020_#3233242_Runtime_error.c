#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cmp(const void*a,const void*b)
{
    char* A=(char*)a;
    char* B=(char*)b;
    int x=0,x1=0;
    int y=0,y1=0;
    for(int k=0;k<strlen(A);k++){
        if(isdigit(A[k])){
            x=x*10+A[k]-'0';
            x1=1;
        }
    }
    for(int k=0;k<strlen(B);k++){
        if(isdigit(B[k])){
            y=y*10+B[k]-'0';
            y1=1;
        }
    }
    if(x1==0&&y1==0){
        return strcmp(A,B);
    }else if(x1==1&&y1==0){
        return 1;
    }else if(x1==0&&y1==1){
        return 0;
    }else
        return x-y;
}

void strnumcmp(char* t[100],int n)
{
    qsort(t,n,sizeof(t[0]),cmp);
}

int main()
{
    char *s[100];
    int i=0;
    while(scanf("%s",s[i])!=EOF){
        i++;
    }
//    freopen("C:\\Users\\HP\\CLionProjects\\ecnuoj\\CODING\\hh","r",stdin);
    strnumcmp(s,i);
    for(int j=0;j<i;j++){
        int c=strlen(s[j]);
        for(int k=0;k<c;k++){
            printf("%c",s[j][k]);
        }
        printf(" ");
    }
    return 0;
}