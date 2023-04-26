#include <stdio.h>
#include <string.h>

typedef struct
{
    int num[200];
    int len;
}INT;
INT add(INT a,INT b);
INT div(INT a,long long b);
INT str2INT(char* s);
int main()
{
    int T;
    scanf("%d",&T);
    for(int j=0;j<T;j++)
    {
        char s[200];
        scanf("%s",s);
        INT a=str2INT(s);
        INT temp,ans={{0},200};
        for(int i=a.len-1;i>=0;i--)
        {
            ans=div(ans,8);
            ans.num[0]=a.num[i];
        }
        ans.len=200;
        while(ans.num[ans.len-1]==0&&ans.len>2) ans.len--;
        printf("case #%d:\n0.",j);
        for(int i=1;i<ans.len;i++)  printf("%d",ans.num[i]);
        printf("\n");
    }
}
INT str2INT(char* s)
{
    INT c={{0},1};
    for(int i=2;i<strlen(s);i++)
    {
        c.num[c.len++]=s[i]-'0';
    }
    return c;
}
// INT add(INT a,INT b)
// {
//     INT c={{0},a.len>b.len?a.len:b.len};
//     int temp=0,carry=0;
//     for(int i=0;i<c.len;i++)
//     {
//         temp=a.num[i]+b.num[i]+carry;
//         c.num[i]=temp%10;
//         carry=temp/10;
//     }
//     if(carry)   
//     {
//         c.num[c.len]=carry;
//         c.len++;
//     }
//     return c;
// }
INT div(INT a,long long b)
{
    INT c={{0},a.len};
    long long temp=0,carry=0;
    for(int i=0;i<200;i++)
    {
        temp=carry*10+a.num[i];
        c.num[i]=temp/b;
        carry=temp%b;
    }
    // while(c.num[c.len-1]==0&&c.len>2)   c.len--;
            
    // for(int i=0;i<200;i++)  printf("%d",c.num[i]);
    // printf("\n");
    return c;
}

