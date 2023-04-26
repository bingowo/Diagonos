#include <stdio.h>
#include <string.h>
#include<math.h>

// s->每三个转换为二进制装入arr1
// arr1->每六个读取转换为char
// 如果在第一步s->arr1时，s剩余不满3个，按位加0
// 如果第二部读取时为空，则转换为=

char table[100] = {0};

int main(){
    for (int i = 0; i < 26; i++){
        table[i] = 'A'+i;
        table[26+i] = 'a'+i;
        table[52+i] = '0'+i;
    }
    table[62] = '+'; table[63] = '/'; table[64] = '\0';
    int T;
    scanf("%d ", &T);
    for (int t = 0 ; t < T; t++){
        printf("case #%d:\n", t);
        char s[105];
        gets(s);
        int arr[1000] = {0};
        int index = 0;
        for (int i = 0; i < strlen(s); i++){
            int temp = (int)s[i];
            for (int j = 0; j < 8; j++){
                arr[index++] = (temp>>(7-j))&1;
            }
        }
        while (index%6 != 0){
            arr[index++] = 0;
        }
        while (index%24 != 0){
            arr[index++] = -1;
        }
        int ctemp = 0, j = 0;
        for (int i = 0; i < index; i++, j++){
            if (arr[i] == -1) {
                printf("=");
                i += 5;
                continue;
            }
            ctemp += arr[i] * pow(2, 5-j);
            if ((i+1) % 6 == 0){
                printf("%c", table[ctemp]);
                ctemp = 0;
                j = -1;
            }
        }
        printf("\n");
    }
    return 0;
}