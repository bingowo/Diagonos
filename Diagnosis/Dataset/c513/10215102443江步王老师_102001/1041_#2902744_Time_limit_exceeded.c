#include<stdio.h>
#include<string.h>


int find(char *s, int i);
int main()
{
    char s[51];
    int max=0;
    int i=0;
    int len=0;
    scanf("%s",s);
    while (i < strlen(s)-max){
        len=find(s,i);
        if (len > max){
            max=len;
        }
    }
    printf("%d",max);
    return 0;
}

int find(char *s, int i)
{
    int len=1;
    char prev=*(s+i);
    if (prev != *(s+i+1)){
        while (prev != *(s+i+1) && *(s+i+1) != '\0'){
            prev=*(s+i+1);
            i++;
            len++;
        }
    }
    return len;
}