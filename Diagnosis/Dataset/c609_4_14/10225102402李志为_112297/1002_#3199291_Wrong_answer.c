#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char s[100]={0};
    void jinzhi(int a,char s[])
    {
        int t=0,j=0;
        char p;
        while(a){
            t = a%2;
            s[j]=t+'0';
            a=a/2;
            j++;
        }
        j--;
        for(int i=0;i<j;i++,j--){
            p = s[i];
            s[i]=s[j];
            s[j]=p;
        }
    }
    int a,b,c,sum=0,sum1;
    scanf("%d",&a);
    for(int i=0;i<a;i++){
        sum = 0;
        for(int x=0;x<100;x++) s[x]=0;
        scanf("%d",&b);
        jinzhi(b,s);//已经转化成二进制数了
        c = strlen(s);
        for(int j=0;j<c-1;j++){
            sum1=1;
            while(s[j+1]!=s[j]&&j<c-1){
                sum1++;
                j++;
            }
            if(sum1>sum) sum=sum1;
        }
        printf("case# %d:\n%d\n",i,sum);
    }
    return 0;
}
