#include<stdio.h>
#include<math.h>
void output(int *a,int beg,int end)
{
    int wid=end-beg+1;
    int res[10];
    int num;
    num=a[beg]*100+a[beg+1]*10+a[beg+2];
    int j=9;
    while(num!=0)
    {
        res[j]=num&1;
        num>>=1;
        j--;
    }
    for(j=0;j<3*wid+1;j++) printf("%d",res[j]);
}
int main()
{
    int num[500];
    char c;
    int i=0;
    while((c=getchar())!=EOF)
    {
        num[i]=c-'0';
        i++;
    }
    int head[10];
    for(int j=0;j<10;j++) head[j]=0;
    int nums=i-1,j=9;
    while(nums!=0)
    {
        head[j]=nums&1;
        nums>>=1;
        j--;
    }
    printf("0001");
    for(int m=0;m<10;m++) printf("%d",head[m]);
    int beg=0,end=beg+2;
    int res[10];
    for(beg=0;beg<i-1;beg+=3)
    {
        end=(beg+2<i-2)?beg+2:i-2;
        int wid=end-beg+1;
        for(int j=0;j<10;j++) res[j]=0;
        int ans=0;
        for(int j=0;j+beg<=end;j++) ans+=num[end-j]*pow(10,j);
        int j=wid*3;
        while(ans!=0)
        {
            res[j]=ans&1;
            ans>>=1;
            j--;
        }
        for(int j=0;j<wid*3+1;j++) printf("%d",res[j]);

    }

}