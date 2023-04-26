#include<stdio.h>
#include<string.h>

int main()
{
    char s[1005];
    scanf("%s",s);
int l=strlen(s);

for(int i=0;i<l;i++)
{
    if(s[i]>='a'&&s[i]<='z')s[i]-=32;
}
char ans[2010]={0};
int k1=1005,k2=1006;
ans[k1]=s[0];
for(int i=1;i<l;i++)
{
    if(s[i]>=ans[k1])ans[--k1]=s[i];
    else ans[k2++]=s[i];
}
for(int i=k1;i<k2;i++)
printf("%c",ans[i]);

}
