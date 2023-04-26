#include<stdio.h>
#include<string.h>

int main(){
    char s[100000] = {0}, c; int len = 0;
    while((c = getchar()) != EOF)
        s[len++] = c;
    int state[] = {0, 1, 0, 2, 3};

    int pst = 0;
    for (int i = 0; i != len; i++){
        if (s[i] == '/'){
            if (s[i+1] == '/') pst = 3;
            else if (s[i+1] == '*') i+=2, pst = 4;
        }
        else if (s[i] == '\"') pst = 1;
        else if (s[i] == '\n') pst = 2;
        else pst = 0;

        pst = state[pst];
        if (pst == 1){
            int tindex = 0;
            for(int j = i; s[j] != '\n'; j++)
                if (s[j] == '\"') tindex = j;
            for (; i <= tindex; i++) printf("%c", s[i]);
            i--;
        }
        
        else if (pst == 2){
            for (; s[i] != '\n'; i++);
            printf("\n");
        }

        else if (pst == 3){
            for (; s[i] != '*' || s[i+1] != '/'; i++);
            i++;
        }
        else printf("%c", s[i]);
    }
    return 0;
}