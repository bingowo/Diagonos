#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        char s[105] = {0};
        gets(s);
        char turn[8][4] = {"{[[","[((","({)",")](","]}[","}){"};
        int slen = strlen(s), count = 0, flag = 0;
        for (int i = 0; i < slen; i++) {
            for (int j = 0; j < 7; j++){
                if (s[i] == turn[j][0]) {
                    if (j <= 2) count++;
                    else count--;
                    if (count==0) {break;}
                    if (i+1<slen && s[i+1]!=turn[j][1] && s[i+1]!=turn[j][2]) {printf("No\n");flag = 1;}
                    break;
                } 
            }
            if (flag == 1) break;
        }
        if (flag==0) {
            if (count!=0) printf("No\n");
            else printf("Yes\n");
        }
    }
    return 0;
}
