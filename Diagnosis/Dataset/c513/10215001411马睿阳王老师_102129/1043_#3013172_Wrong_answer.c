#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int cnt(char s[])
{
    int i = 0,num = 0;
    for( i = 0; i < strlen(s)-1; i++)
    {
        if(s[i] == s[i+1])num++;
    }
    return num;//计算字符串是否还有重复字母
}

int max(int a,int b)
{
    if(a>=b)return a;
    else return b;
}

int main()
{
    char s1[107],s[107],s2[107];
    int n,i,j,k,m,l,num,ans,len;
    scanf("%d",&n);
    for(i = 0; i < n; i++)
    {
       ans = 0;
       scanf("%s",s);
       for(j = 0; j < strlen(s); j++)//枚举每一个字母后面插入和他相同的字母
       {
           if(j != 0&&s[j] == s[j-1])continue;//若字母和前面重复，则进行下一轮
           m = j;
           for( k = 0; k <= m; k++)s1[k] = s[k];
           s1[k++] = s[m];
           for(;k <=strlen(s); k++)s1[k] = s[k-1];
           s1[k]='\0';//最后一定要有结束符！
           len = strlen(s1);//记录长度
           while(cnt(s1))
           {
               strcpy(s2,s1);
               for(l = 0; l < k; l++)s1[l] = '\0';
               for(l = 0,m = 0; l < strlen(s2)-1; l++)
               {
                   if(l == 0){if(s2[0] != s2[1])s1[m] = s2[l],m++;}//首字母单独讨论
                   else if((s2[l] != s2[l-1])&&(s2[l] != s2[l+1]))s1[m] = s2[l],m++;//如果这个字母与前或后相同则不记录，不同就记录；
               }
               if(s2[l] != s2[l-1]){s1[m] = s2[l];}//末字母也单独讨论
               s1[m] = '\0';//结束符结束符！！
               if(strlen(s1) == 0)break;
           }
           num = len - strlen(s1);
           ans = max(ans,num);
           for(l = 0; l < k; l++){s1[l] = '\0';s2[l] = '\0';}//清零！！
        }
        printf("case #%d:\n",i);
        printf("%d\n",ans);

    }
    return 0;
}