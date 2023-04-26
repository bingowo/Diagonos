#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>






int main()
{
    char s[600];
    int a[600];
    int b[600];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    scanf("%s",s);
    int mul_a =0;
    int mul_b=0;
    int pa=0;
    int pb =0;
    for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='.')
        {
            mul_a = strlen(s)-i-1;
        }
        else
        {
            a[pa++] = s[i]-'0';
        }
    }
    scanf("%s",s);
        for(int i=strlen(s)-1;i>=0;i--)
    {
        if(s[i]=='.')
        {
            mul_b = strlen(s)-i-1;
        }
        else
        {
            b[pb++] = s[i]-'0';
        }
    }
    int n;
    scanf("%d",&n);


    int *p = (mul_a<mul_b)?a:b;
    int l = (mul_a<mul_b)?pa:pb;
    int mul_s = (int)abs(mul_a-mul_b);
    for(int i =l-1;i>=0;i--)
    {
        p[i+mul_s] = p[i];
    }
    for(int x =0;x<mul_s;x++)p[x]=0;

    int mul = (mul_a<mul_b)?mul_b:mul_a;
    int carry =0;
    if(mul_a<mul_b)pa+=mul_s;
    else pb+=mul_s;
    int len = (pa<pb)?pb:pa;

    int res[600];
    memset(res,0,sizeof(res));
    for(int i=0;i< len;i++)
    {
        int p1 = a[i] -b[i] +carry;
        if(p1<0)
        {
            p1+=10;
            carry = -1;
        }
        else carry =0;
        res[i] = p1;
    }
    int flag =0;//判断是否为负数

    int mid[600] ={0};
    mid[len] = 1;


    if(carry)
    {
    carry =0;
    flag = 1;
    for(int i=0;i< len;i++)
    {
        int p1 = mid[i] -res[i] +carry;
        if(p1<0)
        {
            p1+=10;
            carry = -1;
        }
        else carry =0;
        res[i] = p1;
    }
    }

    if(mul-n-1>=0&&res[mul-n-1]>4)
    {
    carry =1;
    int pp=mul -n;
    while(carry==1)
        {
            int p1 = res[pp] +carry;
        if(p1>=10)
        {
            p1-=10;
            carry = 1;
        }
        else carry =0;
        res[pp] = p1;
        pp++;
    }

    }


    if(flag)printf("-");
    int point = len;
    while(res[point]==0&&point>=mul)point--;
    if(point ==mul-1)printf("0");
    while(point>=mul)
    {
        printf("%d",res[point]);
        point--;
    }
    printf(".");
    while(point>=0&&point>=mul-n)
    {
        printf("%d",res[point]);
        point--;
    }
    if(mul<n)for(int j=0;j<n-mul;j++)printf("0");


//    for(int k =0;k<len;k++)
//    {
//        printf("%d\n",res[k]);
//    }
//    printf("mul=%d",mul);
    return 0;
}
