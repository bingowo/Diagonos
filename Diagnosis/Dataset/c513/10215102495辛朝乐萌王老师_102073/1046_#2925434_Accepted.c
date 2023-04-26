#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *ignorelist[6] = {"the","a","an","of","for","and"};
int ignore(char *s)
{
    int ret=0;
    char temp[101];
    for (int i=0; i<strlen(s); i++) {
        temp[i] = tolower(s[i]);
    }
    temp[strlen(s)] = '\0';
    for (int i=0; i<6; i++) {
        if(strcmp(temp, ignorelist[i])==0){
            ret=1;
            break;;
        }
    }
    return ret;
}

int countwords(char *s)
{
    int ret =0;
    char temp[101];
    char *pa= s,*pb=NULL;
    while (*pa==' ') {
        pa++;
    }
    pb = pa;
    while (*pa) {
        pb++;
        if(*pb==' '||*pb =='\0'){
            memmove(temp, pa, pb-pa);
            temp[pb-pa] = '\0';
            if(!ignore(temp)){
                ret+=1;
            }
            while (*pb==' ') {
                pb++;
            }
            pa=pb;
        }
    }
    return ret;
}



int main(void)
{
    int t;
    scanf("%d",&t);
    char c = getchar();
    for (int i=0; i<t; i++) {
        int count;
        char s[101];
        gets(s);
        count = countwords(s);
        printf("case #%d:\n%d\n",i,count);
    }
    return 0;
}
