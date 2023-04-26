#include <stdio.h>
#include <string.h>
int distance(char *s2,char *a1,int lens1,int len2){
    int sign =0;
    for(int j=0;j< lens1- len2+1;j++){
        if(a1[j] == s2[0]){
            int p=1;
            for(;p< len2;p++){
                if(a1[j+p] != s2[p]){
                    break;
                }
            }
            if(p== len2){
                sign = j>sign?j:sign;
            }
        }
    }
    return sign;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++) {
        char s1[81];
        char s2[81];
        char s[81];
        scanf("%s", s1);
        scanf("%s", s2);
        scanf("%s", s);
        int len1 = strlen(s1);
        int len2 = strlen(s2);
        char *a1 = strstr(s,s1);
        int lens1 = strlen(a1);
        char *b1 = strstr(s,s2);
        int lens2 = strlen(b1);
        int l1 = distance(s2,a1,lens1,len2)-len1;
        int l2 = distance(s1,b1,lens2,len1)-len2;
        printf("case #%d:\n%d\n",i,l1>l2?l1:l2);
    }
    return 0;
}
