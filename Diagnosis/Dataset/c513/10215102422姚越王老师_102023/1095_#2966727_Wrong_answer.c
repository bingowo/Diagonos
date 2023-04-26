#include<stdio.h>
#include<string.h>
#define C 10000
#define L 20000
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
            if(i==L-1&&b[i]==1)printf("i");
            else
            {
                for(i;i<L;++i)printf("%d",b[i]);
                printf("i");return;
            }
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
            if(i==L-1&&b[i]==1)printf("i");
            else
            {
                for(i;i<L;++i)printf("%d",b[i]);
                printf("i");return;
            }
        }
    }
}
void set(int* R,int* I)
{
    int dest_R[L],dest_I[L],i,tmp,carry=0;
    for(i=L-1;i>-1;--i)
    {
        tmp=-R[i]-I[i]+carry;
        if(tmp>=10||tmp<=-10){dest_R[i]=tmp%10;carry=tmp/10;}
        else {dest_R[i]=tmp;carry=0;}
    }
    for(i=L-1;i>-1;--i)
    {
        tmp=R[i]-I[i]+carry;
        if(tmp>=10||tmp<=-10){dest_I[i]=tmp%10;carry=tmp/10;}
        else {dest_I[i]=tmp;carry=0;}
    }
    memcpy(R,dest_R,4*L);memcpy(I,dest_I,4*L);
    return;
}
void add(int* ans_R,int* ans_I,int* R,int* I)
{
    int i,tmp,carry=0;
    for(i=L-1;i>-1;--i)
    {
        tmp=ans_R[i]+R[i]+carry;
        if(tmp>=10||tmp<=-10){ans_R[i]=tmp%10;carry=tmp/10;}
        else {ans_R[i]=tmp;carry=0;}
    }
    for(i=L-1;i>-1;--i)
    {
        tmp=ans_I[i]+I[i]+carry;
        if(tmp>=10||tmp<=-10){ans_I[i]=tmp%10;carry=tmp/10;}
        else {ans_I[i]=tmp;carry=0;}
    }
}
int main()
{
    char s[4*C];scanf("%s",s);
    h2b(s);int i,j,cnt=0;for(i=0;s[i];++i)if(s[i]=='1')break;
    int a[4*C]={0};for(j=strlen(s)-1;j>=i;--j)a[cnt++]=s[j]-48;
    int R[L]={0},I[L]={0},ans_R[L]={0},ans_I[L]={0};R[L-1]=1;
    for(i=1;i<cnt;++i){set(R,I);if(a[i]==1)add(ans_R,ans_I,R,I);}
    reset(ans_R);reset(ans_I);print(ans_R,ans_I);return 0;
}
