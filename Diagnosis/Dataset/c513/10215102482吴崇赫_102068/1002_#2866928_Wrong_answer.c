#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 65

// 最小密码

// 统计字符串字符个数
int Charnum(char* p) {
	int ans = 0,n=strlen(p);
	int cnt[200] = { 0 };
	for (int i = 0;i < n;++i)cnt[p[i]]++;
	for (int j = 0;j < 200;++j) {
		if (cnt[j])ans++;
	}
	return ans;
}

//赋值 第一字符为1，第二字符为0，后面依次排列
void solve(char* s) {
	int give = 0,n=strlen(s);
	int Give[200] = { -1 };
	int flag0=0,flag1=0;
	for (int i = 0;i < strlen(s)&&Give[s[i]]==-1;++i) {
		Give[s[i]] = give++;
		if(Give[s[i]]==1&&!flag1){Give[s[i]]=0;flag1++;}
		if(Give[s[i]]==0&&!flag0){Give[s[i]]=1;flag0++;}
	}
	long long ans = 0;
	int jz = Charnum(s);
	while (*s)
	{
		ans *= jz;
		ans += Give[*s++];
	}
	printf("%lld\n", ans);
	//printf("%d\n", Give[s[4]]);
}

int main() {
	int T,x=0;
	scanf("%d\n", &T);
	while (x<T) {
		char test[N] = { '\0' };
		scanf("%s", test);
		printf("case #%d:\n",x++);
		solve(test);
	}
	return 0;
}