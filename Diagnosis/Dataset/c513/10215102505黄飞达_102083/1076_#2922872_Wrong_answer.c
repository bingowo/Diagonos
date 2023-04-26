#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        char s[105] = {0}, shun[4][2] = {0};
        gets(s);
        shun[0][0]=s[0];
        int table[128] = {0};
        int slen = strlen(s), flag = 0, index = 1;
        for (int i = 1; i < slen; i++){
            if ((s[i]=='{'||s[i]=='['||s[i]=='(')&&s[i]!=shun[index-1][0]){
                shun[index++][0] = s[i];
                if (index>=3) break;
            }
        }
        for (int i = 0; i < 3; i++){
            if (shun[i][0]=='{') shun[i][1] = '}';
            else if (shun[i][0]=='[') shun[i][1] = ']';
            else if (shun[i][0]=='(') shun[i][1] = ')';
        }
        for (int i = 0; i < slen; i++) {
            table[s[i]]++;
            if (!(table[shun[0][0]]-table[shun[0][1]]>=table[shun[1][0]]-table[shun[1][1]]&&table[shun[1][0]]-table[shun[1][1]]>=table[shun[2][0]]-table[shun[2][1]])){
                flag = 1;
                printf("No\n");
                break;
            }
        }
        if (flag == 0) printf("Yes\n");
    }
    return 0;
}