#include <stdio.h>
#include <string.h>

#define N 500
typedef struct {
    int cnt, v[N];
} BIGINT;

BIGINT ADD1(BIGINT S, BIGINT T) {
    BIGINT R = {0};
    int i, carry = 0;
    for (i = 0; i < S.cnt && i < T.cnt; i++) {
        int temp = (S.v[i] + T.v[i] + carry);
        R.v[i] = temp % 10;
        carry = temp / 10;
    }
    while (i < S.cnt) {
        int temp = S.v[i] + carry;
        R.v[i++] = temp % 10;
        carry = temp / 10;
    }
    while (i < T.cnt) {
        int temp = T.v[i] + carry;
        R.v[i++] = temp % 10;
        carry = temp / 10;
    }
    if (carry) {
        R.v[i++] = carry % 10;
    }
    R.cnt = i;
    return R;
}
BIGINT ADD2(BIGINT S, BIGINT T) {
    BIGINT R = {0};
    int i, carry = 0;
    if(S.cnt < T.cnt)
    {
        for(int x=S.cnt;x<T.cnt;x++)
            S.v[x] = 0;
        S.cnt=T.cnt;
    }
    else if(T.cnt<S.cnt)
    {
        for(int x=T.cnt;x<S.cnt;x++)
        {
            T.v[x] = 0;
        }
        T.cnt=S.cnt;
    }
    for (i = S.cnt-1; i>=0; i--) {
        int temp = (S.v[i] + T.v[i] + carry);
        R.v[i] = temp % 10;
        carry = temp / 10;
    }
    if(carry != 0)
        R.v[S.cnt]=1;
    else R.v[S.cnt]=0;
    R.cnt = S.cnt;
    return R;
}

int main() {
    int n;
    char A[501], B[501];

    scanf("%s",A);
    scanf("%s",B);
    scanf("%d", &n);
    int len1 = strlen(A), len2 = strlen(B);
    int i, a, b, j;
    int flag1=0,flag2=0;
    for (i = 0; i < len1; i++) {
        if (A[i] == '.')
        {
            a = i;
            break;
        }
        if(i == len1)
            flag1=1;
    }
    for (i = 0; i < len2; i++) {
        if (B[i] == '.')
        {
            b = i;
            break;
        }
        if(i == len2)
            flag2 = 1;
    }
    BIGINT AI = {0}, AF = {0}, BI = {0}, BF = {0};
    for (j = 0, i = a - 1; i >= 0; i--, j++) {
        AI.v[j] = A[i] - '0';
        AI.cnt++;
    }
    for (i = a+1, j = 0; i < len1; i++, j++) {
        AF.v[j] = A[i] - '0';
        AF.cnt++;
    }
    for (j = 0, i = b - 1; i >= 0; i--, j++) {
        BI.v[j] = B[i] - '0';
        BI.cnt++;
    }
    for (i =b+1, j = 0; i < len2; i++, j++) {
        BF.v[j] = B[i] - '0';
        BF.cnt++;
    }
    BIGINT I={0}, R={0};
    if(flag1 ==1 && flag2 ==0)
    {
        I = ADD1(AI, BI);
        R = BF;
    }
    else if(flag1 ==0 && flag2==1)
    {
        I = ADD1(AI, BI);
        R = AF;
    }
    else if(flag1 ==1 && flag2 ==1)
    {
        I = ADD1(AI,BI);
    }
    else if(flag1==0 && flag2==0 )
    {
        if(a==0 && b==0)
            R= ADD2(AF,BF);
        else if(a==0 && b != 0)
        {
            I=BI;
            R= ADD2(AF,BF);
        }
        else if(a!=0 && b ==0)
        {
            I=AI;
            R= ADD2(AF,BF);
        }
        else
        {
            I = ADD1(AI, BI);
            R = ADD2(AF, BF);
        }

    }
    int carry = R.v[R.cnt];
    for(int k=0;carry != 0;k++)
    {
         int temp = I.v[k]+carry;
         I.v[k] = temp%10;
         carry=temp/10;
    }
    if (R.v[n] >= 5) {
        int carry1=1;
        for (int k = n-1; k >=0 && carry1 != 0; k--) {
            int temp=R.v[k]+carry;
            R.v[k]=temp%10;
            carry1=temp/10;
            }
        }
    for (int k = I.cnt - 1; k >= 0; k--)
        printf("%d", I.v[k]);
    printf(".");
    for (int k = 0; k <n; k++)
        printf("%d", R.v[k]);
    printf("\n");
    return 0;
}
