#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        scanf("%d",&m);



        printf("case #%d:\n",z);

        printf("%d\n",maxlen1(m));

    }

    //首先转化成二进制 还是每算一个都与前一个相比
    //先转化再算似乎有一些麻烦了
    return 0;
}

int maxlen1(int m)
{
    char s[50];
    memset(s,'\0',sizeof(s));
    int i=0;
    while(m)
    {
        s[i]=m%2+'0';
        m/=2;
        i++;
    }//最后结束的i是字符串总长度
    int ans=1,cnt=1,l=i;
    /*while(1)
    {
        int flag=0;
        while(s[j]!=s[j+1])
        {
            cnt++;
            if(j==l-2) {flag=1;break;}
            j++;
        }
        if(ans<cnt) ans=cnt;
        cnt=0;
        j++;
        if(flag==1||j>=l-1) break;
    }
    */
    //printf("%s",s);
    for(int j=0;j<l;j++)
    {
        while(s[j+1]!=s[j])
        {
            cnt++;
            j++;
        }
        if(ans<cnt) ans=cnt;
        cnt=1;
    }

    return ans;
}



