#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int T;
    scanf("%d",&T);
    for (int i = 0; i < T; i++) {
        char s[101];
        scanf("%s",s);
        int len = strlen(s);

        char ans[1000] = {'0'};
        char base64[64] = {"ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"};

        int a[1000] = {0};

        for (int j = 0; j < len; j++) {
            int ch = (int)s[j]; //ASCII
            for (int k = 7+j*8; k >= j*8; k--) {
                a[k] = ch % 2;
                 ch /= 2;
            }
        }


        //此时 a[]数组里面就都是二进制数，在分为四组、每组6位，
        int j = 0, k = 0;
        while (j <= len * 8) {
            int tmp = 0;
            if (j == 0) {
                while (j != 6){
                    tmp = tmp * 2 + a[j];
                    j++;
                }
            }
            else {
                while ((j % 6) != 0) {
                    tmp = tmp * 2 + a[j-1];
                    j++;
                }
                tmp = tmp * 2 + a[j-1];
            }


            ans[k++] = base64[tmp];
            j++;
        }

        if (len%3 == 1) {
            ans[k++] = '=';
            ans[k++] = '=';
        }

        if (len%3 == 2) {
            ans[k++] = '=';
        }

        printf("case #%d:\n",i);
        printf("%s\n",ans);
    }
    return 0;
}
