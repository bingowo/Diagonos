#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<math.h>

int cmp(const void *a,const void *b)
{
    char a1=*(char*)a,b1=*(char *)b;
    return a1>b1?-1:1;
}
int main()
{
    int T;scanf("%d",&T);
    for(int step=0;step<T;step++){
        printf("case #%d:\n",step);
        char s[21];scanf("%s",s);
        char c[21];strcpy(c,s);
        qsort(c,strlen(c),sizeof(char),cmp);
        if(strcmp(s,c)!=0){
            for(int i=strlen(s)-1;i>0;i--){
                if(s[i]>s[i-1]){
                    char g=s[i];
                    s[i]=s[i-1];
                    s[i-1]=g;
                    break;
                }
            }
            printf("%s\n",s);
        }
        else{
            qsort(s,strlen(s),sizeof(char),strcmp);
            printf("%c",s[0]);printf("0");
            for(int i=0;i<strlen(s);i++)
                printf("%c",s[i]);
            printf("\n");
        }
    }
    return 0;
}
