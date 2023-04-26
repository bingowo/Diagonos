#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int compare(char *a,char *b);
    char a1[520],b1[520];
    int n;
    memset(a1,'\0',sizeof(a1));
    memset(b1,'\0',sizeof(b1));
    scanf("%s %s",a1,b1);
    scanf("%d",&n);//输入之后先预处理
    char a[520],b[520];
    memset(a,'\0',sizeof(a));
    memset(b,'\0',sizeof(b));
    //printf("4%d4",strlen(a1));
    int finda=0,findb=0;
    for(int gg=0;gg<strlen(a1);gg++)
    {
        if(a1[gg]=='.') finda=1;
    }
     for(int gg=0;gg<strlen(b1);gg++)
    {
        if(b1[gg]=='.') findb=1;
    }
    int lza=strlen(a1),lzb=strlen(b1);
    if(finda==0) a1[lza]='.';
    if(findb==0) b1[lzb]='.';
    int flag;
    if(a1[0]=='.') {
        a[0]='0';
        strcat(a,a1);
    }
    else if(a1[0]!='.') strcpy(a,a1);
    if(b1[0]=='.'){
        b[0]='0';
        strcat(b,b1);
    }
    else if(b1[0]!='.') strcpy(b,b1);//不管正负最后算绝对值的时候就是用a-b
    flag=strcmp(a,b);

    if(flag==-1)
    {
        char temp[520];
        memset(temp,'\0',520);
        strcpy(temp,a);
        strcpy(a,b);
        strcpy(b,temp);
    }
    else if(flag==0)
    {
        printf("0.");
        for(int zz=0;zz<n;zz++)
            printf("0");
        return 0;
    }

    int laa=strlen(a),lbb=strlen(b);
    int la2=0,lb2=0,l;//la2 lb2 代表小数点后的位数
    int i=laa-1;
    while(a[i]!='.') {la2++;i--;}
    i=lbb-1;
    while(b[i]!='.') {lb2++;i--;}
    if(la2>=lb2){
        int dl=la2-lb2;
        l=la2;
        for(int kk=0;kk<dl;kk++)
            b[lbb+kk]='0';
    }
    if(lb2>la2){
        int dl=lb2-la2;
        l=lb2;
        for(int kk=0;kk<dl;kk++)
            a[laa+kk]='0';
    }//到这里预处理完成 l表示的是归一之后小数点之后的位数

    int l0=max(strlen(a),strlen(b));

    int jieflag;//是否要向整数位借数
    for(int enda=strlen(a)-1,endb=strlen(b)-1,j=0;j<l;j++)
    {
        if(a[enda-j]<b[endb-j]) {
            int f=1;
            while(a[enda-j-f]=='0'&&a[enda-j-f]!='.')
            {
                f++;
            }
            if(a[enda-j-f]=='.')
            {
                jieflag=1;
                for(int m=enda-j-f+1,mm=0;mm<f-1;mm++)
                    a[m+mm]+=9;
                a[enda-j]+=10;
            }
            else{
                jieflag=0;
                a[enda-j-f]--;
                for(int m=enda-j-f,mm=1;mm<f;mm++)
                    a[m+mm]+=9;
                a[enda-j]+=10;
            }//分两种情况处理小数部分 并且记录jieflag等到之后的整数部分在处理
            a[enda-j]=a[enda-j]-b[endb-j]+'0';
        }
        else if((a[enda-j]>=b[endb-j]))
        {
            a[enda-j]=a[enda-j]-b[endb-j]+'0';
        }
    }//之后开始处理整数

    int flaga,flagb;
    int k1=0,k2=0;
    while(a[k1]!='.') k1++;
    while(b[k2]!='.') k2++;
    flaga=k1;flagb=k2;
    if(jieflag==1)
    {
        int zzz=1;
        while(a[flaga-zzz]=='0') zzz++;
        a[flaga-zzz]--;
        for(int m=flaga-zzz+1,mm=0;mm<zzz-1;mm++)
                a[m+mm]+=9;
    }
    for(int j=flaga-1,jb=flagb-1;j>=0,jb>=0;j--,jb--)
    {
        if(a[j]>=b[jb]) {a[j]=a[j]-b[jb]+'0';}
        else if(a[j]<b[jb])
        {
            int f=1;
            while(a[j-f]=='0')
            {
                f++;
            }
            a[j-f]--;
            for(int m=j-f+1,mm=0;mm<f-1;mm++)
                a[m+mm]+=9;
            a[j]+=10;
            a[j]=a[j]-b[jb]+'0';
        }
    }
    if(l<n){
        for(int g=0;g<n-l;g++)
            a[l0+g]='0';
    }
    else if(l>n)
    {
        if(a[flaga+n+1]>='5') a[flaga+n]++;
        for(int r=flaga+n;r>=0;r--)
        {
            if(a[r]>='0'+10&&a[r-1]=='.'){a[r]=(a[r]-'0')%10+'0';a[r-2]++;r--;}
            else if(a[r]>='0'+10) {a[r]=(a[r]-'0')%10+'0';a[r-1]++;}
        }
    }
    int start,flagg=0;
    for(int kkk=0;kkk<flaga;kkk++)
    {
        if(a[kkk]!='0') {start=kkk;flagg=1;break;}
    }
    if(flagg==0) start=flaga-1;
    for(int tt=start;tt<=flaga+n;tt++)
      printf("%c",a[tt]);
    return 0;
}
int max(int a,int b)
{
    return (a>=b)?a:b;
}

int min(int a,int b)
{
    return (a>=b)?b:a;
}
