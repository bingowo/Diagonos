#include<stdio.h>
#include<string.h>
void add(int* A,int* B)
{
	int sum,carry=0,i;
	for(i=509;i>-1;--i)
	{
		sum=A[i]+B[i]+carry;
		A[i]=sum%10;
		carry=sum/10;
	}
	return;
}
void add1(int* a,int mlf,int N)//a进1
{
    int carry=1,i,tmp;
    for(i=509-mlf+N;i>-1;--i)
    {
        tmp=a[i]+carry;
        if(tmp==10){a[i]=0;carry=1;}
        else {a[i]=tmp;return;}
    }
}
void appro(int* a,int N,int mlf) 
{
	int d,i;
    if(N>=mlf)
    {
        d=N-mlf;
        for(i=0;i<510;++i)if(a[i]&&i<510-mlf)break;
        if(i==510)//第一位非0数字在小数点之后
        {
            for(i=0;i<510;++i)if(a[i])break;
            printf("0.");
            for(i=510-mlf;i<510;++i)printf("%d",a[i]);
            for(i=0;i<d;++i)printf("0");
            return;
        }
        for(i;i<510;++i)
        {
            if(i==510-mlf)printf(".%d",a[i]);
            else printf("%d",a[i]);
        }
        for(i=0;i<d;++i)printf("0");
        return;
    }
    else
    {
        d=mlf-N;
        if(a[510-mlf+N]>=5)add1(a,mlf,N);
        for(i=0;i<510;++i)if(a[i]&&i<510-mlf)break;
        if(i==510)//第一位非0数字在小数点之后
        {
            printf("0.");
            for(i=510-mlf;i<510-d;++i)printf("%d",a[i]);
            return;
        }
        for(i;i<510-d;++i)
        {
            if(i==510-mlf)printf(".%d",a[i]);
            else printf("%d",a[i]);
        }
        return;
    }
}
void motify(char* A)//统一浮点数字符串的格式
{
    int i,lena=strlen(A);
    for(i=0;A[i];++i)if(A[i]=='.')break;
    if(i==lena){A[lena]='.';A[lena+1]='0';A[lena+2]='\0';return;}//没有小数点的情况
    else if(A[0]=='.')//小数点为第一个的情况
    {
        for(i=lena;i>0;i--)A[i]=A[i-1];
        A[0]='0';A[lena+1]='\0';
        return;
    }
    else if(A[lena-1]=='.'){A[lena]='0';A[lena+1]='\0';return;}
}
int main()
{
	char A[510],B[510];scanf("%s %s",A,B);
	int N,i,j,k;scanf("%d",&N);
    motify(A);motify(B);
	for(i=0;A[i];++i)if(A[i]=='.')break;
    int inta=i,floa=strlen(A)-i-1;
    for(j=0;B[j];++j)if(B[j]=='.')break;
    int intb=j,flob=strlen(B)-j-1;
	int lena,lenb,mlf=floa>flob?floa:flob;
	int Ax[510]={0},Bx[510]={0};
	while(floa<mlf){lena=strlen(A);A[lena]='0';A[lena+1]='\0';floa++;}
	while(flob<mlf){lenb=strlen(B);B[lenb]='0';B[lenb+1]='\0';flob++;}
	for(i=511-strlen(A),j=0;i<510;++i,++j)if(j!=inta)Ax[i]=A[j]-48; else i--;
	for(i=511-strlen(B),j=0;i<510;++i,++j)if(j!=intb)Bx[i]=B[j]-48; else i--;
	add(Ax,Bx);
	appro(Ax,N,mlf);
	return 0;
}