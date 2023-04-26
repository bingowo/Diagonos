#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void input(char **mail, int n){
    for (int i = 0; i != n; i++){
        char *temp = (char*)malloc(sizeof(char) * 1000000);
        scanf("%s", temp);
        mail[i] = (char*)malloc(sizeof(char) * (strlen(temp)+1));
        strcpy(mail[i], temp);
        free(temp);
    }
}

int compare(void const *p1, void const *p2){
    char *mail1 = *(char**)p1, *mail2 = *(char**)p2;
    int index = 0;
    while (*(mail1+index++) != '@');
    char *t1 = mail1 + index;
    index = 0;
    while (*(mail2+index++) != '@');
    char *t2 = mail2 + index;
    
    if (strcmp(t1, t2) == 0)
        return strcmp(mail2, mail1);
    return strcmp(t1, t2);
}

void output(char **mail, int n){
    for (int i = 0; i != n; i++){
        printf("%s\n", mail[i]);
        free(mail[i]);
    }
    free(mail);
}

int main(){
    int n; 
    scanf("%d", &n);
    char **mail = (char**)malloc(sizeof(char *) * n);
    input(mail, n);
    qsort(mail, n, sizeof(mail[0]), compare);
    output(mail, n);
    return 0;
}