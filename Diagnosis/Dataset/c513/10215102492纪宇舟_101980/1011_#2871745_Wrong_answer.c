#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
char chr[1005];
int main()
{
    int bin[5],flag=0;
    scanf("%s",chr);
    int L=strlen(chr);
    int a,b,qr=1,qi=0;
    for(int i=2;i<L;i++)
    {
        int x;
        if(chr[i]>='0'&&chr[i]<='9')x=chr[i]-'0';
        else x=chr[i]-'A'+10;
        for(int j=4;j>=1;j--){bin[j]=x%2;x/=2;}
        for(int j=1;j<=4;j++)
        {
            if(i==2&&bin[j]==0&&flag==0)continue;
            if(i==2&&bin[j]==1&&flag==0){flag=1;continue;}
            a=bin[j]-qr-qi;b=qr-qi;
            //printf("%d %d %d %d %d\n",j,qr,qi,a,b);
            qr=a;qi=b;
            //printf("%d %d\n",a,b);
        }
    }
    if(a!=0)if(b>0)printf("%d+",a);else printf("%d",a);
    if(b!=0)if(b==1)printf("i");else if(b==-1)printf("-i");else printf("%di",b);
    return 0;
}