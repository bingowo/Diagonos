#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNum(char *s){
    int len=strlen(s);
    int flag=0,sum=0;
    for(int i=0;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            sum=10*sum+s[i]-'0';
            flag=1;
        }
    }
    if(flag==0)
        sum=-1;
    return sum;
}

int strnumcmp(const void* a,const void* b){
    char *x=(char *)a;
    char *y=(char *)b;
    int n1,n2;
    n1=getNum(x);
    n2=getNum(y);
    if(n1>n2)   return 1;
    else if(n1<n2)  return -1;
    else    return strcmp(x,y);
}

int main()
{
    char n[100][30];
    int i=0,j=0;
    while(scanf("%s",&n[i])!=EOF)
        i++;
    qsort(n,i,sizeof(n[0]),strnumcmp);
    for(j=0;j<i-1;j++)
        printf("%s ",n[j]);
    printf("%s",n[j]);
    return 0;
}
