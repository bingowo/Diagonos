#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int panduan2(int*q1,int*q2,int lenq1,int lenq2)//判断q1,q2哪个大大于零代表q2大
{
   if(lenq1!=lenq2) return  lenq2-lenq1;
   else
   {
       char a1[lenq1+1],a2[lenq2+1];
       for(int i=0;i<lenq1;i++)
         a1[i]=q1[lenq1-i-1]+'0';
       for(int i=0;i<lenq2;i++)
       a2[i]=q2[lenq2-i-1]+'0';
       return strcmp(a2,a1);
   }
}
void chuli(int *qr,int flagqr,int *lenqr,int*qi,int flagqi,int *lenqi,int *a,int *flaga,int *lena)//实现flagqr*qr+flagqi*qi存放在a里
{


    //printf("%d %d",lena,lenb);
    int max=(lenqr[0]>lenqi[0])?lenqr[0]:lenqi[0];
    if(flagqr*flagqi==1)
    {
        flaga[0]=flagqr;
        int yu=0;
        for(int i=0;i<max;i++)
            {a[i]=(qi[i]+qr[i]+yu)%10;
            yu=(qi[i]+qr[i]+yu)/10;}
        while(yu!=0) {a[max]=yu;yu/=10;max++;}
        lena[0]=max;
    }

    if(flagqr*flagqi==-1)
    {
        if(panduan2(qr,qi,lenqr[0],lenqi[0])<0)
        {
           flaga[0]=flagqr;
           int jie=0;
           for(int i=0;i<max;i++)
           {
               a[i]=qr[i]-qr[i]-jie;
               if(a[i]<0) {a[i]+=10;jie++;}
               else jie=0;
           }


        }
        if(panduan2(qr,qi,lenqr[0],lenqi[0])>0)
        {
            flaga[0]=flagqi;
            int jie=0;
            for(int i=0;i<max;i++)
            {
                a[i]=qi[i]-qr[i]-jie;
                if(a[i]<0) {a[i]+=10;jie++;}
                else jie=0;
            }
        }
        lena[0]=max;
    }

}

int main()
{
    char l2,l1;
    scanf("%c%c",&l1,&l2);
    char s[10000];
    scanf("%s",&s);
    char t[10000];
    int k=0;
    for(int i=0;i<strlen(s);i++)  //16进制转转为2进制
    {
        int d;
        if(s[i]>='A') d=s[i]-'A'+10;
        else d=s[i]-'0';
        unsigned int flag=0x8;
        while(flag)
        {
            if(d&flag) t[k++]='1';
            else t[k++]='0';
            flag=flag>>1;
        }
    }   //数组s存放16进制(去掉0x)，数组t存放转换后的2进制
    //for(int d=0;d<k;d++) printf("%d ",t[d]-48);
     int qr[10000]={0},qi[10000]={0},a[10000]={0},b[10000]={0};
     int flagqi[1],flagqr[1],flaga[1],flagb[1],lenqr[1],lenqi[1],lena[1],lenb[1];
     flagqi[0]=1;flagqr[0]=1;flaga[0]=1;flagb[0]=1,lenqr[0]=1,lenqi[0]=1,lena[0]=1,lenb[0]=1;
    for(int i=0;i<k;i++)
    {
        int r=t[i]-'0';
        chuli(qr,flagqr[0]*-1,lenqr,qi,flagqi[0]*-1,lenqi,a,flaga,lena);//实现a=-qr-qi
        a[0]+=r;//实现a+r
        int yu=0;//有进位就进位
        for(int m=0;m<strlen(a);m++)
        {
            int z=a[m];
            a[m]=(a[m]-+yu)%10;
            yu=(z+yu)/10;
        }
        if(yu!=0) {a[lena[0]]=yu;yu/=10;lena[0]++;}
        chuli(qr,flagqr[0],lenqr,qi,flagqi[0]*-1,lenqi,b,flagb,lenb);//实现b=qr-qi
        strcpy(qr,a);strcpy(qi,b);//实现qr=a,qi=b
        lenqr[0]=lena[0];lenqi[0]=lenb[0];
        flagqr[0]=flaga[0];flagqi[0]=flagb[0];
        memset(a,0,10000);memset(b,0,10000);//初始化a,b
    }
    char a1[10000],a2[10000];//将qr,qi倒序放在字符串a1,a2中输出
    int t1=lenqr[0]-1,t2=lenqi[0]-1;//除去末尾的零
    while(qr[t1]==0) t1--;
    while(qi[t2]==0) t2--;
    for(int k=0;k<t1;k++)
        a1[k]=qr[t1-k-1]+'0';
    for(int k=0;k<t2;k++)
        a2[k]=qi[t2-k-1]+'0';
    a1[t1]='\0';a2[t2]='\0';
    if(t2==0)     //输出，没有虚部
    {
        if(flagqr[0]==-1) printf("-");
        printf("%s",a1);
    }
    else       //输出，有虚部
    {
        if(t1!=0)  //有实部
        {
            if(flagqr[0]==-1) printf("-");
            printf("%s",a1);
            if(flagqi>0) printf("+");
        }
        if(t2==1&&a2[0]=='1') printf("i\n");
        else if(t2==1&&flagqi[0]==-1&&a2[0]=='1') printf("-i\n");
             else
                {
                    if(flagqi[0]==-1) printf("-");
                    printf("%s",a2);printf("i\n");
                 }
    }
 return 0;
}
