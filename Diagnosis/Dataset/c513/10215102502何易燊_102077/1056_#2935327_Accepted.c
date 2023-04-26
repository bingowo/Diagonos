
 #include <stdio.h>
#include <string.h>

int main(){
    int n;
    scanf("%d ", &n);
    const int L = 14;
    char dict[4001][15] = {0};
    for (int i=0; i<n; i++) gets(dict[i]);
    char s[5001] = {0};
    gets(s);
    int index = 0, slen = strlen(s), templen = L;
    char stemp[15] = {0};
    // char res[10001] = {0};
    while (index < slen) {
        for (int j=0; j<L; j++) stemp[j]=s[index+j];
        int i;
        for (i=L; i>0; i--){
            int flag = 0;
            stemp[i] = '\0';
            for (int j=0; j<n; j++){
                if (strcmp(stemp, dict[j])==0) {
                    if (index+i<slen) printf("%s ", dict[j]);
                    else printf("%s\n", dict[j]);
                    // strcat(res, dict[j]);
                    flag = 1;
                    break;
                }
                else if (i==1) {
                    if (index+i<slen) printf("%c ", s[index]);
                    else printf("%c\n", s[index]);
                    // strcat(res, s[index]+"");
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) break;
        }
        index += i;
    }
    // puts(res);
    return 0;
}
