#include<stdio.h>
#include<string.h>
char* int_(char *a);
char* doub_(char *a);
int main(){
    
    while(1){
        int i = 0,flag = 0,j = 0;
        char a[100]='\0';
        char *p = NULL;
        while(scanf("%c",a[i++])!=EOF){
            if(a[i-1]=='.')flag = 1;
            if(getchar() =='\n')break;
        }
        if(flag == 1){
            p = doub_(a);
        }
        else p = int_(a);
        for(int i = 0;*(p+i)!='\0';i++){
            if(j == 2){printf(" ");j = 0;}
            printf("%c",*p);
            j++;
        }
    }
}
char* int_(char *a){
    char b[8] = '\0';
    int s = 0,n;
    for(int i = 0; i < strlen(a);i++){
        s = s*10+ *(a+i);
    }
    for(int i = 0; i < 8;i++){
        n = (s>>(i*4))&15;
        if(n >= 10)b[i] = n-10+'a';
        else b[i] =  n+'0';
    }
    return b;
}
char* doub_(char *a){
    
    
    
}