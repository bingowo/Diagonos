#include<stdio.h>
#include<string.h>

int main()
{
    int T;//题目数
    int i,j;
    scanf("%d",&T);
    for(i=0;i<T;i++)        //一个问题
    {
        printf("case #%d:\n",i);
        char s[30];
        
        scanf("%s",s);
        int l=strlen(s);
        long long int ansA = 0;
        for(j=0;j<l;j++)        //读入数组
        {
            ansA = ansA * 3;
            if(s[j]=='1') ansA++;
            if(s[j]=='-') ansA--;
        }
        printf("%lld\n",ansA);
    }
    return 0;
}