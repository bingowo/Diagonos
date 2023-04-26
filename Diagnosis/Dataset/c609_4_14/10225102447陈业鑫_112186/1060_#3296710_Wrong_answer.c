#include<stdio.h>
#include<string.h>
int check(char *a, int i, int len){
    char c = a[i];
    if(i==len-1)return 0;
    if(a[i]>=a[i+1])return 0;
    return 1;
}
int main(){
    char get[101] = {'\0'};
    char ret[201] = {'\0'};
    scanf("%s", &get);
    int len = strlen(get);
    int i = 0;
    int j = 0;
    while(i<len){
        if(check(get, i, len)==0)ret[j++]=get[i];
        else{
            ret[j++]=get[i];
            ret[j++]=get[i];
        }
        i++;
    }
    printf("%s", ret);
    return 0;
}