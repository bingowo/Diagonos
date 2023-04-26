#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
        int la,lb,maxlen,k;
        char a[1000],b[1000];
        int a1[1000]={0},b1[1000]={0};
        int i,m;
        char r[1000];
        while(scanf("%s",a)&&scanf("%s",b)){
        la=strlen(a);   //a数字的记位器
        lb=strlen(b);   //b的
        if(la>lb)
        maxlen=la;      //如果 a 位数长，那么 a 当大数
        else
        maxlen=lb;      //反之则 b
        if(la>lb||(la==lb&&strcmp(a,b)>0))       //两字符串比较（即为俩数字比较）a > b 时
        {
                m=maxlen;       //m 用来存刚才对比过后的二者中较大的位数 maxlen
                for(i=0;i<la;i++,m--)   //
                        a1[m]=a[la-1-i]-'0';//这里是进行了将输入的字符串变成数字数组的操作，
                                                //注意最高位空出来，防止溢出
                m=maxlen;
                for(i=0;i<lb;i++,m--)
                        b1[m]=b[lb-1-i]-'0';//减去字符0就是减去了32，字符串串变成了数字串存每个数字
        }
        else            //这里为后面进行b串-a串的操作做准备
        {
                m=maxlen;
                for(i=0;i<lb;i++,m--)
                        a1[m]=b[lb-1-i]-'0';    //改写a1串，注意这是else，a1存大的，此时b是大的，把b放a1中
                m=maxlen;
                for(i=0;i<la;i++,m--)
                        b1[m]=a[la-1-i]-'0';    //改写b1串
        }
        //减法（在二者在上面进行了比较为大小之后，这里直接进行大数减小数
        for(i=maxlen;i>=0;i--)
        {
                a1[i]-=b1[i];
                if(a1[i]<0)//这里是进行了借位，如 1-8，等于3，在计算机中实则是 -7+10
                {
                    a1[i]=a1[i]+10;
                    a1[i-1]--;//借了位被借位处要减一
                }
        }
        if(la<lb||(la==lb&&strcmp(a,b)<0))//两字符串比较（即为俩数字比较）a < b 时
            printf("-");//这个if就是为了输出这个负号
        for(i=1;i<=maxlen;i++)
        {
            //if(a1[1]==0) i++;
            printf("%d",a1[i]);
        }
        }
}