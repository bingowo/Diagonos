#include<stdio.h>
#include<string.h>
#include<stdio.h>
int main()
{
    char index[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    int T;
    scanf("%d",&T);
    char s[105];

    for(int i=0;i<T;i++)
    {int a[420]={0};
    int cnt=0;
        scanf("%s",s);
        int l=strlen(s);
for(int j=0;j<l;j++)
{
    int b[8]={0};
    char tmp=s[j];
    int k=0;
    while(tmp!=0)
    {
        b[k]=tmp%2;
        tmp/=2;
        k++;
    }
    while(k>=0)
    {
        a[cnt]=b[k];
        cnt++;k--;
    }
}
printf("case #%d:\n",i);
int temp=cnt/6;
if((cnt%6)!=0)temp+=1;
for(int j=0;j<temp;j++)
{
    int sum=0;
    for(int k=0;k<6;k++)
    {
        sum=sum*2+a[j*6+k];

    }
    printf("%c",index[sum]);

}


if(temp%4!=0){
int temp2=4-temp%4;
for(int j=0;j<temp2;j++)
    printf("=");



}
printf("\n");
    }

}
