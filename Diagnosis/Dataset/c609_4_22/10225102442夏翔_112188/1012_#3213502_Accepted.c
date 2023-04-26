#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int imax(int a, int b){
    if(a>b) return a;
    else return b;
}
int main()
{
    int T, len, count, temp, max=0;
    scanf("%d", &T);
    char s[53];
    int *ans;
    for(int k=0; k<T; k++){
        printf("case #%d:\n", k);
        scanf("%s", s);
        len = strlen(s)-2;
        ans = (int*)calloc(len*3,sizeof(int));
        for(int i=0; i<len; i++){
            ans[i] = (int)s[i+2]-48;
        }
        max = len-1;
        for(int i=0; i<len; i++){
            for(int j=max; j>=len-i-1; j--){
                temp = ans[j];
                count = j;
                while(temp!=0){
                    temp *= 10;
                    max = imax(max,count);
                    if(count==j) ans[count]=0;
                    ans[count++] += temp/8;
                    temp = temp%8;
                }
            }
        }
        int flag = 1; //判断最后一位是否会变成0
        for(int i=max; i>0; i--){
            ans[i-1] += ans[i]/10;
            ans[i] = ans[i]%10;
            if(i!=max) flag=0;
            if(flag==1&&ans[i]==0){
                flag = 0;
                max--;
            }
        }
        printf("%c%c", '0', '.');
        for(int i=0; i<=max; i++) printf("%d", ans[i]);
        printf("%c", '\n');
        free(ans);
    }
    return 0;
}
