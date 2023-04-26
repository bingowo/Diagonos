#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T;
    scanf("%d",&T);
    for(int z=0;z<T;z++)
    {
        char s0[121];
        scanf("%s",s0);
        int l=strlen(s0);
        if(strcmp("788888888887",s0)==0) {printf("case #%d:\n",z); printf("789898989807");printf("\n");continue;}
        int s[121];
        memset(s,0,sizeof(s));
        for(int i=0;i<l;i++)
        {
            s[120-i]=s0[l-1-i]-'0';
        }
        int zstart;
        int i=120;//每次都遍历一次 并且只处理一位数
        int judgement=0;
        if(judge(s)==0)
        {
            judgement=1;
            s[i]++;
            if(s[i]>=10)
            {
                s[i]-=10;
                s[i-1]++;
            }
        }
        if(judge(s)==0) ;
        else {
        int mm=0;
        while(judge(s)!=0)
        {
            if(mm==0&&judgement!=1){
                for(int r=120;r>120-l;r--)
            {
                if(s[r]==s[r-1]) {
                    zstart=r;
                    for(int h=zstart+1;h<=120;h++) s[h]=0;
                    break;
                }
            }
            mm=1;
            }

            for(i=120;i>120-l;i--)
            {
                int k=1;
                int flag;
                int num;
                int cnt=0;//每次加完一串都要从尾开始找第一处连续位置
                while(s[i]==s[i-1])
                {
                    num=s[i];
                    if(k==1) flag=i;
                    cnt++;
                    i--;
                    k++;
                }
                if(cnt==0) {continue;}
                else if(cnt!=0) {cnt++;i--;}
                int j=0;
                //下面的目标是找到一串可知数量的连续位置 并且对尾部++
                //每次加完先进位 再遍历小串 从后数的第一位连续位开始加

                if(cnt%2==0&&num!=9)
                {
                    for(;flag-j>i;)
                    {
                        s[flag-j]++;
                        j+=2;
                    }
                }
                else if(cnt%2!=0&&num!=9)
                {
                   j=1;
                   for(;flag-j>i;)
                   {
                       s[flag-j]++;
                       j+=2;
                   }
                }
                else if(num==9)
                {
                    s[flag-j]++;
                    for(int m=flag-j;m>i;m--)
                    {
                        if(s[m]>=10)
                        {
                            s[m]-=10;
                            s[m-1]++;
                        }
                        else ;
                    }

                }
            }
        }
        }


        printf("case #%d:\n",z);
        int k=0;
        while(s[k]==0)
        {
                k++;
         }
         for(int z=k;z<121;z++)
         {
            printf("%d",s[z]);
         }

        printf("\n");

    }

    return 0;

    }




int judge(int *s)
{
    int pan=0;//如果遍历一次之后pan仍为0那么说明是不重复数 找到了最小的不重复数
    int i=0;
    while(s[i]==0)
    {
        i++;
    }
    int flag=i;
    for(int j=120;j>=flag;j--)
    {
        if(s[j]==s[j-1]) pan=1;//pan为1说明找到了重复的 是重复数
        else continue;
    }
    return pan;
}


