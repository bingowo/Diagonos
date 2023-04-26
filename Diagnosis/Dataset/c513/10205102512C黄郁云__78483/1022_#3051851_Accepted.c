#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char** email;

int cmp(const void* a,const void *b){
    char * p1,*domain1,*p2,*domain2;
    p1 = *((char**)a);
    p2 = *((char**)b);
    int i = 0;
    while(*(p1+i)!= '@'){
        i++;
    }
    domain1 = (p1+1+i);
    i = 0;
    while(*(p2+i)!= '@'){
        i++;
    }
    domain2 = (p2+1+i);
   if(strcmp(domain1,domain2) == 0){
       return strcmp(p1,p2) <0;
   }
   return strcmp(domain1,domain2);

}
int main(){
    int num = 0;
    scanf("%d",&num);
    email = (char**)malloc(num*sizeof(char**));
    char s[1000001];
    char *p = 0;
    for(int i = 0;i < num;i++){
        scanf("%s",s);
        int len = strlen(s);
        p = (char*) malloc (len*sizeof(char)+1);
        strcpy(p,s);
        *(email+i) = p;
    }
    qsort(email,num,sizeof(email[0]),cmp);
    for(int i = 0; i < num;i++){
        printf("%s\n",email[i]);
    }
}