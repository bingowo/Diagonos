#include<stdio.h>

void trans(char *s,int *bit,int len);
int count(int *bit,int len);
int find_cd(int over, int under);
int main()
{
    int T;
    int i,j;
    char s[121];
    scanf("%d",&T);
    for (i=0;i<T;i++){
        int bit[960];//bit数组用于存放各个位
        int len=0;
        int cnt=0;
        int over,under,cd;
        gets(s);//s为当前行字符串
        len=strlen(s);
        for (j=0;j<len*8;j++){
            bit[i]=0;
        }
        trans(s,bit,len);
        cnt=count(bit,len);
        over=cnt;
        under=len*8;
        cd=find_cd(over, under);
        printf("%d/%d\n",over/cd,under/cd);
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

int find_cd(int over, int under)
{
    int rest;
    rest=under%over;
    while (rest!=0){
        under=over;
        over=rest;
        rest=under%over;
    }
    return over;
}