#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

void insertA(char*s,int k,char*b)
{

    int lens=strlen(s);
    int po=0;
    for(int i=0;i<lens;i++){
    	if(i==k){
    		b[po++] = 'A';
		}
    	b[po++]=s[i];
	}
	b[po++] = '\0';

}//在s[k]后插入A放在b里面
void insertB(char*s,int k,char*b)
{

    int lens=strlen(s);
    int po=0;
    for(int i=0;i<lens;i++){
    	if(i==k){
    		b[po++] = 'B';
		}
    	b[po++]=s[i];
	}
	b[po++] = '\0';

}//在s[k]后插入B放在b里面
void insertC(char*s,int k,char*b)
{

    int lens=strlen(s);
    int po=0;
    for(int i=0;i<lens;i++){
    	if(i==k){
    		b[po++] = 'C';
		}
    	b[po++]=s[i];
	}
	b[po++] = '\0';

}//在s[k]后插入C放在b里面

   int jiancha(char*s)
{
    int len=strlen(s),k;
    if(len<=1) return 1;
    if(len>1)
    {for(k=1;k<len;k++)
    if(s[k]==s[k-1]) return 0;
   return 1;}
}//检查s里面有没有重复字母
void xiaochu(char*s)
{
    char c[110];
    int lens=strlen(s);
 

    while(jiancha(s)==0)
    {
        int l=0;
        for(int k=0;k<lens-1;)
        {if(s[k]==s[k+1]) {while(s[k]==s[k+1]&&k<lens-1) k++;}
        else {c[l]=s[k];l++;}
        k++;}
        if(s[lens-2]!=s[lens-1]) c[l++] = s[lens-1];
        c[l++] = '\0';
        strcpy(s,c);
        
    }//消除
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        char a[110];
        scanf("%s",a);
        
        int len=strlen(a),max=0;
        for(int k=0;k<len;k++)
        {
            char b[110];
            insertA(a,k,b);
            xiaochu(b);
            //printf("%s\n",b);
            max=(max>(len+1-strlen(b)))?max:(len+1-strlen(b));
        }//插A
        for(int k=0;k<len;k++)
        {
            char b[110];
            insertB(a,k,b);
            xiaochu(b);
            max=(max>(len+1-strlen(b)))?max:(len+1-strlen(b));
        }//插B
        for(int k=0;k<len;k++)
        {
            char b[110];
            insertC(a,k,b);
            xiaochu(b);
            max=(max>(len+1-strlen(b)))?max:(len+1-strlen(b));
        }//插C
        printf("case #%d:\n",i);
        pr