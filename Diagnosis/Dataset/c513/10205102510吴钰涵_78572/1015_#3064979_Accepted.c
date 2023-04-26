/*  素数进制A+B  */

#include <stdio.h>
#include <string.h>

int Char_to_Int(char L1[],int L2[],int l) {  //对字符串进行处理，删去‘,’
    int pac=25;
    for(int i=l-1;i>=0;i--) {
        if(L1[i]!=',' && (L1[i-1]==',' || i==0)) {
            L2[pac]=L1[i]-'0';
            pac--;
        }
        else if(L1[i]!=',' && L1[i-1]!=',') {
            int x=L1[i]-'0';
            int y=L1[i-1]-'0';
            L2[pac]=y*10+x;
            pac--;
            if(i==1)
                break;
            else
                i--;
        }
    }
    return pac;
}

void ADD(int A[],int B[],int C[],int p) {
    int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};
    int digit=0;  //digit表示进位
    for(int i=25;i>=p;i--) {
        int x=A[i]+B[i];
        if(digit==0) {
            if(x<prime[i])
                C[i+1]=x;
            else {
                C[i+1]=x%prime[i];
                digit=1;
            }
        }
        else {
            if(x<(prime[i]-1)) {
                C[i+1]=x+1;
                digit=0;
            }
            else
                C[i+1]=(x+1)%prime[i];
        }
    }
}

int main() {
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++) {
        char s[60];  //用于输入数据（存在字符','）
        int a[26]={0};
        int b[26]={0};
        int c[30]={0};
        scanf("%s",s);
        int len=strlen(s);
        int p1=Char_to_Int(s,a,len);
        scanf("%s",s);
        len=strlen(s);
        int p2=Char_to_Int(s,b,len);
        int p0;
        if(p1<p2)
            p0=p1;
        else
            p0=p2;
        ADD(a,b,c,p0);
        int p=0;
        for(;p<27;p++) {
            if(c[p]!=0)
                break;
        }
        printf("case #%d:\n",t);
        for(;p<26;p++)
            printf("%d,",c[p]);
        printf("%d\n",c[p]);

    }
    return 0;
}