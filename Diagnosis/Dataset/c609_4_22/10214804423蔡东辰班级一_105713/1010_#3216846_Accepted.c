#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char table[] = "0123456789ABCDEFGHIJ";
    int N, R, cnt = 0;
    char array[100];
    scanf("%d %d", &N, &R);
    if(N==0){
        printf("0");
        return 0;
    }
    while(N!=0){
        if(N%R < 0){
            array[cnt++] = table[N%R-R];
            N += R;
        }
        else{
            array[cnt++] = table[N%R];
        }
        N /= R;
    }
    for(int n = --cnt; n>=0; n--){
        printf("%c", array[n]);
    }
    return 0;
}
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// int find(char* s);
// int cal(int len);//计算分母
// int main()
// {
//     int result = 0;
//     int weight = 1;
//     int B, C = 0;//B分母,C分子
//     int table[3] = {0, 1, -1};//数码0、1、2分别对应的权重值。
//     char s[31];
//     scanf("%s", s);
//     if(find(s)<0){
//         for(int i=strlen(s)-1; i>=0; i--){
//             result += table[s[i]-'0'] * weight;
//             weight *= 3;
//         }
//         printf("%d", result);
//     }
//     else{
//         int len = strlen(s);
//         for(int i=find(s)-1; i >= 0; i--){
//             result += table[s[i]-'0'] * weight;
//             weight *= 3;
//         }
//         B = cal(len-find(s)-1);//B分母
//         weight = B/3;
//         for(int i = len-find(s)-1; i<len-1; i++){
//             C += table[s[i]-'0'] * weight;
//             weight /= 3;
//         }

//         if(result < 0){
//             if(C<0){
//                 printf("%d %d %d", result, C, B);
//             }
//             else{
//                 printf("%d %d %d", result+1, B+C, B);
//             }
//         }
//         else{
//             if(C>0){
//                 printf("%d %d %d", result, C, B);
//             }
//             else{
//                 printf("%d %d %d", result-1, B+C, B);
//             }
//         }
//     }

//     return 0;

// }
// int find(char* s){
//     int result = -1;
//     for(int i = 0; s[i] != '\0'; i++)
//     {
//         if(s[i] == '.'){
//             result = i;
//             break;
//         }
//     }
//     return result;
// }
// int cal(int len){
//     int result = 1;
//     for(int i=len; i>0; i--){
//         result *= 3;
//     }
//     return result;
// }
