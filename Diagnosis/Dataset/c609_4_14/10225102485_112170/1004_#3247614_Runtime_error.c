#include <stdio.h>
#include <string.h>

int main()
{
    int A,B;
    int r,b;
    char n[20],a[20];
    scanf("%d %s %d",&A,n,&B);
    int len=strlen(n),i;
    for(i=0;i<len;i++){
        if(n[i]>96){n[i]=n[i]-32;}//将字母大小写全化为大写
        n[i]=n[i]-55;//转为对应的数字10-32
    }
    if(len==1) r=n[i]*A;
    else{
        r=n[0]*A+n[1];
        for(i=1;i<len-1;i++) r=r*A+n[i+1];//转十进制
    }
    int j,cnt=0;
    b=r;
    while(r>0){
        r=r/B;
        cnt++;
    }
    for(j=cnt;j>0;j--){
        if(b%B<10) a[j]=b%B+48;
        else a[j]=b%B+55;
        b=b/B;
    }
    for(j=1;j<cnt+1;j++) printf("%s",a[j]);
    return 0;
}
