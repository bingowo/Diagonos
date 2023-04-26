#include<stdio.h>
#include<string.h>

int main()
{
    char s[51];scanf("%s",s);
    int i=0,res=0,mid=1;
    while (i<(int)strlen(s))
    {
        if(s[i]!=s[i+1] && i<(int)strlen(s)-1) {mid++;i++;}
        if(s[i]==s[i+1] || i==(int)strlen(s)-1)
        {
            if(mid>res) res=mid;
            i++,mid=1;
        }
    }
    printf("%d",res);

    return 0;    
}