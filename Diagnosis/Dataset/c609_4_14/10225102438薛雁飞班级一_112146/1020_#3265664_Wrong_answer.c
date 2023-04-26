#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int num(char *a)
{
    int n=0,b=-1;
    for(int i=0;i<strlen(a);i++){
        if(a[i]>='0'&&a[i]<='9'){
            n=(a[i]-'0')+n*10;
            b=a[i];
        }
    }
    if(b==-1)return -1;
    return n;
}
int strnumcmp(const void* a,const void* b)
{
    char *p1=(char*)a;
    char *p2=(char*)b;
    if(num(p1)==num(p2)){
        return(strcmp(p1,p2));
    }
    else if(num(p1)>num(p2))return 1;
    else return -1;
}
int main()
{
    char p[100][30];
    int i=0;
    while(scanf("%s",p[i])!=EOF){
        i++;
    }
    qsort(p,i,sizeof(p[0]),strnumcmp);
    for(int j=0;j<i;j++){
        printf("%s ",p[j]);
    }
    return 0;
}
