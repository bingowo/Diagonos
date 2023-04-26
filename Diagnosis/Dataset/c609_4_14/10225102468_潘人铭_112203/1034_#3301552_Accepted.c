#include <stdio.h>
 #include <stdlib.h>
 #include <ctype.h>
 #include <string.h>
 #define MAX_LENGTH 1000001
 int main()
 {
    char s[MAX_LENGTH];
    fgets(s, MAX_LENGTH, stdin);  
    int len = strlen(s);
    if (s[len - 1] == '\n') {  
        s[len - 1] = '\0';
   }
    int flag = 0;
    for(int i = 0; s[i]; i++) {  
        if(s[i] == '0' && s[i + 1] == 'x' && isxdigit(s[i + 2])) {
            unsigned int ans = 0;  
            i += 2;  
            while(isxdigit(s[i])) {  
                if(s[i] >= '0' && s[i] <= '9') {
                    ans = ans * 16 + s[i] - '0';  
               } else {
                    ans = ans * 16 + s[i] - 'a' + 10;  
              }
                i++;  
           }
            printf("%u ", ans);  
            flag = 1;  
       }
   }
    if(!flag) {
        printf("-1");  
   }
    return 0;
 }