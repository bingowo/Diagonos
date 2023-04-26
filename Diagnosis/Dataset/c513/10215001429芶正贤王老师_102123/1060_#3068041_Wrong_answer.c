#include<stdio.h>
#include<string.h>

int main()
{
    char s[105];
    scanf("%s",s);
    int len;
    len=strlen(s);
    int mark[105]={0};
    int stand[105]={0};
    int max=0;
    for(int i=0;i<len;i++)//对可以计入的数字做标记
    {
        int asc;
        asc = s[i];
        if(asc==48)//0
            mark[i] = 10;
        if(asc>48 && asc<58)//数字1-9
            mark[i] = 1;
    }
    if(mark[0]==0)
        stand[0]=0;
    else
        stand[0]=9;
    for(int i=1;i<len;i++)
    {
        if(mark[i-1]==0 && (mark[i]==1 || mark[i]==10))//前一位为字母，此位为数字0-9
            stand[i]=9;
    }
   
    for(int i=0;i<len;i++)//对每个stand点
    {
        if(stand[i]!=9)
            continue;
        int length=0;
        int j=i;
        while(mark[j]==0)
        {
            j++;
            
        }
        while(mark[j]==1 || mark[j]==10)
        {
            length++;
            j++;
            if(length>max)
                max=length;
        }
    }
    printf("%d",max);
    return 0;
    
}