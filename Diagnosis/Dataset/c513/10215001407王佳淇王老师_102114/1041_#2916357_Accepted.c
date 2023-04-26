#include<stdio.h>
#include<string.h>
#include<math.h>
int main(){
	char s[52];
	int cnt[52];
	scanf("%s",s);
	cnt[0] = 1;
	int  maxn = 1;
	for(int i=1;i<strlen(s);i++)
{
   if(s[i]!=s[i-1])
   {
       cnt[i] = cnt[i-1]+1;
       maxn = fmax(cnt[i],maxn);
    }
   else cnt[i] = 1;

}
    printf("%d",maxn);
	return 0;
} 