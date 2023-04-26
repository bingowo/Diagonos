#include <stdio.h>
#include <string.h>
#define N 1000

typedef struct{
    int cnt;
    char v[N];
}BIGINT;

BIGINT ADD(BIGINT a,BIGINT b){
    int carry=0,j,t;
    BIGINT R={0};
    for(j=0;j<a.cnt || j<b.cnt;j++){
        t=a.v[j]+b.v[j]-2*'0'+carry;
        R.v[j]=t%10+'0';
        carry=t/10;
        R.cnt++;
    }
    if(j==a.cnt){
        for(;j<b.cnt;j++){
            t=b.v[j]-'0'+carry;
            R.v[j]=t%10+'0';
            carry=t/10;
            R.cnt++;
        }
    }
    if(j==b.cnt){
        for(;j<a.cnt;j++){
            t=a.v[j]-'0'+carry;
            R.v[j]=t%10+'0';
            carry=t/10;
            R.cnt++;
        }
    }
    while(carry>0){
        R.v[R.cnt++]=carry%10+'0';
        carry/=10;
    }
    return R;
}

void printBIGINT(BIGINT R){
    for(int i=R.cnt-1;i>=0;i--) printf("%c",R.v[i]);
}

void swap(char *left,char *right){
    while(left<right){
        char temp=*left;
        *left=*right;
        *right=temp;
        left++;
        right--;
    }
}

int main()
{
    BIGINT s1={0},s2={0};
    scanf("%s",s1.v);
    scanf("%s",s2.v);
    swap(&s1.v[0],&s1.v[strlen(s1.v)-1]);
    swap(&s2.v[0],&s2.v[strlen(s2.v)-1]);
    for(int i=0;s1.v[i];i++)  s1.cnt++;
    for(int i=0;s2.v[i];i++)  s2.cnt++;
    printBIGINT(ADD(s1,s2));
    return 0;
}
