#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 1000

int ftrans(int t,char a[])//把t进制数转换为十进制数
{
    int sum=0;
    int n=strlen(a),b[N];

    for(int i=n-1;i>=0;i--)
    {
        if(a[i]>='0'&&a[i]<='9') b[i]=a[i]-'0';
        if(a[i]>='A'&&a[i]<='F') b[i]=a[i]-'A'+10;
        if(a[i]>='a'&&a[i]<='f') b[i]=a[i]-'a'+10;
    }

    int k=0;
    while(k<n)
    {
        sum=sum*t+b[k];
        k++;
    }

    return sum;
}


void strans(int a,int b)//把十进制数a转换为b进制数
{
    char c[N],h[N]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int cnt=0,r;
            while(a>0)
            {
                r=a%b;
                c[cnt]=h[r];
                a=a/b;
                cnt++;
            }
            for(int i=(cnt-1);i>=0;i--) printf("%c",c[i]);
            printf("\n");
}

int main(void)
{
    int n1,n2;
    char arr[N];
    scanf("%d %s %d",&n1,arr,&n2);

    int num=ftrans(n1,arr);
    strans(num,n2);

    return 0;
}