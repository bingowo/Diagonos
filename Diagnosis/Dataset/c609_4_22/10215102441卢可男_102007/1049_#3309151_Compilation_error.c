提交 #3006912
#	送交者	题目	语言	提交时间	评测时间	结果	耗时	内存	评测机
3006912	10215102441	1049. A-B(Big Integer)	C	2022-04-25 15:46:22	2022-04-25 15:46:23	
Accepted: 100
0.008	0.480	Seattle
 C
 Copy
#include<stdio.h>
#include<string.h>
#define L 500
void input(int*a,char*s);
int compare(int*a,int*b);
void sub(int*a,int*b,int*c,int r);
void sub_0(int*a,int*b,int*c);
void output(int*a,int r);
int main()
{
    char s1[L]={0};
    char s2[L]={0};
    while(scanf("%s %s",s1,s2)!=EOF)
    {
        int r;
        int a[L]={0};
        int b[L]={0};
        int c[L]={0};
        input(a,s1);
        input(b,s2);
        r=compare(a,b);
        sub(a,b,c,r);
        output(c,r);
    }
    return 0;
}
void input(int*a,char*s)
{
    int i,j;
    for(j=L-1,i=strlen(s)-1;i>=0;i--,j--)
    {
        a[j]=s[i]-'0';
    }
}
int compare(int*a,int*b)
{
    int i;
    int r=1;
    for(i=0;i<L;i++)
    {
        if(a[i]>b[i])
        {
            r=1;
            break;
        }
        if(a[i]<b[i])
        {
            r=-1;
            break;
        }
    }
    return r;

}
void sub(int*a,int*b,int*c,int r)
{
    r==1?sub_0 (a,b,c):sub_0 (b,a,c);
}
void sub_0(int*a,int*b,int*c)
{
    int i,j,k;
    for(i=L-1;i>=0;i--)
    {
        if(a[i]<b[i])
        {
            for(j=i-1;j>=0;j--)
            {
                if(a[j]>0)break;
            }
            a[j]-=1;
            for(k=j+1;k<i;k++)
            {
                a[k]=9;
            }
            a[i]+=10;
        }
        a[i]-=b[i];
        c[i]=a[i];
    }
}
void output(int*c,int r )
{
    int i=0;
    int j;
    if(r==-1)printf("-");
   while(c[i]==0&&i<L)i++;
   if(i>=L)printf("0");
   for(j=i;j<L;j++)
   {
       printf("%d",c[j]);
   }printf("\n");


}
评测报告
只显示前 512 个字节
测试点 #1: time: 0.008s, memory: 0.480 MB, exit code: 0, verdict: ACCEPTED
input
1 2
2 3
1231231231823192 123123123123123
1000000000000000 1
1 1000000000000000000
1 1
1 9
9999 9999
9999 1
99999999999999999999999 99999999999999999999999
10 100000
6685020856 2131925371
82264288342238069219 18864502492740843433
996762868251070140713538432958 653530960193259996988761659988
4985657219011018662855925106350514391486 9126307940844100407025687995766029118322
83953656792698523498691023947629029699099216388950 44540848008627016801272089225426372727783293863916
1005898053483212014478668121894857859...
output
-1
-1
1108108108700069
999999999999999
-999999999999999999
0
-8
0
9998
0
-99990
4553095485
63399785849497225786
343231908057810143724776772970
-4140650721833081744169762889415514726836
39412808784071506697418934722202656971315922525034
-296753003192685815784853330914827606737625058556880884044434
-74449953682408447487194991518672597694114385211315345472879205804248
21144267401229771297519491449724693388894705698857748181263192015221098787818513
-39904884669230477008896344919915971014031152699719012442981849...
answer
-1
-1
1108108108700069
999999999999999
-999999999999999999
0
-8
0
9998
0
-99990
4553095485
63399785849497225786
343231908057810143724776772970
-4140650721833081744169762889415514726836
39412808784071506697418934722202656971315922525034
-296753003192685815784853330914827606737625058556880884044434
-74449953682408447487194991518672597694114385211315345472879205804248
21144267401229771297519491449724693388894705698857748181263192015221098787818513
-39904884669230477008896344919915971014031152699719012442981849...
checker's comment
ok
#	提交时间	评测时间	语言	评测结果	耗时	内存
3006912	2022-04-25 15:46:22	2022-04-25 15:46:23	C	
Accepted: 100
0.008	0.480
3006901	2022-04-25 15:43:16	2022-04-25 15:43:16	C	
Wrong answer: 0
0.007	0.480
3006862	2022-04-25 15:30:32	2022-04-25 15:30:32	C	
Wrong answer: 0
0.008	0.480
3006818	2022-04-25 15:18:25	2022-04-25 15:18:26	C	
Runtime error: 0
0.006	0.605
3003881	2022-04-21 14:30:27	2022-04-21 14:30:27	C	
Accepted: 100
0.007	0.480
3003878	2022-04-21 14:28:36	2022-04-21 14:28:36	C	
Compilation error: 0
N/A	N/A
3003874	2022-04-21 14:27:39	2022-04-21 14:27:39	C	
Compilation error: 0
N/A	N/A
2993048	2022-04-11 15:40:40	2022-04-11 15:40:40	C	
Accepted: 100
0.006	0.480
2992981	2022-04-11 15:30:13	2022-04-11 15:30:14	C	
Wrong answer: 0
0.009	0.605
2991339	2022-04-10 13:50:40	2022-04-10 13:50:41	C	
Runtime error: 0
0.005	0.449
2991318	2022-04-10 13:24:13	2022-04-10 13:24:13	C	
Compilation error: 0
N/A	N/A
2991286	2022-04-10 12:46:51	2022-04-10 12:46:51	C	
Runtime error: 0
0.006	0.605
2991284	2022-04-10 12:45:22	2022-04-10 12:45:22	C	
Wrong answer: 0
0.005	0.355
服务
首页
反馈
Polygon
Wiki
开源
Github
eJudge
关于我们
团队: @ultmaster, @zerol, @kblack.
联系方式: acmsupport@admin.ecnu.edu.cn