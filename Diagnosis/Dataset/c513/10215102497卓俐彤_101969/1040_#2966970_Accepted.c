#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void checkchild(char f[],char m[]){
    printf("%s %s ",f,m);
    if(strcmp(f,"A")==0){
        if(strcmp(m,"A")==0){
            printf("{A,O}\n");
        }else if(strcmp(m,"B")==0){
            printf("{A,AB,B,O}\n");
        }else if(strcmp(m,"AB")==0){
            printf("{A,AB,B}\n");
        }else printf("{A,O}\n");
    }else if(strcmp(f,"B")==0){
        if(strcmp(m,"A")==0)printf("{A,AB,B,O}\n");
        else if(strcmp(m,"B")==0)printf("{B,O}\n");
        else if(strcmp(m,"AB")==0)printf("{A,AB,B}\n");
        else printf("{B,O}\n");
    }else if(strcmp(f,"AB")==0){
        if(strcmp(m,"A")==0)printf("{A,AB,B}\n");
        else if(strcmp(m,"B")==0)printf("{A,AB,B}\n");
        else if(strcmp(m,"AB")==0)printf("{A,AB,B}\n");
        else printf("{A,B}\n");
    }else{
        if(strcmp(m,"A")==0)printf("{A,O}\n");
        if(strcmp(m,"B")==0)printf("{B,O}\n");
        if(strcmp(m,"AB")==0)printf("{A,B}\n");
        if(strcmp(m,"O")==0)printf("{O}\n");
    }
}

void checkparent(int flag,char p[],char c[]){
    char res[11];
    if(strcmp(p,"A")==0){
        if(strcmp(c,"A")==0)strcpy(res,"{A,AB,B,O}");
        else if(strcmp(c,"AB")==0)strcpy(res,"{AB,B}");
        else if(strcmp(c,"B")==0)strcpy(res,"{AB,B}");
        else strcpy(res,"{A,B,O}");
    }else if(strcmp(p,"AB")==0){
        if(strcmp(c,"A")==0)strcpy(res,"{A,AB,B,O}");
        else if(strcmp(c,"AB")==0)strcpy(res,"{A,AB,B}");
        else if(strcmp(c,"B")==0)strcpy(res,"{A,AB,B,O}");
        else strcpy(res,"impossible");
    }else if(strcmp(p,"B")==0){
        if(strcmp(c,"A")==0)strcpy(res,"{A,AB}");
        else if(strcmp(c,"AB")==0)strcpy(res,"{A,AB}");
        else if(strcmp(c,"B")==0)strcpy(res,"{A,AB,B,O}");
        else strcpy(res,"{A,B,O}");
    }else{
        if(strcmp(c,"A")==0)strcpy(res,"{A,AB}");
        else if(strcmp(c,"AB")==0)strcpy(res,"impossible");
        else if(strcmp(c,"B")==0)strcpy(res,"{AB,B}");
        else strcpy(res,"{A,B,O}");
    }
    if(flag==1){
        printf("%s %s %s\n",res,p,c);
    }else printf("%s %s %s\n",p,res,c);
}


int main(){
    char father[3],mother[3],child[3];
    scanf("%s %s %s",father,mother,child);
    if(strcmp(child,"?")==0)checkchild(father,mother);
    else if(strcmp(father,"?")==0)checkparent(1,mother,child);
    else checkparent(2,father,child);
    return 0;
}
