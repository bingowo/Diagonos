#include<stdio.h>
#include<string.h>
int main()
{
    int T,cnt=0;
    scanf("%d",&T);
    while(T--){
        char octal[55],decimal[165];
        scanf("%s",octal);
        int len=strlen(octal)-1,num,j,n=0,r;
        for(;len>1;len--){
            num=octal[len]-'0';
            j=0;
            do{
                num*=10;
                if(j<n)
                    r=num+decimal[j]-'0';
                else
                    r=num;
                decimal[j++]=r/8+'0';//十进制小数位
                num=r%8;
            }while(r!=0||j<n);
            n=j;
        }
        decimal[n]='\0';
        for(;;n--){
            if(decimal[n-1]=='0')n--;
            else break;
        }
        //去0
        printf("case #%d:\n0.",cnt++);
        for(int i=0;i<n+1;i++)
            printf("%c",decimal[i]);
    }
    return 0;
}
