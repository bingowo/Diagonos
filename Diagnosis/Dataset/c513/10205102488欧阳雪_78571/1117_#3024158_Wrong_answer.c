#include<stdio.h>
#include<stdlib.h> 
#include<string.h>  
#define MAX 20000
int compare(char* s1,char* s2)  //比较字符串（两个数）数字的大小，大于等于返回0，小于返回1。  
{  
  if(strlen(s1)>strlen(s2)) return 0;  //先比较长度，哪个字符串长，对应的那个数就大  
  if(strlen(s1)<strlen(s2)) return 1;  
  for(int i=0;i<=strlen(s1);i++)  //长度相同时，就一位一位比较。  
  {  
    if(s1[i]>s2[i]) return 0;  
    if(s1[i]<s2[i]) return 1;                            
  }  
  return 0;   //如果长度相同，每一位也一样，就返回0，说明相等  
}

char*ChebyDis(char*str1,char*str2,char*ans)//|str1-str2|结果返回字符串 
{   
  	int a[MAX],b[MAX],len;  
    int i;  
    memset(a,0,sizeof(a));  
    memset(b,0,sizeof(b));
    int flg=1;
    
    if(str1[0]=='-'&&str2[0]!='-'||str1[0]!='-'&&str2[0]=='-')
    {
    	flg=0;
    	if(str1[0]=='-')
    	{
    	//	printf("a[]:");
    		a[0]=strlen(str1)-1;
    		int len3=strlen(str1);
    		for(i=1;i<=a[0];i++)
    		{
    			a[i]=str1[len3-i]-'0';
    		//	printf("%d",a[i]);
			}
		//	printf("\n");
			b[0]=strlen(str2); 
			for(i=1;i<=b[0];i++)
            {
  	            b[i]=str2[b[0]-i]-'0';
            }
			
		}
		if(str2[0]=='-')
		{
		//	printf("b[]:\n");
    		b[0]=strlen(str2)-1;
    		int len4=strlen(str2);
    		for(i=1;i<=b[0];i++)
    		{
    			b[i]=str2[len4-i]-'0';
    		//	printf("%d",b[i]);
			}
		//	printf("\n");
			a[0]=strlen(str1); 
			for(i=1;i<=a[0];i++)
            {
  	            a[i]=str1[a[0]-i]-'0';
            }
		}
    	
	}
	else
	{
    a[0]=strlen(str1);   //数组首位存储数据长度 
    int len1=strlen(str1); //字符串->数组，倒着存 
    for(i=1;i<=len1;i++)
    {
  	    a[i]=str1[len1-i]-'0';
    }  
    
    b[0]=strlen(str2); 
    int len2=strlen(str2);
    for(i=1;i<=len2;i++)
    {
  	    b[i]=str2[len2-i]-'0';
    }
    }
    
    if(flg==0)//符号不同，相减的绝对值相当于加法
	{
	//	printf("负数 ");
		int r=0;
		int m;
		if(a[0]>b[0])m=a[0];
		else{
			m=b[0];
		}
	//	printf("m:%d\n",m);

	    for(i=1;i<=m;i++)
		{
			int tmp = a[i]+b[i]+r;
             r = tmp/10;
            a[i] = tmp%10;
		}
		if(r>0)//最高位有进位 
		{
			m+=1;
			a[m]=r;
		//	printf("r:%d\n",r);
		}
		int j1=0;
	//	printf("tes:");
        for(i=m,j1=0;i>=1;i--,j1++)//返回值 
        {
        	ans[j1]=a[i]+'0';
	//	    printf("%d",a[i]);  
	    }
	 //   printf("\n");
	}
	
	if(flg==1) 
    {
    if((compare(str1,str2))==0)  //大于等于，做按位减，并处理借位。  
    {  
        for(i=1;i<=a[0];i++)  
        {
		    a[i]-=b[i];  
            if (a[i]<0)
			{
			    a[i+1]--;
				a[i]+=10;
			}  
        }  
        a[0]++;  
        while((a[a[0]]==0)&&(a[0]>1)) a[0]--;  //去除前导0
		
		int j=0;
        for(i=a[0],j;i>=1;i--,j++)//返回值 
        {
        	ans[j]=a[i]+'0';
	//	    printf("%d",a[i]);  
	    }
      //  printf("\n");  
      //  printf("ans:%s\n",ans);
  }                            
  else  
  {  
        for(i=1;i<=b[0];i++)  //做按位减，大的减小的  
        {
		    b[i]-=a[i];  
            if(b[i]<0)
			{
			    b[i+1]--;
				b[i]+=10;
			}  
        }  
        b[0]++;  
        while((b[b[0]]==0)&&(b[0]>1)) b[0]--;  
        
        int k=0; 
        for(i=b[0],k;i>=1;i--,k++)
        {
        	ans[k]=b[i]+'0';
        //	printf("%d",b[i]);
		}
      //  printf("\n");        
  }  
  
}
  //printf("ans:%s\n",ans);
  return ans; 
}    
int main()  
{
  char x0[MAX],y0[MAX];
  char xi[MAX],yi[MAX];
  char distance[MAX];
  memset(distance,'1',sizeof(distance));
  int n;
  scanf("%s",x0);
  scanf("%s",y0);
  scanf("%d",&n);
  for(int i=0;i<n;i++)
  {
  	char x[MAX],y[MAX];
	char t1[MAX]={0},t2[MAX]={0};
  	char tempe[MAX];
  	scanf("%s",x);
  	scanf("%s",y);
  	ChebyDis(x,x0,t1);
  	ChebyDis(y,y0,t2);
  	//printf("t1 t2 %s %s\n",t1,t2);
  	if(compare(t1,t2)==0){//t1>=t2
  		strcpy(tempe,t1);
	}
	else{
		strcpy(tempe,t2);
	}
  	if(compare(distance,tempe)==0)//distance>=tempe
  	{
  		strcpy(distance,tempe);
  		//printf("tes:%s\n",tempe);
  		strcpy(xi,x);
  		strcpy(yi,y);
	}
	
  }
  printf("%s\n",distance);
  printf("%s ",xi);
  printf("%s",yi);
  return 0;
} 

