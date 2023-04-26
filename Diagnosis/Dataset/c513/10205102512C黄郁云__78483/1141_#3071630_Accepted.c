#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int layer[50];

int push(int *a,int top,int i){
        a[top++] = i;
        return top;
}

int pop(int *a,int top){
    if(a[top-1] == 0){
        a[top-1] = 1;
        return top;
    }else{
        int sum  = 0;
        while(top>0){
        if(a[top-1] != 0){
            sum+=a[top-1];
            top--;
        }else if(a[top-1] == 0){
            a[top-1] = sum*2;
            return top;

        }
    }
}
}


int main(){
    char s[55];
    int sta[50];
    int status = 0;
    int status_max = 0;
    scanf("%s",&s);
    int length = strlen(s);
    int top = 0;
    for(int i =0; i <length;i++){
            if(s[i] == '('){
                top = push(sta,top,0);
               }else if(s[i] == ')'){
                   top =pop(sta,top);
               }


    }
    int ttl = 0;

    for(int i = 0; i <top;i++){
        ttl+=sta[i];
    }
    printf("%d",ttl);

}
