#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct string{char q[100];} std;

int cmp(const void * a,const void * b){
    std * p1 = (std*)a;
    std * p2 = (std*)b;
    return strcmp(p1->q,p2->q);
}

int main(){
    std str[260];
    char s[501];gets(s);

    int k = 0;int j = 0;int bool = 0;
    for (int i = 0;s[i] != '\0'; ++i)
    {
        if(s[i] == ' '||s[i] == '.'||
        s[i] == ','||s[i] == '!'||s[i] == '?')
        {   if(!bool){k++;bool = 1;}  j = 0;continue;}
        str[k].q[j++] = s[i];bool = 0;
    }
    qsort(str,k+1,sizeof(std),cmp);
    int bol = 0;
    for (int i = 1; i < k+1; ++i) {
        if(bol&&(cmp(str[i-1].q,str[i].q) == 0))continue;
        printf("%s ",str[i].q);bol++;
    }
}