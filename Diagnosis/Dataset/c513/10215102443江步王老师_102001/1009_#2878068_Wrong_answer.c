#include<stdio.h>

void trans(char *s,int *bit,int len);
int count(int *bit,int len);
int main()
{
    int T;
    int i;
    char s[121];
    scanf("%d",&T);
    for (i=0;i<T;i++){
        int bit[960];//bit数组用于存放各个位
        int len=0;
        int cnt=0;
        scanf("%s",s);//s为当前行字符串
        len=strlen(s);
        trans(s,bit,len);
        cnt=count(bit,len);
        printf("%d\n",cnt);
    }
    return 0;
}

void trans(char *s,int *bit,int len)
{
    int i;
    int t;
    int num=0;
    for (i=0;i<len;i++){
        t=s[i];
        while (t>0){
            bit[num]=t%2;
            t=t/2;
            num++;
        }
    }
    return;
}

int count(int *bit,int len)
{
    int i;
    int cnt=0;
    len=len*8;
    for (i=0;i<len;i++)
    {
        if (*(bit+i)==1){
            cnt++;
        }
    }
    return cnt;
}