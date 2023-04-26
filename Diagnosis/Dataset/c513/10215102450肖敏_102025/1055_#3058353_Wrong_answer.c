#include <stdio.h>
#include <string.h>

#define N 1000001

int main() {
    char s[N];
    scanf("%s", s);
    int alpha[128];
    int len = strlen(s);
    int l = 1, loc=0;
    for (int i = 0; i < len; i++) {
        int k = 0;
        memset(alpha, 0, sizeof(alpha));
        for(int j=i;j<len;j++,k++)
        {
            if(alpha[s[j]]>0)
            {
                if(l<k)
                {
                    l=k;
                    loc=i;
                }
                break;
            }
            else
                alpha[s[j]]++;
        }
    }
    for(int i=0;i<l;i++)
        printf("%c",s[loc+i]);
    return 0;
}
