#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *a){
    int len = strlen(a);
    for(int i = 0; i < len/2; i++){
        char temp = a[i];
        a[i] = a[len-i-1];
        a[len-i-1] = temp;
    }
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        char s1[81] = {'\0'}, s2[81] = {'\0'}, s[81] = {'\0'};
        scanf("%s%s%s",s1,s2,s);

        printf("case #%d:\n",R);
        if(strstr(s,s1) == NULL || strstr(s,s2) == NULL){
            printf("0\n");
        }
        else{
            int lens1 = strlen(s1), lens2 = strlen(s2),
                lens = strlen(s);
            int L1_MAX,L1_MIN,L2_MAX,L2_MIN;
            L1_MIN = (strstr(s,s1) - s) + lens1;
            L2_MIN = (strstr(s,s2) - s) + lens2;

            reverse(s);
            reverse(s1);
            reverse(s2);

            L1_MAX = lens - (strstr(s,s1) - s) - lens1;
            L2_MAX = lens - (strstr(s,s2) - s) - lens2;

            int ans = L2_MAX - L1_MIN;
            if(L1_MAX - L2_MIN > ans) ans = L1_MAX - L2_MIN;

            printf("%d\n",ans);
        }

    }
    return 0;
}
