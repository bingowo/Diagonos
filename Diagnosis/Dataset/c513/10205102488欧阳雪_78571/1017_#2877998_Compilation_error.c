#include<stdio.h>
#include<string.h>
int main()
{
	char s[100]={'\0'};
	int a[1000]={0};//存储罗马数字的值 
	a['I']=1,a['V']=5,a['X']=10,a['L']=50,a['C']=100,a['D']=500,a['M']=1000;
	long long ans=0;
	long long flg=1;
	scanf("%s",s);
	int each[100]={0};
	int count=0,i=0;
	while(s[i])
	{
		if(s[i]=='(')flg*=1000;
		if(s[i]==')')flg/=1000;
		else each[count++]=a[s[i]]*flg;
		i++;
	}
	for(int j=0;j<count;j++){
		if(j==count-1){
			ans+=each[j];#include<iostream>

using namespace std;

int R[130];
int main()
{   
    R['I'] = 1, R['V'] = 5, R['X'] = 10, R['L'] = 50, R['C'] = 100, R['D'] = 500, R['M'] = 1000;
    long long flag = 1;
    long long sum = 0;
    string s;
    cin >> s;
    int len = s.length();
    //利用栈的特性来判定正负
    long long* each = new long long[len];
    int count = 0;
    for(int i = 0; i < len; i++)
    {
        switch (s[i])
        {
        case '(':
            flag *= 1000;
            break;
        case ')':
            flag /= 1000;
            break;
        
        default:
            each[count++] = flag * R[s[i]];
            break;
        }
    }
    for(int i = 0; i < count; i++)
    {
        if(i == count - 1)
            sum += each[i];
        
        else
            sum += ((each[i] < each[i + 1]) ? -each[i] : each[i]);
    }
    cout << sum;
}

		}
		else{
			ans+=((each[j]<each[j+1])? -each[j]:each[j]);
		}
	}
	printf("%lld",ans);
}