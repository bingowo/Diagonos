#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[105];
    scanf("%s",s);
int i=0;
int l=strlen(s);
int ans=0,cnt=0;
int flag=0;
while(i<l){
    if(s[i]>='0'&&s[i]<='9')flag=1;
    else flag=0;
    if(flag==0)i++;
    else{
        long long int sum=0;
        int j;
        for(j=i;j<l&&flag==1;j++)
        {if(s[j]<'0'||s[j]>'9'){flag=0;}
          else  if(s[j]!='0'){cnt+=1;}
        }
        if(cnt==0)cnt=1;
        if(ans<cnt)ans=cnt;
        cnt=0;
        i=j;
    }


}
printf("%d",ans);

}
