#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int dele(char s[])
{
    int re=0,len=strlen(s),i,k=0,j;
    char ne[120];
    memset(ne,0,sizeof(char)*120);

    for(i=0;i<len;i++)
    {
        ne[i]=s[i];
    }
    memset(s,0,sizeof(char)*len);
    for(i=0;i<len;i++)
    {
        if(ne[i]==ne[i+1])
        {
            re++;
            for(j=i;j<len;j++)
            {
                if(ne[j]==ne[j+1]) re++;
                else break;
            }
            i=j;
        }
        else s[k++]=ne[i];
    }
    return re;


}

int cha(int i,char s[])
{
    int re=0,j,k=0,len=strlen(s),c;
    char xin[120];
    memset(xin,0,sizeof(char)*120);
    for(j=0;j<=i;j++)
    {
        xin[k++]=s[j];
    }
    xin[k++]=s[i];
    for(j=i+1;j<len;j++)
    {
        xin[k++]=s[j];
    }
    //printf("原始xin=%s\n",xin);
    while(1)
        {
            c=dele(xin);
            //printf("c=%d  xin=%s\n",c,xin);
            if(c==0) break;
            else
            {
                re+=c;
            }
        }
    //printf("cha内部：test:re=%d\n",re);
    return re;
}


int main()
{
    int t,i;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        char s[120],ne[110];
        int re=0,j,co,mid,m=0;
        scanf("%s",s);
        /*while(1)
        {
            co=dele(s);
            //printf("co=%d  s=%s\n",co,s);
            if(co==0) break;
            else
            {
                re+=co;
            }
        }
        printf("\n一删后：test:s=%s\n",s);*/
        int len=strlen(s);
        if(len<=0) re++;
        else if((len==2)||(len==1)) re+=2;
        else
        {
            for(j=0;j<len;j++)
            {
                mid=cha(j,s);
                if(mid>m) m=mid;
            }
            re=re+m;
        }
        printf("case #%d:\n",i);
        printf("%d\n",re);
        //printf("test:re=%d\n",re);
        //printf("test:s=%s\n",s);
    }
}