#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int main()
{
    char a[110];
    scanf("%s",a);
    int len=strlen(a),count=0,max=0;
    for(int i=0;i<len;i++)
    {
        if(s[i]<='9'&&s[i]>='0') 
        {count++;
        if(max<count) max=count;}
        if(s[i]<'0'&&s[i]>'9') count=0;
    }
    printf("%d",max);
    return 0;
}