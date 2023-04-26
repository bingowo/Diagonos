#include <stdio.h>
#include <stdlib.h>
int measure(int x, int y)
{
	int z = y;
	while(x%y!=0)
	{
		z = x%y;
		x = y;
		y = z;
	}
	if(z<0) z=-z;
	return z;
}
int main()
{
        char s[30];
        scanf("%s",s);
        int s1[100];
        for(int q=0;q<100;q++) s1[q]=0;
        int m=strlen(s);
        int j;
        for(j=0;j<m;j++)
        {
            if(s[j]=='2') s1[j]=-1;
            if(s[j]=='0') s1[j]=0;
            if(s[j]=='1') s1[j]=1;
            if(s[j]=='.')
            {
                j++;
                break;
            }
        }
        if(j==m) j=m+1;
        int ans=0;
        for(int k=0;k<j-1;k++)
            ans=ans*3+s1[k];
        int num=j;
        for(;j<m;j++)
        {
            if(s[j]=='2') s1[j]=-1;
            if(s[j]=='0') s1[j]=0;
            if(s[j]=='1') s1[j]=1;
        }
        int ans2=0,ans3=1;
        for(int q=num;q<m;q++)
        {
            ans2=ans2*3+s1[q];
            ans3=ans3*3;
        }
        if(ans<0)
        {
            ans=ans+1;
            ans2=ans3-ans2;
        }
        if(ans2<0&&ans!=0)
        {
            ans=ans-1;
            ans2=ans3+ans2;
        }
        int c=measure(ans2,ans3);
        if(ans==0) printf("%d %d",ans2/c,ans3/c);
        else
        {
            if(ans2==0) printf("%d",ans);
            else printf("%d %d %d",ans,ans2/c,ans3/c);
        }
}
