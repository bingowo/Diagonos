#include<stdio.h>
#include<string.h>

int main(){
    char w[1005] = {0};
    gets(w);
    char res[2010] = {0};
    int l=1005, r=1005;
    int wlen = strlen(w);
    res[l]=w[0];
    for (int i=1; i<wlen; i++){
        if (w[i]>=res[l]) res[--l]=w[i];
        else res[++r]=w[i];
    }
    int index=0;
    while(res[index]==0) index++;
    for (int i=index; res[i]!='\0'; i++){
        if (res[i]>='a') res[i] = res[i]-'a'+'A';
        printf("%c", res[i]);
    }
    return 0;
}