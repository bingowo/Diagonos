#include <stdio.h>
#include <string.h>

int main()
{
    int A,B,r;
    char n[20],a[20];
    scanf("%d %s %d",&A,n,&B);
    for(int i=0;i<strlen(n);i++){
        if(n[i]>96){n[i]=n[i]-32;}//将字母大小写全化为大写
    }
    for(int i=1;i<strlen(n);i++)r=n[i]+n[i-1]*A;//转十进制
    int j=0;
    while(r>0){
        if(r/B<10) a[j]=r/B+48;
        else a[j]=r/B+55;
        r=r%B;
        j++;
    }
    for(int i=0;i<strlen(a);i++){printf("%s",a[i]);}
    return 0;
}
