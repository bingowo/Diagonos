#include<stdio.h>
#include<string.h>
int check(char *a, int i){
    char c = a[i];
    while(a[i]!='0'){
        if(c>a[i])return 0;
        i++;
    }
    return 1;
}
int main(){
    char get[101] = {'0'};
    char ret[201] = {'0'};
    scanf("%s", &get);
    int len = strlen(get);
    int i = 0;
    int j = 0;
    while(i<len){
        if(check(get, i)==0)ret[j++]=get[i];
        else{
            ret[j++]=get[i];
            ret[j++]=get[i];
        }
    }
    printf("%s", ret);
    return 0;
}