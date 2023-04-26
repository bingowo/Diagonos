#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int A[130];

int Strcmp(char *a,char *b){
    int len1=strlen(a);
    int len2=strlen(b);
    int len=(len1 > len2)? len1:len2;
    for(int i=0;i<len;i++){
        if(a[i]!=b[i])
            return(A[a[i]]-A[b[i]]);
    }
    return len1-len2;
}

int cmp(const void* a,const void *b){
    char *x=(char *)a;
    char *y=(char *)b;
    return Strcmp(x,y);
}
int main()
{
    char c;
    while((c=getchar())!=EOF){
        while(c!='\n'){
            for(int i=0;i<52;i+=2){
                A[c]=i;
                A[c+'a'-'A']=i+1;
                c=getchar();
            }
        }
        char s[100][30];
        int i=0,j=0;
        c=getchar();
        while(c!='\n'){
            s[i][j++]=c;
            c=getchar();
            if(c==' '){
                s[i][j]='\0';
                i++;
                j=0;
                c=getchar();
            }
        s[i][j]='\0';
        }
        qsort(s,i+1,sizeof(s[0]),cmp);
        for(j=0;j<i;j++)
            printf("%s ",s[j]);
        printf("%s\n",s[j]);
    }
    return 0;
}
