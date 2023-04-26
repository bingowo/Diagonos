#include<stdio.h>
#include<string.h>

int main(){
    int T, a = 0, b = 0,flag = 0;
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
                        flag = 1;
                    }
                    n++;
                    j++;
                }
                i = n;
            }
            if(flag == 1){flag = 0;break;}
        }
        for(int i = strlen(s)-1;i >= 0;i--){
            if(s[i] = s2[strlen(s2)-1]){
                int n = i, j = strlen(s2) - 1;
                while(s[n] == s2[j]){
                    if(j == 0){
                        b = n;
                        flag = 1;
                    }
                    n--;
                    j--;
                }
                i = n;
            }
            if(flag == 1){flag = 0;break;}
        }
        printf("case #%d:\n%d\n", m, b-a-1);
    }
    return 0;
}