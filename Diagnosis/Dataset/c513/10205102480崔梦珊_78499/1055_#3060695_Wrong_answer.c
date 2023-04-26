#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct str
{
    char ss[1000];
    int len;
};
int cmp(const void* a,const void* b)
{
    struct str* x=(struct str*)a;
    struct str* y=(struct str*)b;
    return y->len-x->len;
}
int main()
{
    char s[1000000]={0};
    scanf("%s",s);
    int alpha[200]={-1};
    int temp=0;
    int n=0,m=0;
    struct str ans[strlen(s)];
    for(int i=0;i<strlen(s);i++)
    {
        /*printf("%c",s[i]);*/
        if(alpha[s[i]]==-1)
        {
            ans[n].ss[m]=s[i];
            alpha[s[i]]=i+1;//记录出现的位置+1！！！！！！
            m++;
            temp++;
        }
        else
        {
            ans[n].len=temp;
            temp=1;
            n++;
            m=0;
            int te=alpha[s[i]];
            i=te;//字符重复时，从重复位置+1处继续遍历
            ans[n].ss[m]=s[i];
            for(int k=0;k<200;k++)
            {
                alpha[k]=-1;
            }
            alpha[s[i]]=i+1;
            m++;
        }
    }
    ans[n].len=temp;
    qsort(ans,n+1,sizeof(ans[0]),cmp);
    /*printf("%d\n",ans[0].len);*/
    printf("%s",ans[0].ss);
}
