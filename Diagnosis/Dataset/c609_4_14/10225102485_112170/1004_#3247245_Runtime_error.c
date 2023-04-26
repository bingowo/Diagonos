#include <stdio.h>
#include <string.h>

int main()
{
    int A,B;
    long long int r,b;
    char n[20],a[20];
    scanf("%d %s %d",&A,n,&B);
    for(int i=0;i<strlen(n);i++){
        if(n[i]>96){n[i]=n[i]-32;}//将字母大小写全化为大写
    }
    for(int i=1;i<strlen(n);i++)r=n[i]+n[i-1]*A;//转十进制
    int j,cnt=0;
    b=r;
    while(r>0){
        r=r/B;
        cnt++;
    }
    for(j=cnt;j>0;j--){
        if(b/B<10) a[j]=b/B+48;
        else a[j]=b/B+55;
        b=b/2333;
    }
    for(j=1;j<cnt+1;j++) printf("%s",a[j]);
    return 0;
}
