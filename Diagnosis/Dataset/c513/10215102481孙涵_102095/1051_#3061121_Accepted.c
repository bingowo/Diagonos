#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        char s[101];
        int ans[150];
        char base64[] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/="};
        scanf("%s",s);
        int len = strlen(s);
        int pl = 0;
        for(int i = 0; i < len - len % 3; i = i + 3){
            int i1,i2,i3,i4;
            char c1,c2,c3;
            c1 = s[i];
            c2 = s[i+1];
            c3 = s[i+2];
            i1 = c1 >> 2;
            i2 = ((c1 % 4) << 4 )+ (c2 >> 4);
            i3 = ((c2 % 16)<<2 )+ (c3 >> 6);
            i4 = c3 % 64;
            ans[pl] = i1;
            ans[pl + 1] = i2;
            ans[pl + 2] = i3;
            ans[pl + 3] = i4;
            pl = pl + 4;
        }
        if(len % 3 == 1){
            char c1 = s[len - 1];
            int i1,i2;
            i1 = c1>>2;
            i2 = (c1 % 4)<<4;
            ans[pl] = i1;
            ans[pl + 1] = i2;
            ans[pl + 2] = 64;
            ans[pl + 3] = 64;
            pl = pl + 4;

        }else if(len % 3 == 2){
            char c1,c2;
            c2 = s[len - 1];
            c1 = s[len - 2];
            int i1,i2,i3;
            i1 = c1 >> 2;
            i2 = ((c1 % 4)<<4) + (c2 >> 4);
            i3 = (c2 % 16)<<2;
            ans[pl] = i1;
            ans[pl + 1] = i2;
            ans[pl + 2] = i3;
            ans[pl + 3] = 64;
            pl = pl + 4;
        }
        printf("case #%d:\n",t);
        for(int i = 0; i < pl; i++){
            printf("%c",base64[ans[i]]);
        }
        printf("\n");
    }
    return 0;
}
