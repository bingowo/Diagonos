#include<stdio.h> 
#include<string.h>
#include<math.h>
int start = 0;
int lengthOfLongestSubstring(char * s){
    int result=0;
    int hush[256]={0};
	int left=0;
    int right=-1;
    int len=strlen(s);
    while(left<len){
    	//下一字符在Left和right之间
		if(hush[s[right+1]]==0&&right<len-1){
			hush[s[++right]]++;
		}
		//下一字符不在Left和right之间
		else{
			hush[s[left++]]--;
		}
		//更新最长子串长度 
		if(right-left+1>result){
			result=right-left+1; start = left;
		}
	}
	return result;
}


int main(){
	char s[1000001];int result;
	scanf("%s", &s);
	result=lengthOfLongestSubstring(s);
	//printf("%d", start);
	for(int i = 0; i < result; i++){
		printf("%c",s[start+i]);
	}
	
}
