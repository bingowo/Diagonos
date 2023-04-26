#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void minus(int *a,int *b,int len,int *res)
{
    int next=0,tmp;
    for(int i=0;i<len;i++)
            {
            if(a[999-i]+next>=b[999-i])
            {
                res[999-i]=a[999-i]+next-b[999-i];
                next=0;
            }
            else
            {
                tmp=0;
                while(a[999-i]+next<b[999-i])
                {
                    next+=10;
                    tmp++;
                }
                res[999-i]=a[999-i]+next-b[999-i];
                next=-tmp;
            }
    }
}
int main()
{
    char a[1000],b[1000],ta[1000],tb[1000];
    int bj[1000],j[1000],res[1000],len=1000;
    for(int i=0;i<1000;i++)
    {
        bj[i]=0;
        j[i]=0;
        res[i]=0;
        ta[i]='0';
        tb[i]='0';
    }
    int n,flag1,flag2,sig;
    scanf("%s %s %d",a,b,&n);
    flag1=strlen(a)-1;
    flag2=strlen(b)-1;
    int w=0;
    for(int i=0;i<strlen(a);i++) if(a[i]=='.')
    {
        flag1=i;
        w=1;
    }
    if(w!=0)
    {
    for(int i=0;i<flag1;i++) a[flag1-i]=a[flag1-i-1];
    a[0]='0';
    }
    w=0;
    for(int i=0;i<strlen(b);i++) if(b[i]=='.')
    {
        flag2=i;
        w=1;
    }
    if(w!=0)
    {
    for(int i=0;i<flag2;i++) b[flag2-i]=b[flag2-i-1];
    b[0]='0';
    }
    ta[999]='\0';
    tb[999]='\0';
    int sup=strlen(a)-flag1-strlen(b)+flag2;
    int flo=(strlen(a)-flag1)>(strlen(b)-flag2)?(strlen(a)-flag1-1):(strlen(b)-flag2-1);
    if(sup<=0)
    {
        sup=-sup;
        for(int i=0;i<strlen(a);i++) ta[998-i-sup]=a[strlen(a)-1-i];
        for(int i=0;i<strlen(b);i++) tb[998-i]=b[strlen(b)-1-i];
    }
    else
    {
        for(int i=0;i<strlen(b);i++) tb[998-i-sup]=b[strlen(b)-1-i];
        for(int i=0;i<strlen(a);i++) ta[998-i]=a[strlen(a)-1-i];
    }
    sig=strcmp(ta,tb);
    if(sig==0)
    {
        printf("0");
        return 0;
    }
    if(sig>0)
    {
        for(int i=0;i<980;i++) bj[999-i]=ta[998-i]-'0';
        for(int i=0;i<980;i++) j[999-i]=tb[998-i]-'0';
    }
    if(sig<0)
    {
        for(int i=0;i<980;i++) bj[999-i]=tb[998-i]-'0';
        for(int i=0;i<980;i++) j[999-i]=ta[998-i]-'0';
    }
    minus(bj,j,len,res);
    int  next=1,tmp;
    if(res[999-flo+n+1]>4)
    {

        for(int i=999-flo+n;i>=0;i--)
        {
            tmp=res[i]+next;
            next=tmp/10;
            res[i]=tmp%10;
            if(next==0) break;;
        }
    }
    int test=0;
    if(sig==-1) printf("-");
    for(int i=0;i<999-flo+1;i++)
    {
       if(res[i]!=0) test=1;
       if(test==1) printf("%d",res[i]);
    }
    if(test==0) printf("0");
    printf(".");
    for(int i=999-flo+1;i<999-flo+n+1&&i<1000;i++)
    {
       printf("%d",res[i]);
    }
    for(int i=0;i<n-flo;i++) printf("0");
}
