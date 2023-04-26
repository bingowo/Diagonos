#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <ctype.h>
#define MAX 501    //定义竖式运算的精度，数值可改变
#define INT(x) int x[MAX] = {0}     //高精度数的定义方式
void sassign(int* x,char* s)    //字符串->数组
{
    int len = strlen(s);
    int i,j;
    if(s[0] == '-') x[0] = 0;
    else x[0] = 1;

    for(i=MAX,j=len-1;i>=1&&isdigit(s[j]);i--,j--)
        {
        	x[i] = s[j]-'0';
			//printf("%d",x[i]);
		}

   // printf("\n");
}
void cpy(int* x,int* y) 
{
    for(int i=0;i<=MAX;i++)
            x[i] = y[i];
}
void print(int* x)
{
    int flag = 0;
    if(!x[0])   printf("-");
    for(int i=1;i<=MAX;i++)
    {
        if(!flag && !x[i])  continue;  //去除前导0
        flag = 1;
        printf("%d",x[i]);
    }
    if(!flag)   printf("0");
    printf("\n");
}
void add(int* x,int* y)
{
    int r=0;
    for(int i=MAX;i>=1;i--)
    {
        int tmp = x[i]+y[i]+r;
        r = tmp/10;
        x[i] = tmp%10;
    }
}
int compare(char* s1,char* s2)  //（正负）比较字符串（两个数）数字的大小，大于返回0，小于返回1,等于返回-1  
{
	//对负数的处理 
  if(s1[0]=='-'&&s2[0]!='-')return 1;
  if(s1[0]!='-'&&s2[0]=='-')return 0;
  if(s1[0]=='-'&&s2[0]=='-')
  {
  	if(strlen(s1)>strlen(s2))return 1;
  	if(strlen(s1)<strlen(s2))return 0;
  	for(int j=1;j<=strlen(s1);j++)
  	{
  		if(s1[j]>s2[j])return 1;
  		if(s1[j]<s2[j])return 0;
	  }
	return -1;
  }
  //两个都是正数
  if(strlen(s1)>strlen(s2)) return 0;  //先比较长度，哪个字符串长，对应的那个数就大  
  if(strlen(s1)<strlen(s2)) return 1;  
  for(int i=0;i<=strlen(s1);i++)  //长度相同时，就一位一位比较。  
  {  
    if(s1[i]>s2[i]) return 0;  
    if(s1[i]<s2[i]) return 1;                            
  }  
  return -1;   //如果长度相同，每一位也一样，就返回-1，说明相等  
}
char*jianfa(char*str1,char*str2,char*ans)//|str1-str2|结果返回绝对值结果的字符串 高精度数相减，包括负数
{   
  	int a[MAX],b[MAX],len;  
    int i;  
    memset(a,0,sizeof(a));  
    memset(b,0,sizeof(b));
    int flg=1;
    //一正一负的字串转成数组的存储处理
    if(str1[0]=='-'&&str2[0]!='-'||str1[0]!='-'&&str2[0]=='-')
    {
    	flg=0;
    	if(str1[0]=='-')
        {
    		a[0]=strlen(str1)-1;
    		int len3=strlen(str1);
    		for(i=1;i<=a[0];i++)
    		{
    			a[i]=str1[len3-i]-'0';
			}
			b[0]=strlen(str2); 
			for(i=1;i<=b[0];i++)
            {
  	            b[i]=str2[b[0]-i]-'0';
            }		
		}
		if(str2[0]=='-')
		{
    		b[0]=strlen(str2)-1;
    		int len4=strlen(str2);
    		for(i=1;i<=b[0];i++)
    		{
    			b[i]=str2[len4-i]-'0';
			}
			a[0]=strlen(str1); 
			for(i=1;i<=a[0];i++)
            {
  	            a[i]=str1[a[0]-i]-'0';
            }
		}  	
	}
    //同为负数 
    else if(str1[0]=='-'&&str2[0]=='-')
	{
    		a[0]=strlen(str1)-1;
    		int len5=strlen(str1);
    		for(i=1;i<=a[0];i++)
    		{
    			a[i]=str1[len5-i]-'0';
			}
    		b[0]=strlen(str2)-1;
    		int len6=strlen(str2);
    		for(i=1;i<=b[0];i++)
    		{
    			b[i]=str2[len6-i]-'0';
			}
	}
    //都是正数的字串转数组的存储处理
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
    
    //计算
    if(flg==0)//符号不同，相减的绝对值相当于加法
	{
	//	printf("负数 ");
		int r=0;
		int m;
		if(a[0]>b[0])m=a[0];
		else{
			m=b[0];
		}

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
		}
		int j1=0;
        for(i=m,j1=0;i>=1;i--,j1++)//返回值 
        {
        	ans[j1]=a[i]+'0';
	    }
	}
	
	if(flg==1) //符号相同，绝对值相减
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
	    }
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
		}    
  }  
  
}
  return ans; 
} 
struct point{
	char x[MAX];
	char y[MAX];
};
int*distance(struct point P1,struct point P2,int*d)
{
	char ans1[MAX]={0},ans2[MAX]={0};
	jianfa(P1.x,P2.x,ans1);
	jianfa(P1.y,P2.y,ans2);
//	printf("ans1:%s\n",ans1);
//	printf("ans2:%s\n",ans2);
	int Ans1[MAX]={0},Ans2[MAX]={0};
	sassign(Ans1,ans1);
	sassign(Ans2,ans2);
	add(Ans1,Ans2);
//	printf("Ans1:");
//	print(Ans1);
	cpy(d,Ans1);
//	printf("d:");
//	print(d);
	return d;
}
int cmp(const void*a,const void*b)
{
	struct point P1=*(struct point*)a;
	struct point P2=*(struct point*)b;
	int ans1[MAX]={0},ans2[MAX]={0};
	int x1[MAX]={0},y1[MAX]={0};
	int x2[MAX]={0},y2[MAX]={0};
	sassign(x1,P1.x),sassign(y1,P1.y);
	sassign(x2,P2.x),sassign(y2,P2.y);
//	printf("x1[0]:%d\n",y1[MAX]);
//	printf("x2[0]:%d\n",y2[MAX]);
	add(x1,y1);
	add(x2,y2);
//	printf("x1:");
//	print(x1);
//	printf("x2:");
//	print(x2);
	char X1[MAX]={0},X2[MAX]={0};
	//转成字串便于比较 
	int flag = 0;
	int j=0,k1=0,k2=0;
	for(j=1,k1;j<=MAX;j++)
	{
		if(!flag && !x1[j])  continue;  //去除前导0
		flag = 1;
		X1[k1++]=x1[j]+'0';
       // printf("%c",X1[k1-1]);
      //  printf(" k:%d ",k1-1);
	}
//	printf("\n");
//	printf("X1:%s\n",X1);
    flag=0;
	for(j=1,k2;j<=MAX;j++)
	{
		if(!flag && !x2[j])continue;  //去除前导0
		flag = 1;
		X2[k2++]=x2[j]+'0';
   //    printf("%c",X2[k2-1]);
  //     printf(" k:%d ",k2-1);
	}
//	printf("X2:%s\n",X2);
	if(compare(X1,X2)==0)//大于 
	{
		return -1;//由大到小排列 
	}
	if(compare(X1,X2)==1)//小于
	{
		return 1;
	 }
	else{
		if(compare(P1.x,P2.x)==0)
		{
			return 1;
		}
		if(compare(P1.x,P2.x)==1)
		{
			return -1;
		}
		else{
		if(compare(P1.y,P2.y)==0)
		{
			return 1;
		}
		if(compare(P1.y,P2.y)==1)
		{
			return -1;
		}
		}
	}
	
}

