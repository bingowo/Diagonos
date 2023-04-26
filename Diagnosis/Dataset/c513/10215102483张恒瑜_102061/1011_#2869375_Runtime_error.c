#include<stdio.h>
#include<string.h>
long long res[2];
char tmp[4];

void solveinput(char x)
{
    switch (x)
    {
        case '0':sprintf(tmp,"0000");break;
        case '1':sprintf(tmp,"0001");break;
        case '2':sprintf(tmp,"0010");break;
        case '3':sprintf(tmp,"0011");break;
        case '4':sprintf(tmp,"0100");break;
        case '5':sprintf(tmp,"0101");break;
        case '6':sprintf(tmp,"0110");break;
        case '7':sprintf(tmp,"0111");break;
        case '8':sprintf(tmp,"1000");break;
        case '9':sprintf(tmp,"1001");break;
        case 'A':sprintf(tmp,"1010");break;
        case 'B':sprintf(tmp,"1011");break;
        case 'C':sprintf(tmp,"1100");break;
        case 'D':sprintf(tmp,"1101");break;
        case 'E':sprintf(tmp,"1110");break;
        case 'F':sprintf(tmp,"1111");break;
        default:break;
    }
    return;
}

void solve(int r)
{
    long long a=res[0],b=res[1];
    res[0]=-a-b+r;
    res[1]=a-b;
    return;
}
int main()
{
    char input[100]={'\0'};
    scanf("0x%s",input);
    int i=0,j;
    res[0]=0;res[1]=0;
    solveinput(input[0]);
    while(tmp[i]=='0') i++;
    for(;i<4;i++) solve(tmp[i]-'0');
    for(i=1;i<strlen(input);i++)
    {
        solveinput(input[i]);
        for(j=0;j<4;j++)
        {
            solve(tmp[j]-'0');
        }
    }
    if(res[1]==1) printf("%lld+i",res[0]);
    else if(res[1]==-1) printf("%lld-i",res[0]);
    else if(res[1]==0) printf("%lld",res[0]);
    else if(res[1]>0) printf("%lld+%lldi",res[0],res[1]);
    else printf("%lld%lldi",res[0],res[1]);
    return 0;
}