#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define C 5000

/*格式化读入的字符串，便于获取数值*/
void motify(char* s)//以+分隔实部和虚部,实部和虚部都有数字
{
    int len=strlen(s),i,j;
    if(s[len-1]!='i'){s[len]='+';s[len+1]='0';s[len+2]='i';s[len+3]='\0';return;}//只有整数
    for(i=0;i<len;i++)
    {
        if(s[i]=='+'&&s[i+1]=='i'){s[len]='i';s[len-1]='1';s[len+1]='\0';return;}//+i->+1i
        else if(s[i]=='-')
        {
            if(i!=0)//中间减号
            {
                if(s[i+1]=='i'){s[i]='+';s[i+1]='-';s[i+2]='1';s[i+3]='i';s[i+4]='\0';return;}//-i->+-1i
                else//-bi->+-bi
                {
                    for(j=len;j>i;--j)s[j]=s[j-1];
                    s[i]='+';s[len+1]='\0';return;
                }
            }
            else //开头减号
            {
                if(!(strchr(s,'+')))
                {
                    for(j=len+1;j>1;j--)s[j]=s[j-2];
				    s[0]='0';s[1]='+';s[len+2]='\0';//-bi->0+-bi
                    if(s[3]=='i'){s[3]='1';s[4]='i';s[5]='\0';}//-i->0+-1i
                    return;
                }
            }
        }
    }
}



/*用获取的数值初始化数组*/
void init(int* A,int a)
{
    if(a<0){A[0]=-1;a*=-1;}
    else if(a==0)A[0]=0;
    else A[0]=1;
    int tmp[5],cnt=0,i,j;
    while(a)
    {
        tmp[cnt++]=a%10;
        a/=10;
    }
    for(i=0,j=C-1;i<cnt;++i,--j)A[j]=tmp[i];
    return;
}

/*大整数a*b,a带符号*/
void mult(int* a,int b)//a*b(带符号)
{
    int carry=0,tmp,i;
    if(b<0){a[0]*=-1;b*=-1;}
    if(!b){memset(a,0,4*C);return;}
    for(i=C-1;i>0;--i)
    {
        tmp=a[i]*b+carry;
        if(tmp>=10){a[i]=tmp%10;carry=tmp/10;}
        else {a[i]=tmp;carry=0;}
    }
}


/*比较两个符号相反的大整数的绝对值大小*/
int compare(const int* addend1,const int* addend2)
{
    int i;
    i=1;while(i<C&&addend1[i]==addend2[i])i++;
    if(i==C)return 0;
    else if(addend1[i]<addend2[i]&&addend1[0]==-1)return 1;//负数加正数大于0
    else if(addend1[i]<addend2[i]&&addend1[0]==1)return 2;//正数加负数小于0
    else if(addend1[i]>addend2[i]&&addend1[0]==-1)return 3;//负数加正数小于0
    else if(addend1[i]>addend2[i]&&addend1[0]==1)return 4;//正数加负数大于0
}

/*大整数减法*/
void sub(int* dest_arr,const int* addend1,const int* addend2)
{
    int i,j;
    memcpy(dest_arr,addend1,4*C);
    for(i=C-1;i>0;--i)
    {
        if(dest_arr[i]<addend2[i])
        {
            j=i;
            while(!(dest_arr[--i]));
            dest_arr[i]--;
            for(++i;i<j;++i)dest_arr[i]=9;
            dest_arr[i]=10+dest_arr[i]-addend2[i];
        }
        else dest_arr[i]-=addend2[i];
    }
}


/*大整数加法,带符号*/
void add(int* dest_arr,const int* addend1,const int* addend2)
{
    int i,tmp,carry=0;
    if(!addend1[0]){memcpy(dest_arr,addend2,4*C);return;}
    if(!addend2[0]){memcpy(dest_arr,addend1,4*C);return;}
    if((addend1[0]==1&&addend2[0]==1)||(addend1[0]==-1&&addend2[0]==-1))
    {
        dest_arr[0]=addend1[0];
        for(i=C-1;i>0;--i)
        {
            tmp=addend1[i]+addend2[i]+carry;
            if(tmp>=10){dest_arr[i]=tmp%10;carry=tmp/10;}
            else {dest_arr[i]=tmp;carry=0;}
        }
    }
    else
    {
        int flag=compare(addend1,addend2);
        switch (flag)
        {
            case 0:
            {
                memset(dest_arr,0,4*C);
                break;
            }
            case 1://addend1<0,addend2>0,deet_arr>0
            {
                dest_arr[0]=1;
                sub(dest_arr,addend2,addend1);
                break;
            }
            case 2://addend1>0,addend2<0,dest_arr<0
            {
                dest_arr[0]=-1;
                sub(dest_arr,addend2,addend1);
                break;
            }
            case 3://addend1<0,addend2>0,dest_arr<0
            {
                dest_arr[0]=-1;
                sub(dest_arr,addend1,addend2);
                break;
            }
            case 4://addend1>0,addend2<0,dest_arr>0
            {
                dest_arr[0]=1;
                sub(dest_arr,addend1,addend2);
                break;
            }

        }
    }
}


/*复数计算公式*/
void multi(int* R,int *I,int r,int i)
{
    int tmp1[C],tmp2[C],tmp3[C],tmp4[C];
    memcpy(tmp1,R,4*C);memcpy(tmp2,I,4*C);tmp2[0]*=-1;
    memcpy(tmp3,R,4*C);memcpy(tmp4,I,4*C);
    mult(tmp1,r);mult(tmp2,i);
    add(R,tmp1,tmp2);
    mult(tmp3,i);mult(tmp4,r);
    add(I,tmp3,tmp4);
    return;
}


/*输出函数，todo change it according to the init change*/
void print(const int* R,const int* I)
{
	int i;
    if(!R[0]&&!I[0])printf("0");
	else if(!R[0])
	{
		if(I[0]==-1)printf("-");
		for(i=1;i<C;++i)if(I[i])break;
		if(!(i==C-1&&I[i]==1))for(i;i<C;++i)printf("%d",I[i]);
		printf("i");
	}
	else if(!I[0])
	{
		if(R[0]==-1)printf("-");
		for(i=1;i<C;++i)if(R[i])break;
		for(i;i<C;++i)printf("%d",R[i]);
	}
	else
	{
		if(R[0]==-1)printf("-");
		for(i=1;i<C;++i)if(R[i])break;
		for(i;i<C;++i)printf("%d",R[i]);
		if(I[0]==1)printf("+"); else printf("-");
		for(i=1;i<C;++i)if(I[i])break;
		if(!(i==C-1&&I[i]==1))for(i;i<C;++i)printf("%d",I[i]);
		printf("i");
	}
} 

/*程序入口主函数*/
int main()
{
    char s[11],tmp[10];int p,i,j,k,real,image;scanf("%s %d",s,&p);
    motify(s);
    for(i=0;s[i];++i)if(s[i]=='+')break;
    for(j=0;j<i;++j)tmp[j]=s[j];
    tmp[j]='\0';
    real=atoi(tmp);
    for(j=i+1,k=0;s[j]!='i';++j,++k)tmp[k]=s[j];
    tmp[k]='\0';
    image=atoi(tmp);
    int R[C]={0},I[C]={0};
    init(R,real);init(I,image);
    for(i=1;i<p;++i)multi(R,I,real,image);
    print(R,I);
    return 0;
}