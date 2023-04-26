#include <stdio.h>
#include <math.h>

int main()
{
    char s[100];
    scanf("%s",s);
    int ans1=0,pos=0,ans2=0,ans3=1,ans;
    while(s[pos]!='.'&&s[pos]!=0){
        if(s[pos]=='2')ans1=ans1*3-1;
        else ans1=ans1*3+s[pos]-'0';
        pos++;
    }
    pos++;
    while(s[pos]!=0){
        if(s[pos]=='2')ans2=ans2*3-1;
        else ans2=ans2*3+s[pos]-'0';
        pos++;
        ans3*=3;
    }
    ans=(int)(ans1+1.0*ans2/ans3);
    if(ans!=0)printf("%d ",ans);
    if(ans1!=ans)ans2=ans3-abs(ans2);
    if(ans2!=0)printf("%d %d",ans2,ans3);
    return 0;
}
