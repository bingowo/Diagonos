#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    char a[10010];
    int p;
    scanf("%d%s%d",&n,a,&p);
    int num=0;
    for (int i=0;i<strlen(a);i++){
        num*=n;
        if (a[i]>='0' && a[i]<='9') num+=a[i]-'0';
        else if (a[i]>='A' && a[i]<='Z') num+=a[i]-'A'+10;
        else num+=a[i]-'a'+10;
    }
    if (num==0){
        printf("0\n");
        return 0;
    }
    char b[100010];
    int j=0;
    while (num!=0){
        if (num%p<10) b[j]=num%p+'0';
        else b[j]=num%p-10+'A';
        num=num/p;
        j++;
    }
    for (int i=j-1;i>=0;i--){
        printf("%c",b[i]);
    }
    printf("\n");
    return 0;
}
