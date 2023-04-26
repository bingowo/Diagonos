#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct string{
    char str[17];
};

int cmp1(const void*a,const void*b){
    char d1,d2;
    d1=*((char*)a);
    d2=*((char*)b);
    if(d1>d2)return 1;
    else return -1;
}

int cmp2(const void*a,const void*b){
    struct string d1,d2;
    d1=*((struct string*)a);
    d2=*((struct string*)b);
    return strcmp(d1.str,d2.str);
}

int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char str[17];
        printf("case #%d:\n",t);
        scanf("%s",str);
        qsort(str,strlen(str),sizeof(str[0]),cmp1);
        int index=0;
        char s[17];
        s[index++]=str[0];
        for(int i=1;i<strlen(str);i++){
            if(str[i]!=str[i-1])s[index++]=str[i];
        }
        s[index]='\0';
        struct string strings[1<<index];
        for(int i=1;i<(1<<index);i++){
            int temp=0;
            for(int j=0;j<index;j++){
                if(i&(1<<j))strings[i-1].str[temp++]=s[j];
            }
            strings[i-1].str[temp]='\0';
        }
        qsort(strings,(1<<index)-1,sizeof(strings[0]),cmp2);
        for(int i=0;i<(1<<index)-1;i++)
            printf("%s\n",strings[i].str);
    }
    return 0;
}
