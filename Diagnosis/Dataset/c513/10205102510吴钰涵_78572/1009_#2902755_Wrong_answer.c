#include <stdio.h>
#include <string.h>

int num1(int num,int arr[]) {  //计算二进制中1的个数
    int i;
    int cnt=0;
    for(i=0;num/2!=0;i++) {
        arr[i]=num%2;
        if(arr[i]==1)
            cnt++;
        num=num/2;
    }
    arr[i]=num;
    cnt++;
    return cnt;
}

void gcd(int m,int n) {
    int rem=0;
    int m1=m;
    int n1=n;
    while(n%m) {
        rem=m%n;
        m=n;
        n=rem;
    }
    printf("%d/%d\n",m1/m,n1/m);
}

int main()
{
    int N;
    scanf("%d",&N);
    for(int I=0;I<N;I++) {
        char s[130];
        int a[130];
        int c;
        int j=0;
        scanf("%s",s);
        getchar();
        int len=strlen(s);
        for(int i=0;i<len;i++) {
            a[i]=(int)s[i];
        }
        int binary[10];
        int cnt=0;
        for(int i=0;i<len;i++) {
            cnt+=num1(a[i],binary);
        }
        gcd(cnt,8*len);
    }
    return 0;
}
