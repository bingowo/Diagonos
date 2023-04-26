#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
char un[7][5]={"the","an","of","for","and","a"};
int main()
{
    int T;scanf("%d",&T);
    char c=getchar();
    for(int i=0;i<T;i++){
        printf("case #%d:\n",i);
        char s[1000];gets(s);
        int res=0,judge=0,n=0;
        char word[30];
        for(int m=0;m<strlen(s);m++){
            if(s[m]!=' ')word[n++]=s[m]<90?s[m]+32:s[m];
            if(s[m]==' '||m==strlen(s)-1){
                for(int step=0;step<6;step++)if(strcmp(word,un[step])!=0)judge++;

                if(judge==6)res++;
                judge=0;
                n=0;
                for(int z=0;z<30;z++)word[z]=0;
            }
        }
        printf("%d\n",res);
        res=0;
    }
    return 0;
}
