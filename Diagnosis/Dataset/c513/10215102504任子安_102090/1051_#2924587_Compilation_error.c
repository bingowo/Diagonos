#include <stdio.h>
#include <string.h>

int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char s[100];
		int l,n,cnt,ans[1000]={0};
		scanf("&s",s);
		l = strlen(s);
		for(int j=0,i=0,cnt=0;i<l;i++)
		{
			if(cnt==0)
            {
                ans[j++]=s[i]/4;
                ans[j]=(s[i]%4)*16;
            }
            else if(cnt==1)
            {
                ans[j++]+=s[i]/16;
                ans[j]=(s[i]%16)*4;
            }
            else
            {
                ans[j++]+=s[i]/64;
                ans[j++]=s[i]%64;
            }
            cnt=(++cnt)%3;
		}
		if(j%4) for(j++; j%4!=0; j++) ans[j]=64;
        printf("case #%d:\n",i);
        for(i=0; i<j; i++)
        {
            if(ans[i]<26) printf("%c",'A'+ans[i]);
            else if(ans[i]<52) printf("%c",'a'+ans[i]-26);
            else if(ans[i]<62) printf("%c",'0'+ans[i]-52);
            else if(ans[i]==62) printf("+");
            else if(ans[i]==63) printf("/");
            else printf("=");
        }
        printf("\n");
	}
	return 0;
}