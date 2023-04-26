#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Add(char s[], int len){
    while(len >= 0){
        s[len] += 1;
        if(s[len] <= '9') return len;

        s[len] = '0';
        len--;
    }
    return len;
}

int main()
{
    int R,T;
    scanf("%d",&T);
    for(R = 0; R < T; R++){
        char s[102] = {'0'};
        scanf("%s",s+1);
        int len = strlen(s+1);

        int i = Add(s,len);

        for(i = 0 ; i < len; i++){
            if(s[i] == s[i+1]) break;
        }

        if(i != len){
            i = Add(s,i+1);
            while(i > 0){
                if(s[i] != s[i-1]) break;
                i = Add(s,i);
            }
            for(int j = i+1; j <= len; j++){
                s[j] = (j-i-1)%2 + '0';
            }
        }

        printf("case #%d:\n",R);
        if(s[0] != '0') printf("%c",s[0]);
        printf("%s\n",s+1);
    }
    return 0;
}
