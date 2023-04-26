#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int mycmp(char* a, const char* b){
    int count = 0;
    if (strlen(a) != strlen(b)) return 1;
    else {
        
        for (int i = 0; i < strlen(a); i++){
            if (b[i]>='a'){
                if (a[i]==b[i] || a[i]==b[i]+'A'-'a') count++;
            }
            else if (b[i]>='A'){
                if (a[i]==b[i] || a[i]==b[i]-'A'+'a') count++;
            }
        }
    }
    if (count==strlen(a)) return 0;
    else return 1;
}


int main(){
    int T;
    scanf("%d ", &T);
    const char *a[6] = {"the", "a", "an", "of", "for", "and"};
    for (int t = 0; t < T; t++){
        char s[101] = {0};
        int count = 0;
        while (1){
            scanf("%s", s);
            int flag = 0;
            for (int i = 0; i < 6; i++){
                if (mycmp(s, a[i])!=0){
                    flag++;
                }
            }
            if (flag == 6) count++;
            char ch = getchar();
            if (ch == '\n') {
                printf("case #%d:\n", t);
                printf("%d\n", count); 
                break;
            }   
        }
    }
    return 0;
}