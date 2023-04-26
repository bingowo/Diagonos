#include<stdio.h>
#include<string.h>

int main(){
    int T, a = 0, b = 0,flag1 = 0, flag2 = 0;
    scanf("%d",&T);
    for(int m = 0;T > m;m++){
        char s1[81], s2[81], s[81];
        scanf("%s%s%s",s1, s2, s);
        for(int i = 0;i < strlen(s);i++){
            if(s[i] == s1[0]){
                int n = i, j = 0;
                while(s[n] == s1[j]){
                    if(j == strlen(s1)-1){
                        a = n;
                        flag1 = 1;
                    }
                    n++;
                    j++;
                }
                i = n-1;
            }
            if(flag1 == 1)break;
        }
        for(int i = strlen(s)-1;i >= 0;i--){
            if(s[i] = s2[strlen(s2)-1]){
                int n = i, j = strlen(s2) - 1;
                while(s[n] == s2[j]){
                    if(j == 0){
                        b = n;
                        flag2 = 1;
                    }
                    n--;
                    j--;
                }
                i = n;
            }
            if(flag2 == 1)break;
        }
        int space = 0;
        if(flag1 != 0&&flag2 != 0)space = b - a -1;
        printf("case #%d:\n%d\n", m, space);
    }
    return 0;
}