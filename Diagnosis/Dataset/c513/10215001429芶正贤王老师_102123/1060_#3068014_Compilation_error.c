#include<stdio.h>
#include<string.h>

int main()
{
    char s[105];
    scanf("%s",s);
    int len;
    len=strlen(s);
    int mark[len]={0};
    int max=0;
    for(int i=0;i<len;i++)//对可以计入的数字做标记
    {
        int asc;
        asc = s[i];
        if(asc>48 && asc<58)
            mark[i] = 1;
    }
    for(int i=0;mark[i]==1;i++)
    {
        int j=i;
        int temp=0;
        while(mark[j]==1)
        {
            temp++;
            j++;
        }
        if(temp>max)
            max=temp;
    }
    printf("%d",max);
    return 0;

}
