#include<stdio.h>
#include<string.h>
int check(char *a, int index, int len, int *ret){
    int same = 0;
    int pr = 0;
    for(int i = index;i<len-1;i++){
        if(a[i]==a[i+1]){
            same++;
            i++;
            while(a[i]==a[i+1]&&i+1<len){
                same++;
                i++;
            }
        }
        if(a[i]==a[i+2]&&a[i]!=a[i+1])pr++;
    }
    *ret+=(same*2-1);
    if(pr>0)*ret+=4;
}
int main(){
    int num = 0;
    char s[10][101] = {'\0'};
    for(int i=0;i<num;i++){
        scanf("%s", &s[i]);
    }
    for(int j=0;j<num;j++){
        printf("case #%d:\n", j);
        int ret = 0;
        int* p_ret = &ret;
        check(s[i], 0, strlen(s[i]), p_ret);
        printf("%d\n", ret);
    }
    return 0;
}