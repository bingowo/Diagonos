#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(){
    char c;
    int flag=0,deflag=0,de=0;
    while((c=getchar())!=EOF){
        if(c=='/'&&!flag&&!deflag){
            deflag=1;
        }
        else if(c=='/'&&flag==1&&deflag)deflag=2;
        else if(c=='*'&&flag==1&&deflag)deflag=3;
        else if(deflag==3&&c=='*')de=1;
        else if(deflag==3&&de&&c=='/'){
            deflag=0;
            de=0;
        }
        else if(c=='\n'){
            flag=0;
            printf("\n");
            if(deflag!=3)deflag=0;
            if(deflag==2)printf("\n");
            continue;
        }
        else{
            if(!deflag)printf("%c",c);
        }
        flag++;
    }
    
    return 0;
}
