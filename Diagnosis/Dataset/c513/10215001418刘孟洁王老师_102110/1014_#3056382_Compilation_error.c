#include<stdio.h>
#include<string.h>

void reverse(char s[])
{
    int l=strlen(s);
    for(int i=0;i<=(l-1)/2;i++)
    {
        char c=s[i];
        s[i]=s[l-1-i];
        s[l-1-i]=c;
    }

}

void turnz(int z,char s[])
{
    int i=0;
    while(z)
    {
        s[i++]=z%3+'0';//不要忘记数字到字符串的转换
        z/=3;
    }
}

void turnx(int b,int x,char s[])
{
    int i=0;
    b/=3;
    while(b)
    {
        s[i++]=x/b+'0';
        x%=b;
        b/=3;
    }
    reverse(s);
}

int main()
{
    int a,b,i,j,l,l1,l2,m,tmp,x,z;
    char s1[1007]={0},s2[1007]={0},zsum[1007]={0},xsum[1007]={0};
    scanf("%d%d",&a,&b);
    z=a/b;
    x=a%b;
    turnz(z,zsum);
    l1=strlen(zsum);
    for(i=0;i<l;i++) s1[i]='1';
    l=l1;
    if(x!=0) turnx(b,x,xsum);
    l2=strlen(xsum);
    for(i=0;i<l2;i++) s2[i]='1';
    if(strlen(xsum)!=0)
    {
        for(i=0,m=0;i<l2;i++)
        {
            tmp=s2[i]-'0'+xsum[i]-'0'+m;
            xsum[i]=tmp%3+'0';
            m=tmp/3;
        }
    }
    if(!strlen(xsum)) m=0;
    for(i=0;i<l1;i++)
    {
        tmp=s1[i]-'0'+zsum[i]-'0'+m;
        zsum[i]=tmp%3;
        m=tmp/3;
    }
    //注意对进位项的处理
    while(m)
    {
        zsum[l1++]=m%3+'0';
        m/=3;
    }
    m=0;
   for(i = 0; i < len; i++)
    {
        tmp = zsum[i] - s1[i];
        tmp = tmp<0?tmp+3:tmp;
        zsum[i] = tmp + '0';
    }
    for(i = 0; i < len2; i++)
    {
        tmp = xsum[i] - s2[i];
        tmp = tmp<0?tmp+3:tmp;
        xsum[i] = tmp + '0';
    }
    for(i=0;xsum[i]=='0'&&i<l2;i++);
    reverse(zsum);
    reverse(xsum);
    for(j=0;zsum[j]=='0'&&j<l1;j++);
    if(strlen(zsum)&&strlen(xsum))
        printf("%s.%s",zsum+j,xsum+i);//字符串的特殊表示
    else if(!strlen(zsum))
    {
        if(!strlen(xsum))printf("0");
        else printf("0.%s",xsum+i);
    }
    else if(!strlen(xsum))
        printf("%s",zsum+j);
    return 0;
}
