#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    char *a = (char *)p1;
    char *b = (char *)p2;
    return strcmp(a,b);
}
typedef struct {
    char s[50];
}string;
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s1[50];
        string a[501];
        int p=0;
        char c;
        while(scanf("%s",s1)){
            if(strstr(s1,",")){
                int j=0;
                for(;j< strlen(s1);j++){
                    if(s1[j]==','){
                        a[p].s[j] = 0;
                        break;
                    }
                    a[p].s[j] = s1[j];
                }
                p++;
                strcpy(a[p].s,s1+j+1);
                p++;
            }
            else if(strstr(s1," "))
            {
                int j=0;
                for(;j< strlen(s1);j++){
                    if(s1[j]==' '){
                        a[p].s[j] = 0;
                        break;
                    }
                    a[p].s[j] = s1[j];
                }
                p++;
                strcpy(a[p].s,s1+j+1);
                p++;
            }
            else if(strstr(s1,"."))
            {
                int j=0;
                for(;j< strlen(s1);j++){
                    if(s1[j]=='.'){
                        a[p].s[j] = 0;
                        break;
                    }
                    a[p].s[j] = s1[j];
                }
                p++;
                strcpy(a[p].s,s1+j+1);
                p++;
            }
            else if(strstr(s1,"!"))
            {
                int j=0;
                for(;j< strlen(s1);j++){
                    if(s1[j]=='!'){
                        a[p].s[j] = 0;
                        break;
                    }
                    a[p].s[j] = s1[j];
                }
                p++;
                strcpy(a[p].s,s1+j+1);
                p++;
            }
            else if(strstr(s1,"?"))
            {
                int j=0;
                for(;j< strlen(s1);j++){
                    if(s1[j]=='?'){
                        a[p].s[j] = 0;
                        break;
                    }
                    a[p].s[j] = s1[j];
                }
                p++;
                strcpy(a[p].s,s1+j+1);
                p++;
            }
            else{
                strcpy(a[p].s,s1);
                p++;
            }
            c = getchar();
            if(c=='\n'){
                break;
            }
        }
        qsort(a,p,sizeof(string),cmp);
        printf("case #%d:\n%s",i,a[0].s);
        for(int q=1;q<p;q++){
            if(strcmp(a[q].s,a[q-1].s)!=0){
                printf(" %s",a[q].s);
            }
        }
        printf("\n");
    }
    return 0;
}
