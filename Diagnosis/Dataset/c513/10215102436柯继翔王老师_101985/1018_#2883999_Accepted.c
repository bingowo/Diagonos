#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    int prime[25]= {97,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    char s[100];
    scanf("%s",s);
    int t[26] = {0},index = 25,n = 1;;
    for(int i = strlen(s)-1; i >= 0; i--)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            t[index] += (s[i]-'0')*n;
            n *= 10;
        }
        else
        {
            index--;
            n = 1;
        }
    }
    int ans[100] = {0},m = 0;
    for(int i = index;i <= 25;i++){
        int x = prime[i - 1],y = 0,temp[100] = {0};
        while(x > 0){
            for(int j = 0;j < m;j++){
                temp[j + y] += ans[j] * (x % 10);
                if(temp[j + y] >= 10){
                    temp[j + y + 1] += temp[j + y] / 10;
                    temp[j +y] = temp[j + y] % 10;
                }
            }
            x /= 10;
            y++;
        }
        int k = t[i],l = 0;
        while(k > 0){
            temp[l] += k % 10;
            if(temp[l] >= 10){
                temp[l + 1] += temp[l] / 10;
                temp[l] = temp[l] % 10;
            }
            k /= 10;
            l++;
        }
        for(int j = 99;j >= 0;j--){
            if(temp[j] != 0){
                m = j + 1;
                break;
            }
        }
        for(int j = 0;j < m;j++){
            ans[j] = temp[j];
        }
    }
    for(int i = m - 1;i >= 0;i--){
        printf("%d",ans[i]);
    }
    if(m == 0)printf("0");
    return 0;

}
