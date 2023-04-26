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

char* BigNumSub(char* num1,char* num2){
    if(BigNumCmp(num1,num2)<0){//num1<num2
        char* ans = BigNumSub(num2,num1);
        char tmp[strlen(ans) + 10];memset(tmp,0,(strlen(ans)+10)*sizeof(char));
        tmp[0] = '-';
        strcat(tmp,ans);
        strcpy(ans,tmp);
        return ans;
    }

    int i = strlen(num1)-1, j = strlen(num2)-1,up = 0;
    char* ans = (char*)malloc( (myMax(i,j)+10)*sizeof(char) );
    memset(ans,0,(myMax(i,j)+10)*sizeof(char));
    int ansLen = 0;
    while(i>=0||j>=0||up!=0){
        int x = i>=0? num1[i]-'0':0;
        int y = j>=0? num2[j]-'0':0;
        int cur = x-y+up;
        if(cur<0){
            ans[ansLen++] = cur + 10 + '0';
            up = -1;
        }
        else{
            ans[ansLen++] = cur + '0';
            up = 0;
        }
        i--;
        j--;
    }
    for(int i = ansLen-1;i>0;i--){//remove prefix0
        if(ans[i]=='0'){
            ans[i] = 0;
        }
        else{
            break;
        }
    }
    ansLen = strlen(ans);
    for(int i = 0,j = ansLen-1;i<j;i++,j--){//reverse
        char tmp = ans[i];
        ans[i] = ans[j];
        ans[j] = tmp;
    }
    return ans;

}
int main()
{

    while(1){
        char A[510];memset(A,0,510*sizeof(char));
        char B[510];memset(B,0,510*sizeof(char));
        if(scanf("%s%s",A,B)==EOF){
            break;
        }
        char* ans = BigNumSub(A,B);
        printf("%s\n",ans);
        free(ans);
    }
    return 0;
}
