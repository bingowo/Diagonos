
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<math.h>
#define MAX 500

void Input(int a[])
{
    char s[MAX+1];
    int i=0;
    scanf("%s",&s);
    while(s[i]&&s[i]!='.')
        i++;//定位小数点位置i

    for(int j =MAX,k=i-1;k>=0;j--,k--)
    {
        a[j]=s[k]-'0';
//        printf("%d",a[j]);
    }
    for(int j=MAX+1,k=i+1;k<strlen(s);j++,k++)
    {
        a[j]=s[k]-'0';
//        printf("pass\n");
//        printf("%d",a[j]);
    }
//    printf("\n");
}


void add(int* a,int* b,int n)
{
    for(int i=2*MAX;i>=MAX+n+1;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]=a[i]%10;
    }
    if (a[MAX+n+1]>=5) a[MAX+n]++;
    for (int i= MAX+n;i>=0;i--)
    {
        a[i]+=b[i];
        a[i-1]+=a[i]/10;
        a[i]=a[i]%10;
    }
}

output (int a[],int n)
{
    int i=0;
    while (a[i]==0) i++;
    if(i>=MAX+1) i=MAX;
    for(int j=i; j<MAX+1;j++)
    {
        printf("%d",a[j]);
    }
    printf(".");

    for (int k=MAX+1;k<MAX+n+1;k++)
    {

        printf("%d",a[k]);
    }
}

int main(void)
{
    int n;
    int a[2*MAX+1]={0};
    int b[2*MAX+1]={0};

    Input(a);
    Input(b);
    scanf("%d",&n);
    add(a,b,n);
    output(a,n);
//    printf("a=%d",a[0]);
    return 0;

}
