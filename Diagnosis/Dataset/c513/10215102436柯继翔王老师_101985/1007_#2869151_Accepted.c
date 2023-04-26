#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int T,n;
   scanf("%d",&T);
   int s[31];
   for(int i = 0;i < T;i++){
        scanf("%d",&n);
        int index = 0;
        while(n>0){
            s[index++] = n % 2;
            n /= 2;
        }
        int maxLen = 1;
        for(int j = 0;j < index - 1;j++){
            int len = 1;
            for(int k = j;k<index -1;k++){
                if(s[k] != s[k+1]){
                    len++;
                }else{
                    break;
                }
                if(len > maxLen)maxLen = len;
            }
        }
        printf("case #%d:\n",i);
        printf("%d\n",maxLen);
   }
    return 0;
}
