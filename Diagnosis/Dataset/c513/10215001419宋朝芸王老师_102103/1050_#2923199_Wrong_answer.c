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
        else if(strstr(s,s1) < strstr(s,s2)){
            int L1,L2;
            int lens1 = strlen(s1), lens2 = strlen(s2),
                lens = strlen(s);
            //L1 = (strstr(s,s1) - s) + lens1;
            L1 = (strstr(s,s1) - s);
            L1 += lens1;
            reverse(s2);
            reverse(s);
            L2 = lens - (strstr(s,s2) - s) - lens2;
            printf("%d\n",L2-L1);
        }
        else if(strstr(s,s1) > strstr(s,s2)){
            int L1,L2;
            int lens1 = strlen(s2), lens2 = strlen(s1),
                lens = strlen(s);
            //L1 = (strstr(s,s1) - s) + lens1;
            L1 = (strstr(s,s2) - s);
            L1 += lens1;
            reverse(s1);
            reverse(s);
            L2 = lens - (strstr(s,s1) - s) - lens2;
            printf("%d\n",L1-L2);
        }

    }
    return 0;
}
