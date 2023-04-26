#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
typedef struct{
    char s[300];
}shu;
int cmp(const void *a,const void *b)//从小到大排
{
    shu *s1=(shu*)a,*s2=(shu*)b;
    int len1=strlen(s1->s),len2=strlen(s2->s);
    if(s1->s[0]=='-'&&s2->s[0]!='-') return -1;
    else if(strcmp(s1->s,s2->s)==0) return -1;
    else if(s1->s[0]!='-'&&s2->s[0]=='-') return 1;
    else if(s1->s[0]!='-'&&s2->s[0]!='-')
    {
        if(len1>len2) return 1;
        else if(len1<len2) return -1;
        else if(len1==len2) return strcmp(s1->s,s2->s);
    }
    else if(s1->s[0]=='-'&&s2->s[0]=='-')
    {
        if(len1>len2) return -1;
        else if(len1<len2) return 1;
        else if(len1==len2) return -strcmp(s1->s,s2->s);
    }
}
char* sub(char *a,char *b)//a-b1
{
    if(a[0]=='-'&&b[0]=='-')//-b-a
    {
        a[0]='0';b[0]='0';
        int len=strlen(b);
        for(int i=len-1,j=strlen(a)-1;j>=0;j--,i--)
        {
            int temp=(a[i]-'0')-(b[j]-'0');
            if(temp<0)
            {
                temp=temp+10;
                a[i]=temp+'0';
                for(int k=i-1;k>=0;k--)
                {
                    if(a[k]=='0') a[k]='9';
                    else {a[k]--;break;}
                }
            }
            if(temp>=0) a[i]=temp+'0';
        }
        return b;
    }
    else if(b[0]=='-')//a+b
    {
        b[0]='0';
        if(strcmp(a,"0")==0) return b;
        int len1=strlen(a),len2=strlen(b);
        if(len1>=(len2-1))//a
        {
            for(int i=len1,j=len2;j>=0;j--,i--)
            {
                int temp=(a[i]-'0')+(b[j]-'0');
                if(temp<=9) a[i]=temp+'0';
                else if(temp>9)
                {
                    a[i]=temp-10+'0';
                    for(int k=i-1;k>=0;k--)
                    {
                        if(a[k]=='9') a[k]='0';
                        if(a[k]<'9') {a[k]++;break;}
                    }
                }
            }
            for(int i=0;i<strlen(a);i++) printf("%c",a[i]);
            printf("\n");
            return a;
        }
        else//b
        {
            for(int i=len2,j=len1;j>=0;j--,i--)
            {
                int temp=(a[i]-'0')+(b[j]-'0');
                if(temp<=9) b[i]=temp+'0';
                else if(temp>9)
                {
                    b[i]=temp-10+'0';
                    for(int k=i-1;k>=0;k--)
                    {
                        if(b[k]=='9') b[k]='0';
                        if(b[k]<'9') {b[k]++;break;}
                    }
                }
            }
            return b;
        }
    }
    else//a-b
    {
        int len=strlen(a);
        for(int i=len-1,j=strlen(b)-1;j>=0;j--,i--)
        {
            int temp=(a[i]-'0')-(b[j]-'0');
            if(temp<0)
            {
                temp=temp+10;
                a[i]=temp+'0';
                for(int k=i-1;k>=0;k--)
                {
                    if(a[k]=='0') a[k]='9';
                    else {a[k]--;break;}
                }
            }
            if(temp>=0) a[i]=temp+'0';
        }
        return a;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    shu* p=(shu*)malloc(t*sizeof(shu));
    for(int i=0;i<t;i++)
    {
        scanf("%s",p[i].s);
    }
    qsort(p,t,sizeof(p[0]),cmp);
    char ans[200];
    strcpy(ans,sub(p[t-1].s,p[0].s));
    int l=strlen(ans);
    for(int i=0;i<l;i++)
    {
        if(i==0&&ans[i]=='0') continue;
        else if(isdigit(ans[i])) printf("%c",ans[i]);
    }
    free(p);
    return 0;
}
