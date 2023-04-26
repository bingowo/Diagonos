//a+bi=r-qr-qi+(qr-qi)i
#include<stdio.h>
#include<string.h>
#define C 1000
#define L 2000
void h2b(char* s)
{
    char ans[4*C];
    int i,cnt=0,tmp;
    if(s[0]=='0'&&s[1]=='x')i=2;
    for(i;s[i];++i)
    {
        tmp=4*cnt;
        switch (s[i])
        {
            case '0':{ans[tmp]='0';ans[tmp+1]='0';ans[tmp+2]='0';ans[tmp+3]='0';break;}
            case '1':{ans[tmp]='0';ans[tmp+1]='0';ans[tmp+2]='0';ans[tmp+3]='1';break;}
            case '2':{ans[tmp]='0';ans[tmp+1]='0';ans[tmp+2]='1';ans[tmp+3]='0';break;}
            case '3':{ans[tmp]='0';ans[tmp+1]='0';ans[tmp+2]='1';ans[tmp+3]='1';break;}
            case '4':{ans[tmp]='0';ans[tmp+1]='1';ans[tmp+2]='0';ans[tmp+3]='0';break;}
            case '5':{ans[tmp]='0';ans[tmp+1]='1';ans[tmp+2]='0';ans[tmp+3]='1';break;}
            case '6':{ans[tmp]='0';ans[tmp+1]='1';ans[tmp+2]='1';ans[tmp+3]='0';break;}
            case '7':{ans[tmp]='0';ans[tmp+1]='1';ans[tmp+2]='1';ans[tmp+3]='1';break;}
            case '8':{ans[tmp]='1';ans[tmp+1]='0';ans[tmp+2]='0';ans[tmp+3]='0';break;}
            case '9':{ans[tmp]='1';ans[tmp+1]='0';ans[tmp+2]='0';ans[tmp+3]='1';break;}
            case 'A':{ans[tmp]='1';ans[tmp+1]='0';ans[tmp+2]='1';ans[tmp+3]='0';break;}
            case 'B':{ans[tmp]='1';ans[tmp+1]='0';ans[tmp+2]='1';ans[tmp+3]='1';break;}
            case 'C':{ans[tmp]='1';ans[tmp+1]='1';ans[tmp+2]='0';ans[tmp+3]='0';break;}
            case 'D':{ans[tmp]='1';ans[tmp+1]='1';ans[tmp+2]='0';ans[tmp+3]='1';break;}
            case 'E':{ans[tmp]='1';ans[tmp+1]='1';ans[tmp+2]='1';ans[tmp+3]='0';break;}
            case 'F':{ans[tmp]='1';ans[tmp+1]='1';ans[tmp+2]='1';ans[tmp+3]='1';break;}
        }
        cnt++;
    }
    ans[4*cnt]='\0';
    strcpy(s,ans);
    return;
}
void add(int *a,int* b)
{
    int i,tmp,carry=0;
    for(i=L-1;i>-1;--i)
    {
        tmp=-(a[i]+b[i]+carry);
        if(tmp>=10||tmp<=-10){a[i]=tmp%10;carry=tmp/10;}
        else {a[i]=tmp;carry=0;}
    }
}
void count_real(int r,int* a,int *b)
{
    add(a,b);int i,tmp,carry=1;
    if(!r)return;
    for(i=L-1;i>0;--i)
    {
        tmp=a[i]+carry;
        if(tmp>=10){a[i]=1;carry=1;}
        else {a[i]=tmp,carry=0;}
        if(!carry)break;
    }
}
void count_image(int* a,int* b)
{
    int i,carry=0,tmp;
    for(i=L-1;i>-1;--i)
    {
        tmp=a[i]-b[i]+carry;
        if(tmp>=10||tmp<=-10){a[i]=tmp%10;carry=tmp/10;}
        else {a[i]=tmp;carry=0;}
    }
}
void set(int* a,int* b,int r)
{
    int tmpa1[L],tmpb1[L],tmpa2[L],tmpb2[L];
    memcpy(tmpa1,a,4*L);memcpy(tmpb1,b,4*L);memcpy(tmpa2,a,4*L);memcpy(tmpb2,b,4*L);
    count_real(r,tmpa1,tmpb1);count_image(tmpa2,tmpb2);
    memcpy(a,tmpa1,4*L);memcpy(b,tmpa2,4*L);
}
void reset(int *a)
{
    int i,j,flag;
    for(i=0;i<L;++i)if(a[i])break;
    if(a[i]<0)flag=-1; else flag=1;
    a[0]=flag;
    for(i;i<L;++i)a[i]*=flag;
    for(i=L-1;i>0;--i)
    {
        if(a[i]<0)
        {
            j=i;while(i>0&&a[i]<=0)i--;
            a[i]--;for(++i;i<j;++i)a[i]+=9;
            a[i]+=10;
        }
    }
}
void print(const int* a,const int* b)
{
    int i,j;
    for(i=1;i<L;++i)if(a[i])break;
    if(i==L)
    {
        for(i=1;i<L;++i)if(b[i])break;
        if(i==L){printf("0");return;}
        else
        {
            if(b[0]==-1)printf("-");
            for(i;i<L;++i)printf("%d",b[i]);
            printf("i");return;
        }
    }
    else
    {
        if(a[0]==-1)printf("-");
        for(i;i<L;++i)printf("%d",a[i]);
        for(i=1;i<L;++i)if(b[i])break;
        if(i==L){return;}
        else
        {
            if(b[0]==-1)printf("-"); else printf("+");
            for(i;i<L;++i)printf("%d",b[i]);
            printf("i");return;
        }
    }
}
int main()
{
    char s[4*C];int i,j;scanf("%s",s);
    h2b(s);for(i=0;s[i];++i)if(s[i]=='1')break;
    int a[L]={0},b[L]={0};
    for(i;s[i];++i)set(a,b,s[i]-48);
    reset(a);reset(b);
    print(a,b);
    return 0;
}
