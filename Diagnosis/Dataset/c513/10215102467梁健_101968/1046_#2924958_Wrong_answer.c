#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
char un[7][5]={"the","a","an","of","for","and"};
int main()
{
    int T;scanf("%d",&T);
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char a;a=getchar();
        char s[1000];gets(s);
        int res=0,judge=0;
        for(int m=0;m<strlen(s);m++){
            char word[100];int n=0;
            if(s[m]!=' ')word[n++]=s[m];
            if(s[m]==' '){
                for(int step=0;step<6;step++)if(strcmp(word,un[step])!=0)judge++;
                if(judge==6)res++;
                judge=0;
            }
        }
        printf("%d\n",res);
        res=0;
    }
    return 0;
}
