#include <stdio.h>
#include <string.h>

char s[110];
int ans[1010];
int tmp[1010];
int two[1010];
int num[1010];
int with[1010];
int lent,lena,lenw,lenn,lenh;

void double_solve()
{
    int len = strlen(s);
    for(int i = 0;i < len;i++)
    {
        ans[lena++] = s[i]-'0';
    }
    while(ans[0] != 0)
    {
        int t = 0;
        for(int i = 0;i < lena;i++)
        {
            t = t*10 + ans[i];
            tmp[lent++] = t/2;
            t %= 2;
        }
        two[lenw++] = t;
        memset(ans,0,sizeof(ans));
        lena = 0;
        int begin = 0;
        for(int i = 0;i < lent;i++)
        {
            if(tmp[i] != 0){
                begin = i;
                break;
            }
        }
        for(;begin < lent;begin++) ans[lena++] = tmp[begin];
        memset(tmp,0,sizeof(tmp));
        lent = 0;
    }
//    for(int i = 0;i < lenw;i++) printf("%d",two[i]);
//    printf("\n");
}

void trans()
{
    memset(tmp,0,sizeof(tmp));
    lent = lena = 0;
    int l = 0;
    for(int i = 0;i < lenw;i++)
    {
        if(two[i] == 0) l++;
        else break;
    }//去除前导0
    with[lenh++] = 1;
    if(lenw == 1) printf("1\n");
    else
    {
        if(two[lenw-1] != 0) num[lenn++] = 1;
        for(int i = lenw-2;i >= l;i--)
        {
            int t = 0;
            for(int j = 0;j < lenh;j++)    //把with*2
            {
                t = t+with[j]*2;
                tmp[lent++] = t%10;
                t /= 10;
            }
            while(t)
            {
                tmp[lent++] = t%10;
                t /= 10;
            }
            for(int j = 0;j < lent;j++) with[j] = tmp[j];
            lenh = lent;
            memset(tmp,0,sizeof(tmp));
            lent = 0;
            if(two[i] != 0)
            {
                int LEN = lenh > lenn ? lenh : lenn;
                t = 0;
                for(int j = 0;j < LEN;j++)
                {
                    t = t+num[j]+with[j];
                    num[j] = t%10;
                    t /= 10;
                }
                if(t) num[LEN++]++;
                lenn = LEN;
            }
        }
        for(int i = lenn-1;i >= 0;i--) printf("%d",num[i]);
        printf("\n");
    }
}

int main()
{
    int n;scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("case #%d:\n",i);
        scanf("%s",s);
        if(s[0] == '0') printf("0\n");
        else
        {
            double_solve();
            trans();
        }
        lent = lenn = lenh = lenw = lena = 0;
        memset(ans,0,sizeof(ans));
        memset(num,0,sizeof(num));
        memset(tmp,0,sizeof(tmp));
        memset(two,0,sizeof(two));
        memset(with,0,sizeof(with));
        memset(s,'\0',sizeof(s));
    }
    return 0;
}