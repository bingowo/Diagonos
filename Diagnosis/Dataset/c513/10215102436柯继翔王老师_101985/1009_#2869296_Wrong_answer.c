#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
   int T;
   char s[300];
   scanf("%d",&T);
   getchar();
   for(int i = 0;i < T;i++){
        gets(s);
        int n = 0;
        for(int j = 0;j < strlen(s);j++){
            int x = s[j];
            for(int k = 0;k<8;k++)
                if((x >> k) &1)n++;
            }
        int r = 2,m = strlen(s) * 8;
        
        printf("%d/%d\n",n,m);
   }
    return 0;
}
