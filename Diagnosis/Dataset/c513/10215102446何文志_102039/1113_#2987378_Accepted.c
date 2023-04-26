#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myMax(int a, int b){
    return a>b? a:b;
}

int BigNumCmp(char* num1, char* num2){//return Positive: num1>num2 Negative: num1<num2 Zero: num1=num2
    int len1 = strlen(num1), len2 = strlen(num2);
    if(len1!=len2){
        return len1-len2;
    }
    else{
        return strcmp(num1,num2);
    }
}

char* BigNumAdd(char* num1, char* num2){
    int i = strlen(num1)-1, j = strlen(num2)-1, up = 0;
    char* ans = (char*)malloc( (myMax(i,j)+10)*sizeof(char) );
    memset(ans,0,(myMax(i,j)+10)*sizeof(char));
    int ansLen = 0;
    while(i>=0||j>=0||up!=0){
        int x = i>=0? num1[i]-'0':0;
        int y = j>=0? num2[j]-'0':0;
        int cur = x+y+up;
        ans[ansLen++] = cur%10 + '0';
        up = cur/10;
        i--;
        j--;
    }
    for(int i = 0,j = ansLen-1;i<j;i++,j--){
        char tmp = ans[i];
        ans[i] = ans[j];
        ans[j] = tmp;
    }
    ans[ansLen++] = 0;
    return ans;
}

int main()
{
    int k = 0, n = 0;
    scanf("%d%d",&k,&n);
    char* dp[n];memset(dp,0,n*sizeof(char*));
    for(int i = 0;i<n;i++){
        dp[i] = (char*)malloc(10*sizeof(char));
        memset(dp[i],0,10*sizeof(char));
    }
    dp[0] = "0"; dp[1] = "1";
    for(int i = 2;i<n;i++){
        for(int j = i-k;j<i;j++){
            if(j>=0){
                char* tmp = BigNumAdd(dp[j], dp[i]);
                free(dp[i]);
                dp[i] = tmp;

            }
        }
    }

    //for(int i = 0;i<n;i++){
    //    printf("%s\n",dp[i]);
    //}
    printf("%s\n",dp[n-1]);
    return 0;
}
