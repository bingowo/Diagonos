/*这个代码烂了
不得不完全重写
真糟糕*/


#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(){
    int T;
    char del[7][5]={"the","a","an","of","for","and"};
    char a[11][101];
    scanf("%d\n",&T);
    for(int t=0;t<T;t++){
        gets(a[t]);
        for(int i = 0 ; i < strlen(a[t]); i ++){
            a[t][i] = tolower(a[t][i]);
        }
        char *p=NULL;
        for(int j=0;j<=5;j++){
            
            while((p=(strstr(a[t],del[j])))!=NULL){
                if(isalpha(*(p+strlen(del[j])))){
                    *p='^';
                    continue;
                }
                while(isspace(*p)==0) {
                    *p = '^';
                    p++;
                }
                *p='^';
            }
        }
//        printf("%s\n",a[t]);
        int ans=1;
        for(int w=0;w<strlen(a[t]);w++){
            if(a[t][w]==' ') ans++;
        }

        printf("case #%d:\n",t);
        printf("%d\n",ans);
    }
}