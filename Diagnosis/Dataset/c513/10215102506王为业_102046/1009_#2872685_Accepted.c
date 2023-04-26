#include <stdio.h>
#include <stdlib.h>
#include<string.h>
//#define LOCAL
int GCD(int x,int y)//x>y==true
{
    x%=y;//now x is y
    if(x==0)return y;
    else return GCD(y,x);
}
int main()
{
#ifdef LOCAL
freopen("in.txt","r",stdin);
freopen("out.txt","w",stdout);
#endif // LOCAL
    int n;
    scanf("%d",&n);
    getchar();//remove the \n
    char str[150];
    int pos=0;
    char *sp;
    char c;
    int numofone;
    while(n--){
        pos=0;
        while((c=getchar())!='\n'&&c!=EOF){
            str[pos++]=c;
        }
        str[pos]='\0';
        sp=str;
        numofone=0;
        int len=8*pos;
        while(pos--){
            for(int i=0;i<8;++i){
                if(((*sp)&(1<<i))){
                    ++numofone;
                }
            }
            ++sp;
        }
        int tem=GCD(len,numofone);
        printf("%d/%d\n",numofone/tem,len/tem);
    }
    return 0;
}
