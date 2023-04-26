#include <stdio.h>
#include <string.h>
char s2[125];
typedef struct {
    int num;
    char S[110];
}str;
char * inspect(char s[],int len){
    int p=0;
    if (s[0] != s[1]){
        s2[p++] = s[0];
    }
    for(int j=1;j<len-1;j++){
        if(s[j] !=s[j+1]&& s[j]!=s[j-1]){
            s2[p++] = s[j];
        }
    }
    if (s[len-1] != s[len -2]){
        s2[p++] = s[len-1];
    }
    s2[p] =0;
    return s2;
}
int main() {
    int T;
    for(int i=0;i<T;i++){
        str a[220];
        char s[125];
        scanf("%s",s);
        int len = strlen(s);
        inspect(s,len);
        int p = strlen(s2);
        int ret = len-p;
        int sum1;
        for(int q=0;q<p-1;q++){
            strncpy(a[q].S,s2,q+1);
            a[q].S[q+1] = s2[q+1];
            strncpy(a[q].S+q+2,s2+q+1,p-q-1);
            a[q].S[p+1] = 0;
            int lenth = strlen(a[q].S);
            inspect(a[q].S,lenth);
            int len2 = strlen(s2);
            int re = lenth-len2;
            int sum = re;
            sum1 = 2;
            if(len2 >2){
                while(re){
                    inspect(s2,len2);
                    re = len2- strlen(s2);
                    len2 = strlen(s2);
                    sum = re +sum;
                }
            }
            if(sum >sum1){
                sum1 = sum;
            }
        }
        ret = ret +sum1;
        printf("case #%d:\n%d\n",i,ret);
    }
    return 0;
}
