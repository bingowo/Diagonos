#include<stdio.h>
#include<string.h>
#include<math.h>

typedef struct
{
    char s[1007],num;int sign;
}dis;

int cmp(const void*a,const void*b)
{
    dis c=*(dis*)a;
    dis d=*(dis*)b;
    if(c.sign==-1)//从大到小排序
    {
        if(d.sign==1) return 1;
        else if(d.sign==-1)
        {
            if(c.num>d.num) return 1;
            else if(c.num<d.num) return -1;
            else if(strcmp(c.s,d.s)<0) return -1;
            else return 1;
        }
    }
    else if(c.sign==1)
    {
        if(d.sign==-1) return -1;
        else if(d.sign==1)
        {
            if(c.num>d.num) return -1;
            else if(c.num<d.num) return 1;
            else if(strcmp(c.s,d.s)<0) return 1;
            else return -1;
        }
    }
}

void reverse1(char *s)
{
    int l=strlen(s);
    int i;
    for(i=0;i<=(l-1)/2;i++)
    {
        char p=s[i];
        s[i]=s[l-1-i];
        s[l-1-i]=p;
    }
    s[i]='\0';
}

void reverse2(int *s,int l)
{
    int i,d;
    for(i=0;i<=(l-1)/2;i++)
    {
        d=s[i];
        s[i]=s[l-1-i];
        s[l-1-i]=d;
    }
}


int main()
{
    int n,i,j,k,len,ans[1007],tmp,l,m;
    char t[1007];
    dis p[1007];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%s",t);
        len=strlen(t);
        for(j=0;j<len;j++) p[i].s[j]='0';
        if(t[0]=='-') p[i].sign=-1,j=1;//‘-’会占一位
        else p[i].sign=1,j=0;
        for(k=0;k<strlen(t);k++,j++) p[i].s[k]=t[j];
        p[i].num=k;
        p[i].s[k]='\0';
    }
    qsort(p,n,sizeof(p[0]),cmp);
    reverse1(p[0].s);reverse1(p[n-1].s);
    if(p[0].sign==1&&p[n-1].sign==1)
    {
        m=0;
        l=p[0].num;
        for(i=p[n-1].num;i<l;i++) p[n-1].s[i]='0';
        for(i=0;i<l;i++)
        {
            tmp=(p[0].s[i]-'0')-(p[n-1].s[i]-'0')-m;
            ans[i]=tmp<0?tmp+10:tmp;
            m=tmp<0 ? 1 :0;
        }
    }
    else if(p[0].sign==1&&p[n-1].sign==-1)
    {
        m=0;
        l=p[0].num>p[n-1].num?p[0].num:p[0].num;
        for(i=p[0].num;i<l;i++)  p[0].s[i]='0';
        for(i=p[n-1].num;i<l;i++) p[n-1].s[i]='0';
        p[0].s[i]='\0';p[n-1].s[i]='\0';
        for(i=0;i<l;i++)
        {
            tmp=(p[0].s[i]-'0')+(p[n-1].s[i]-'0')+m;
            ans[i]=tmp%10;
            m=tmp/10;
        }
        while(m)
        {
            ans[l++]=m%10;
            m/=10;
        }
    }
    else if(p[0].sign==-1&&p[n-1].sign==-1)
    {
        m=0;
        l=p[n-1].num;
        for(i=p[0].num;i<l;i++) p[0].s[i]='0';
        for(i=0;i<l;i++)
        {
            tmp=(p[n-1].num-'0')-(p[0].num-'0')-m;
            ans[i]=tmp<0?tmp+10:tmp;
            m=tmp<0?1:0;
        }
    }
    reverse2(ans,l);
     for(i = 0; ans[i] == 0 && i < l; i++);
    for(;i<l;i++)
        printf("%d",ans[i]);
    return 0;
}
