#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int T; 
char s[100000],ans[100000];
void judge(char s[])
{
	int len = strlen(s), states[100000], top = 0,pos=0;
	states[top] =0;
	for (int i = 0; i<len; i++) {
		int state = states[top];
		char ch= s[i];
		int m=i+2,n=i-2;
		switch(state)
		{
//		外层状态 
    	case 0:if(ch=='/') states[++top]=1;
				else if(ch=='"') {
					states[++top]=4;
					ans[pos++]=ch;
				}
				else if(ch=='\0'){
					ans[pos]='\0';
					return ;
				} 
				else{
					states[++top]=0;
					ans[pos++]=ch;
				}
            break;
//		检测到第一个/  
        case 1:if(ch=='/')	states[++top]=2;
        		else if(ch=='*') states[++top]=3;
        	break; 
//      检测到第二个/
		case 2:if(ch=='\n'){
			states[++top]=0;
			ans[pos++]=ch;
		}
			else states[++top]=2;
			break;
//		检测到第一个*
		case 3:if(ch=='*') states[++top]=5;
			else states[++top]=3;
			break; 
//      检测到引号
		case 4:while(n>=0&&s[n]==' ')
				n--;
//				printf("%c\n",s[n]);
		if(i>0&&s[n]=='=')
		{
//			printf("WOTMLAINA\n");
			states[++top]=6;
			ans[pos++]=ch;
		 } 
		else
		{
			if(ch=='"'){
			states[++top]=0;
			ans[pos++]=ch;
			}
			else{
				states[++top]=4;
				ans[pos++]=ch;
			}
		}
			break;
//		检测到第二个* 
		case 5:if(ch=='/')	states[++top]=0;
			break;
		case 6:
			while(s[m]==' ')
				m++;
//			printf("%d %d\n",i,m);
			if(ch=='"'&&s[m]==';')
		{
			states[++top]=0;
			ans[pos++]=ch;
		}
		else{
			states[++top]=6;
			ans[pos++]=ch;
		}
			break;
    	}
   }
	return ; 
}
int main()
{
	int i=0;
		while(1)
		{
			char c;
			c=getchar();
			if(c!=EOF)
				s[i++]=c;
			else
				break;
		}
		s[i]='\0';
		judge(s);
		printf("%s",ans);
	return 0;
}