#include <stdio.h>
#include <string.h>
int main(){
    int k=0;
    int test=0;
    char s[1000];
    scanf("%s",s);
    char t[1000];
    for(int i=0;i<strlen(s);i++)  //16Ω¯÷∆◊™◊™Œ™2Ω¯÷∆
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
    } 
    t[k]=0;
//    printf("%s\n",t);//≤‚ ‘¥˙¬Î 

    while(t[test]=='0')
	{
		test++;
	}
	test++;
//	printf("%d\n",test); //≤‚ ‘¥˙¬Î 

// ˝◊Ès¥Ê∑≈16Ω¯÷∆(»•µÙ0x)£¨ ˝◊Èt¥Ê∑≈◊™ªª∫Ûµƒ2Ω¯÷∆

    long long int qr=0,qi=0;
    long long int a,b;
    for(int i=test;i<k;i++)   //º∆À„∏¥ ˝’˚ ˝
    {

        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;qi=b;
//        printf("%lld %lld\n",qr,qi);  //≤‚ ‘¥˙¬Î 
    }
    if(qi==0)     // ‰≥ˆ£¨√ª”––È≤ø
    {
        printf("%lld\n",qr);
    }
    else       // ‰≥ˆ£¨”––È≤ø
    {
        if(qr!=0)  //”– µ≤ø
        {
            printf("%lld",qr);
            if(qi>0) printf("+");
        }
        if(qi==1) printf("i\n");
        else if(qi==-1) printf("-i\n");
        else {printf("%lld",qi);printf("i\n");}
    }
    return 0;

}
