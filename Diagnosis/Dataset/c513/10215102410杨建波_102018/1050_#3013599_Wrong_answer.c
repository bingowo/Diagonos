#include<stdio.h>
#include<string.h>

int search_begin(char*s1, char*s){
    int flag1 = 0, a = -1;
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
    return a;
}

int search_end(char*s2, char*s){
    int flag2 = 0, b = -1;
     for(int i = strlen(s)-1;i >= 0;i--){
            if(s[i] == s2[strlen(s2)-1]){
                int n = i, j = strlen(s2) - 1;
                while(s[n] == s2[j]){
                    if(j == 0){
                        b = n;
                        flag2 = 1;
                    }
                    n--;
                    j--;
                }
                i = n+1;
            }
            if(flag2 == 1)break;
    }
    return b;
}

int main(){
    int T, a1 , a2, b1, b2;
    scanf("%d",&T);
    for(int m = 0;T > m;m++){
        char s1[81], s2[81], s[81];
        scanf("%s%s%s",s1, s2, s);
        a1 = search_begin(s1, s);
        a2 = search_end(s1, s);
        b1 = search_begin(s2, s);
        b2 = search_end(s2, s);
        int space = 0;
        if(a1 != -1 && b2 != -1){
            if(a1==b2||a2 == b1)space =0;
            else space = (b2 - a1 > a2 - b1? b2-a1-1:a2-b1-1);
        }
        printf("case #%d:\n%d\n", m, space);
    }
    return 0;
}

