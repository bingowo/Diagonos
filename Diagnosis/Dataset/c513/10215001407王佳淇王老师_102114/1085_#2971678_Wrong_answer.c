#include<stdio.h>
#include<string.h>
char*a,*b;
void get(char*s)
{
	a=strtok(s," ");
	b=strtok(NULL,"\0");
}
char s[2000];
int main(){
	
	while(gets(s)){
	
	get(s);
	int la=strlen(a);   
    int lb=strlen(b);
	int a1[1000]={0},b1[1000]={0}; 
	int i;  
    int maxlen=la>lb?la:lb;
    if(la>lb||(la==lb&&strcmp(a,b)>0))       //两字符串比较（即为俩数字比较）a > b 时
        {
                int m=maxlen;       //m 用来存刚才对比过后的二者中较大的位数 maxlen
                for(i=0;i<la;i++,m--)   //
                        a1[m]=a[la-1-i]-'0';//这里是进行了将输入的字符串变成数字数组的操作，
                                                //注意最高位空出来，防止溢出
                      m=maxlen;
                for(i=0;i<lb;i++,m--)
                        b1[m]=b[lb-1-i]-'0';//减去字符0就是减去了32，字符串串变成了数字串存每个数字
        }
      else            //这里为后面进行b串-a串的操作做准备
        {
                int m=maxlen;
                for(i=0;i<lb;i++,m--)
                        a1[m]=b[lb-1-i]-'0';    
                m=maxlen;
                for(i=0;i<la;i++,m--)
                        b1[m]=a[la-1-i]-'0';    
        }
        //减法
        for(i=maxlen;i>=0;i--)
        {
                a1[i]-=b1[i];
                if(a1[i]<0)//借位
                {
                    a1[i]=a1[i]+10;
                    a1[i-1]--;
                }
        }
        if(la<lb||(la==lb&&strcmp(a,b)<0))//负号
        printf("-");
        int v=0,z=sizeof(a1)/sizeof(a1[0]);
        while(a1[v]==0) v++;//去前导0 
        if((v-1)==z) printf("0");
        else{
        for(i=v;i<=maxlen;i++)printf("%d",a1[i]);}
		printf("\n");}
        return 0;
}