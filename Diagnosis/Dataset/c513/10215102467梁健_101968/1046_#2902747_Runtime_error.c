#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char jud[6][5]={{"the"},{"a"},{"an"},{"of"},{"for"},{"and"}};
int length(const void *a)
{
    char a1=(char *)a;
    int judin = 0;
    for(int z=0;z<6;z++){
        if(strcmp(a1,jud[z])!=0)judin++;
    }
    if (judin==6)return 1;
    else return 0;
}
int main()
{
    int T;
    scanf("%d",&T);
    char a=getchar();
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s[101];
        gets(s);
        char s1[20][101];
        int n=0,p=0;
        for(int m=0;m<strlen(s);m++){
            if(s[m]!=' ')s1[n][p++]=s[m];
            if(s[m]==' '){
                n++;p=0;
            }
        }
        printf("n=%d\n",n);
        int res=0;
        for(int z=0;z<n;z++){
            if(length(s1[z])==1)res++;
        }
        printf("%d\n",res);
    }
    return 0;
}
