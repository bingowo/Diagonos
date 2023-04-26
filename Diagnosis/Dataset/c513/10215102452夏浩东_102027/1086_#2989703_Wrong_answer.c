#include <stdio.h>
#include <string.h>
#include <stdlib.h> 
int compare(char *s1,char *s2)
{
    int res=0;
    for(int i=0;i<1050;i++)
    {
        if(s1[i]>s2[i]) {res=1;break;}
        else if(s1[i]<s2[i]) {res=-1;break;}
    }
    return res;
}
char* add(char *R,int num)
{
	char *s = (char*)malloc(1050*sizeof(char));
	for(int i=0;i<=num;i++) s[i+1]=R[i];
	s[0]='0'; 
	int left=1;
	for(int i=num+1;i>=0;i--)
	{
		if(s[i]=='.') continue;
		int temp = s[i]+left-'0';
		s[i] = temp%10+'0';
		left = temp/10;
		if(left==0) break;
	}
	return s;
}
char* cut(char *s1,char *s2,int len)
{
    char *R = (char*)malloc(1050*sizeof(char));
    for(int i=0;i<1050;i++) R[i]='0';
    for(int i=len-1;i>=0;i--)
    {
    	if(s1[i]=='\0') s1[i]='0';
        if(s2[i]=='\0') s2[i]='0';
	}
	for(int i=len-1;i>=0;i--)
    {
        if(s1[i]=='.') {R[i]='.';continue;}
        if(s1[i]>=s2[i]) R[i]=s1[i]-s2[i]+'0';
        else
		{
			R[i]=s1[i]+10-s2[i]+'0';
			if(s1[i-1]!='.') s1[i-1]-=1;
			else s1[i-2]-=1;
		}
    }
    return R;
}
int main()
{
    char s1[1050],s2[1050];
    for(int i=0;i<1050;i++) {s1[i]='0';s2[i]='0';}
    int num=0;
    scanf("%s %s %d",s1,s2,&num);
    int dot1=-1,dot2=-1,dot=0;
    for(int i=0;i<1050;i++){
        if(s1[i]=='.') dot1=i;
        if(s2[i]=='.') dot2=i;
    }
    if(dot1==-1) {dot1=(int)strlen(s1);s1[(int)strlen(s1)+1]='\0';s1[(int)strlen(s1)]='.';}
    if(dot2==-1) {dot2=(int)strlen(s2);s2[(int)strlen(s2)+1]='\0';s2[(int)strlen(s2)]='.';}
    dot=dot1>dot2?dot1:dot2;
    if(dot1==dot){
        int mov = dot-dot2;
        for(int i=(int)strlen(s2);i>=0;i--) s2[i+mov]=s2[i];
        for(int i=mov-1;i>=0;i--) s2[i]='0';
    }else{
        int mov = dot-dot1;
        for(int i=(int)strlen(s1);i>=0;i--) s1[i+mov]=s1[i];
        for(int i=mov-1;i>=0;i--) s1[i]='0';
	}
    int flag = compare(s1,s2);
    int len1 = (int)strlen(s1);
    int len2 = (int)strlen(s2);
    int len = len1>len2?len1:len2;
    char *R = (char*)malloc(1050*sizeof(char));
    if(flag==1) R=cut(s1,s2,len);
    else if(flag==-1) R=cut(s2,s1,len);
    if(R[dot+num+1]>='5') {R=add(R,num+dot);num++;}
    if(flag==-1){
        printf("-");
        int zero=0;
        for(int i=0;R[i]=='0' && R[i+1]!='.';i++) zero++;
        for(int i=zero;i<=dot+num;i++) printf("%c",R[i]);
    }
    else if(flag==1){
        int zero=0;
        for(int i=0;R[i]=='0' && R[i+1]!='.';i++) zero++;
        for(int i=zero;i<=dot+num;i++) printf("%c",R[i]);
    } else {
        printf("0.");
        for(int i=0;i<num;i++){
            printf("0");
        }
    }
    free(R);
    return 0;
}