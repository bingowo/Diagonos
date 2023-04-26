#include <stdio.h>
#include <string.h>

#define N 501
typedef struct {
    int cnt, v[N];
} BIGINT;

BIGINT SUB(BIGINT S, BIGINT T) {
    BIGINT R = {0};
    int i, carry = 0;
    for (i = 0;i < T.cnt; i++) {
        int temp = (S.v[i] - T.v[i] - carry);
        if(temp <0)
        {
            R.v[i] = temp +10;
            carry = 1;
        }
        else
        {
            R.v[i] = temp;
            carry = 0;
        }
    }
    while (i < S.cnt) {
        int temp = S.v[i] - carry;
        if(temp <0)
        {
            R.v[i++] = temp +10;
            carry = 1;
        }
        else
        {
            R.v[i++] = temp;
            carry = 0;
        }
    }
    R.cnt = i;
    return R;
}
int main() {
    char A[501],B[501];
    while(scanf("%s%s",A,B)!= EOF)
    {
        BIGINT S={0},T={0};
        int len1 = strlen(A),len2= strlen(B);
        for(int i=len1-1,j=0;i>=0;i--,j++)
            S.v[j]=A[i]-'0';
        for(int i=len2-1,j=0;i>=0;i--,j++)
            T.v[j]=B[i]-'0';
        S.cnt=len1;T.cnt=len2;
        int sign =1;
        if((len1 < len2))
        {
            BIGINT M;
            M =S;
            S=T;
            T=M;
            sign = -1;
        }
        else if(len1==len2)
        {
            for(int j= len1-1;j>=0;j--)
            {
                if(S.v[j] > T.v[j])
                    break;
                else if(S.v[j] < T.v[j])
                {
                    BIGINT M;
                    M =S;
                    S=T;
                    T=M;
                    sign = -1;
                }
            }
        }//使得S为更大的那个数
        BIGINT R={0};
        R= SUB(S,T);
        if(sign ==-1)
            printf("-");
        int x =0;
        for(int k=R.cnt-1;k>=0;k--)
        {
            if(R.v[k] != 0)
            {
                x=k;
                break;
            }
        }
        for(int k = x;k>=0;k--)
        {
            printf("%d",R.v[k]);
        }
        printf("\n");
    }
    return 0;
}
