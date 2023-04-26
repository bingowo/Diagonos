#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int myMax(int a, int b){
    return a>b? a:b;
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

int BigNumCmp(char* num1, char* num2){//return Positive: num1>num2 Negative: num1<num2 Zero: num1=num2
    int len1 = strlen(num1), len2 = strlen(num2);
    if(len1!=len2){
        return len1-len2;
    }
    else{
        return strcmp(num1,num2);
    }
}

int max(int a, int b){
    return a>b? a:b;
}

int main()
{
    char A[510], B[510];
    memset(A,0,510*sizeof(char));
    memset(B,0,510*sizeof(char));
    int N = 0;
    scanf("%s%s%d",A,B,&N);
    char A1[510], A2[510], B1[510], B2[510];
    memset(A1,0,510*sizeof(char));memset(A2,0,510*sizeof(char));
    memset(B1,0,510*sizeof(char));memset(B2,0,510*sizeof(char));

    int Alen = strlen(A), Blen = strlen(B);
    int A1Cnt = 0, A2Cnt = 0, B1Cnt = 0, B2Cnt = 0;
    int i = 0, j = 0;
    while(isdigit(A[i])){
        A1[A1Cnt] = A[i];
        A1Cnt++;i++;
    }
    i++;
    while(isdigit(A[i])){
        A2[A2Cnt] = A[i];
        A2Cnt++;i++;
    }
    while(isdigit(B[j])){
        B1[B1Cnt] = B[j];
        B1Cnt++;j++;
    }
    j++;
    while(isdigit(B[j])){
        B2[B2Cnt] = B[j];
        B2Cnt++;j++;
    }

    while(strlen(A2)<strlen(B2)){
        A2[strlen(A2)] = '0';
    }
    while(strlen(B2)<strlen(A2)){
        B2[strlen(B2)] = '0';
    }
    char* whole = BigNumAdd(A1,B1);
    char* frac = BigNumAdd(A2,B2);
    if(strlen(whole)==0){
        whole[0] = '0';
        whole[1] = 0;
    }
    //printf("1whole = %s, frac = %s\n",whole, frac);
    if(strlen(frac)>max(strlen(A2),strlen(B2))){//有进位
        char* tmp = BigNumAdd(whole, "1");
        free(whole);
        whole = tmp;
        int fraclen = strlen(frac);
        for(int k = 0;k<fraclen-1;k++){
            frac[k] = frac[k+1];
        }
        frac[fraclen-1] = 0;
    }
    while(strlen(frac)<N){
        char* tmp = (char*)malloc((strlen(frac)+10)*sizeof(char));
        memset(tmp,0,(strlen(frac)+10)*sizeof(char));
        strcpy(tmp,frac);
        tmp[strlen(tmp)] = '0';
        free(frac);
        frac = tmp;
    }
    //printf("2whole = %s, frac = %s\n",whole, frac);
    char fracN = frac[N];
    frac[N] = 0;
    if(fracN>='5'){
        char* tmp = BigNumAdd(frac,"1");
        free(frac);
        frac = tmp;
    }
    //printf("3whole = %s, frac = %s\n",whole, frac);
    if(strlen(frac)>N){//有进位
        char* tmp = BigNumAdd(whole, "1");
        free(whole);
        whole = tmp;
        int fraclen = strlen(frac);
        for(int k = 0;k<fraclen-1;k++){
            frac[k] = frac[k+1];
        }
        frac[fraclen-1] = 0;
    }

    //printf("4whole = %s, frac = %s\n",whole, frac);

    //printf("A1 = %s, A2 = %s\nB1 = %s, B2 = %s\n", A1,A2,B1,B2);
    //printf("5whole = %s, frac = %s\n",whole, frac);
    printf("%s.%s",whole,frac);
    return 0;
}