int main()
{
	int n;
	scanf("%d",&n);
	struct point P[n];
	int i=0;
	for(i=0;i<n;i++)
	{
		scanf("%s%s",P[i].x,P[i].y );
	}
	qsort(P,n,sizeof(P[0]),cmp);
	int ans[MAX]={0};
	distance(P[0],P[1],ans);
	/*printf("排序后：\n");
    for(int z=0;z<n;z++)
    {
    	printf("%s %s\n",P[z].x,P[z].y );
	}*/
//	printf("ans:");
	print(ans);
	
	int step=0;
	
	for(i=0;i<n;i++)
	{
		int d[MAX]={0};
		distance(P[i],P[i+1],d);
	//	printf("d:");
	//	print(d);
		if(d[MAX]%2!=0)
		{
			for(int j=1;j<=64;j++)
			{
				unsigned long long f=1,f1,f2;
				f1=f<<j;
				f2=f<<62;
			//	printf("f1:%lld\n",f1);
			//	printf("f2:%lld\n",f2);
				char tf1[MAX]={0},F1[MAX]={0};
				char tf2[MAX]={0},F2[MAX]={0};
				int t1=0,t2=0;
			//	printf("tf1:");
				while(f1>0)
				{
					tf1[t1++]=f1%10+'0';
			//		printf("%c",tf1[t1-1]);
					f1=f1/10;
				}
			//	printf("\n");
			//	printf("tf2:");
				while(f2>0)
				{
					tf2[t2++]=f2%10+'0';
			//		printf("%c",tf2[t2-1]);
					f2=f2/10;
				}
			//	printf("\n");
				t1=strlen(tf1)-1;
				t2=strlen(tf2)-1;
				int i=0;
				while(t1>=0)
				{
					F1[i++]=tf1[t1];
					t1--;
				}
				i=0;
				while(t2>=0)
				{
					F2[i++]=tf2[t2];
					t2--;
				}
		//		printf("F1:%s\n",F1);
			//	printf("F2:%s\n",F2);
				//d转成字串 
	            int flag = 0;
	            char D[MAX]={0};
	            for(int z=1,i=0;z<=MAX;z++)
            	{
	            	if(!flag && !d[z])  continue;  //去除前导0
		            flag = 1;
		            D[i++]=d[z]+'0';
                    //printf("%d",x1[j]);
             	}
             //	printf("D:%s\n",D);
	
				if(compare(D,F1)!=0)//大于返回0，小于返回1,等于返回-1 
				{
					step+=j;
				//	printf("j:%d\n",j);
					break;
				}
				if(compare(D,F2)==0)
				{
					step+=64;
				//	printf("j:%d\n",j);
					break;
				}
			}
		}
		else{
			break;
		}
	}
	printf("%d",step);
	return 0;
}