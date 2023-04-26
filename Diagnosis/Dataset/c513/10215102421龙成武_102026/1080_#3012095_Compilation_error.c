#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void div(int* a)  //只能除2的简易大数字除法器
{
    int i = 101, carry = 0;
    while (a[i] == 0 && i >= 0) i--;  //去除前导零
    //当只有一位，且值为1的时候，这个给下一位的carry会被舍弃掉
    for (;i > -1;i--)
    {
        a[i] += carry * 10;
        carry = a[i] % 2;      //当前这一位除以2后余下来的值会继续留到下一位进行运算,只可能是1或者0
        a[i] /= 2;             
    //因为这里每一位都直接/2，对最后一位也是，所以最后一为是1还是0，最后得到的都一样，所以需要在函数外对余数进行处理
        //呃，但既然都一样了，其实不处理也行
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    char s[102];
    int a1[102];

    for (int i=0;i<t;i++){
        scanf("%s",s);
       memset(a1,0,sizeof(a1));
     for (int j=0;j<strlen(s);j++)
            a1[j]=s[strlen(s)-1-j]-'0';
        int len=strlen(s)-1;
        int slen=0;
        int b[400];


        memset(b,0,sizeof(b));
        while (len!=0||a1[0]!=0){
            b[slen++]=a1[0]%2;
            div2(a1);
// /           len=100;
            while (a1[len]==0&&len>=0) len--;
            if (len<0) len=0;
//
        }

        int a2[102];

        memset(a2,0,sizeof(a2));
        int first=0;
        while (b[first]==0&&first<slen-1) first++;
        for (int j=first;j<slen;j++)
		{
            for (int k=0;k<101;k++)
                a2[k]=a2[k]*2;
            int carry=b[j];
            for (int k=0;k<101;k++){
                a2[k]+=carry;
               carry=a2[k]/10;
                a2[k]=a2[k]%10;
            }
        }
        printf("case #%d:\n",i);
        int j=101;
        while (j>=0&&a2[j]==0) j--;
       if (j==-1) printf("0");
        for (;j>=0;j--) printf("%d",a2[j]);
        printf("\n");
    }


    return 0;
}