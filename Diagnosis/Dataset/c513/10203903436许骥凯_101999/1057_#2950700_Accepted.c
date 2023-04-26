#include<stdio.h>
#include<ctype.h>

int main(){
    char s[3000] = {0}, c; int max = 1500, min = 1500;
    scanf("%c", &s[max]); s[max] = toupper(s[max]);
    while((c = getchar()) != '\n' && c != EOF){
        if (toupper(c) >= s[max])
            s[--max] = toupper(c);
        else s[++min] = toupper(c);
    }
    printf("%s\n", s + max);
}