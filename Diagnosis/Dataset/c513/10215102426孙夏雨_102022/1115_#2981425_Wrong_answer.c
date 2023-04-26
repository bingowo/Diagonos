#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* c3,const void* c4)
{
    char* c1=(char* )c3;
    char* c2=(char* )c4;
    if((*c1)>(*c2)) return 1;
    else return -1;
}

int main()
{
    int T=0;
    scanf("%d",&T);
    char s[50];
    for(int t=0;t<T;t++){
        scanf("%s",s);
        int len=strlen(s),i=len-1;
        printf("case #%d:\n",t);
        for(;i>0;i--){
            if(s[i-1]<s[i]) break;
        }
        char c;
        if(i>0){
            qsort(s+i,len-i,sizeof(char),cmp);
            c=s[i];
            s[i]=s[i-1];
            s[i-1]=c;
            qsort(s+i,len-i,sizeof(char),cmp);
            printf("%s\n",s);
        }
        else{
            qsort(s,len,sizeof(char),cmp);
            printf("%c0",s[0]);
            for(int j=1;j<len;j++) printf("%c",s[j]);
            printf("\n");
        }
    }
    return 0;
}
