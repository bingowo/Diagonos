#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int yue(int a,int b)
{
    if((a==0)||(b==0)) return 0;
    if(a==b) return a;
    else if(a>b)
    {
        if(a%b==0) return b;
        else
        {
            a=a%b;
            return yue(b,a);
        }
    }
    else return yue(b,a);
}

int numof(int st,int en,char *s)
{
    int i,j,len=strlen(s);
    int re=0;
    if(st>en) return 1;
    for(i=st;i<=en;i++)
    {
        if(s[i]=='x') return 0;
        re*=10;
        re+=s[i]-'0';
    }
    /*for(i=st;i<=en;i++)
    {
        printf("s[%d]=%c  ",i,s[i]);
    }
    printf("\n");*/
    return re;
}

void xishu(char *s,int *c)
{
    int len=strlen(s);
    int i,k=0,j;
    for(i=0;i<len;i++)
    {
        if(s[i]=='x')
        {
            if(s[i+1]=='^')
            {
                k=s[i+2]-'0';
                for(j=i-1;j>=0;j--)
                {
                    if(s[j]=='+') {c[k]=numof(j+1,i-1,s);break;}
                    else if(s[j]=='-') {c[k]=-numof(j+1,i-1,s);break;}
                }
                if(j==-1) c[k]=numof(0,i-1,s);
            }
            else
            {
                k=1;
                for(j=i-1;j>=0;j--)
                {
                    if(s[j]=='+') {c[k]=numof(j+1,i-1,s);break;}
                    else if(s[j]=='-') {c[k]=-numof(j+1,i-1,s);break;}
                }
                if(j==-1) c[k]=numof(0,i-1,s);
            }
        }

        if(i==len-1)
        {
            k=0;
            for(j=i;j>=0;j--)
            {
                if(s[j]=='+') {c[k]=numof(j+1,i,s);break;}
                else if(s[j]=='-') {c[k]=-numof(j+1,i,s);break;}
            }
            if(j==-1) c[k]=numof(0,i,s);
        }
    }
    //for(i=0;i<5;i++) printf("%d x ^ %d\n",c[i],i);
}

int kekaifang(int mid)
{
    int i;
    for(i=0;i<=mid;i++)
    {
        if(pow(i,2)>mid) break;
        if(pow(i,2)==mid) return i;
    }
    return -1;
}

void shuchu(int a1,int c1,int a2,int c2)
{
    if(a1<a2) printf("%d %d %d %d",a1,c1,a2,c2);
    else if(a1>a2) printf("%d %d %d %d",a2,c2,a1,c1);
    else
    {
        if(c1<=c2) printf("%d %d %d %d",a1,c1,a2,c2);
        else printf("%d %d %d %d",a2,c2,a1,c1);
    }
}

int main()
{
    char s[50];
    scanf("%s",s);
    int c[5];
    memset(c,0,sizeof(int)*5);
    int mid;
    xishu(s,c);

    mid=pow(c[1],2)-(4*c[0]*c[2]);
    //printf("test:mid kaiqian=%d\n",mid);
    mid=kekaifang(mid);
    //printf("test:mid kaihou=%d\n",mid);
    if(mid>=0)
    {
        int fb,fa;
        int a1,c1,a2,c2;
        fb=-c[1];
        fa=2*c[2];
        //printf("test: fa=%d\n",fa);
        //printf("test: fb=%d\n",fb);
        if(yue(abs(fb+mid),abs(fa))==0) {c1=0;a1=1;}
        else {
        c1=-((fb+mid)/yue(abs(fb+mid),abs(fa)));
        a1=fa/yue(abs(fb+mid),abs(fa));}
        if(yue(abs(fb-mid),abs(fa))==0) {c2=0;a2=1;}
        else {
        c2=-((fb-mid)/yue(abs(fb-mid),abs(fa)));
        a2=fa/yue(abs(fb-mid),abs(fa));}
        shuchu(a1,c1,a2,c2);
    }
    else printf("No Answer!");

}
