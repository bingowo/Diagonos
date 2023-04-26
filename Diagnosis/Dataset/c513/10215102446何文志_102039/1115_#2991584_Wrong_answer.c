#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//字典序全排列
void swap(char *a, char *b){
    char tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}

void dictionaryArrange(char* s){
    int len = strlen(s);
    for(int i = len-1;i>0;i--){
        int j = i-1;
        if(s[j]<s[i]){
            int k = len-1;
            for(int k1 = len-1;k1>j;k1--){
                if(s[k1]>s[j]){
                    if(s[k1]<s[k]){
                        k = k1;
                    }
                }
            }
            char tmp = s[j];
            s[j] = s[k];
            s[k] = tmp;
            for(int k1=j+1,k2=len-1;k1<k2;k1++,k2--){
                char tmp = s[k1];
                s[k1] = s[k2];
                s[k2] = tmp;
            }
            break;
        }
    }

}
int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int i = 0;i<T;i++){
        char N[30];memset(N,0,30*sizeof(char));
        scanf("%s",N);

        dictionaryArrange(N);

        printf("%s\n",N);
    }


    return 0;
}
