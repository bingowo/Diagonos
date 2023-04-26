#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int prime[26]={97,91,89,83,79,73,71,67,61,59,53,47,43,41,37,31,29,23,19,17,13,11,7,5,3,2};

void read(char*s,int*b)
//按原字符数组的顺序读入数字
{
    int p=0,cnt,i=0,l=strlen(s);
    while(i<=l)
    {
        cnt=0;
        while(s[i]!=',' && s[i]!='\0') {cnt++;i++;}
        if(s[i]==',' || s[i]=='\0')
        {
            int res=0,ex=1,n=1;
            while(cnt>0)
            {
                res+=ex*(s[i-n]-'0');
                ex*=10;n++;cnt--;
            }
            *(b+p)=res;i++;p++;
        }
    }
}

int intlen(int*p)
//求整型数组的长度
{
    int*t=p;
    int l=0;
    while(*t!=-1) {l++;t++;}
    return l;
}

void ADD(int*a,int*b,int*c)  //求和
{
    int l1=intlen(a),l2=intlen(b),carry=0,sum,d=abs(l1-l2),p=25;
    //在短数组前方补0(数组长度不相等时)
    if(l1<l2)
    {
        for(int i=l1-1;i>=0;i--) {a[i+d]=a[i];a[i]=0;}
        for(int i=l1;i<d;i++) a[i]=0;
        l1=l2;
    }
    if(l2<l1)
    {
        for(int i=l2-1;i>=0;i--) {b[i+d]=b[i];b[i]=0;}
        for(int i=l2;i<d;i++) b[i]=0;
        l2=l1;
    }
    for(int i=l1-1;i>=0;i--)
    {
        sum=a[i]+b[i]+carry;
        if(sum<prime[p]) {c[i]=sum;carry=0;}
        else {c[i]=sum-prime[p];carry=1;}
        p--;
    }
    if(carry)
    {
        for(int i=l1-1;i>=0;i--) c[i+1]=c[i];
        c[0]=1;
    }
}

void output(int*c)  //按照要求输出
{
    int l=intlen(c);
    for(int i=0;i<l-1;i++)
    {
        if(c[i]==-1) break;
        else printf("%d,",c[i]);
    }
    printf("%d\n",c[l-1]);
}

int main()
{
    int t;scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        char s[100];
        int a[26],b[26],c[26];
        for(int i=0;i<26;i++) a[i]=b[i]=c[i]=-1;
        scanf("%s",s);read(s,a);
        scanf("%s",s);read(s,b);
        ADD(a,b,c);
        printf("case #%d:\n",i);
        output(c);
    }

    return 0;
}