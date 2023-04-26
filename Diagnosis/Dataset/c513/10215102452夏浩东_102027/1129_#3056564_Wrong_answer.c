#include <stdio.h>
char in[10001],out[400000];
int main()
{
    int len=0,end=0,count=0,num=0; 
    scanf("%s",in);
    for(int i=0;in[i]!='\0';i++)
    {
        if(in[i]<='z' && in[i]>='a'){
            out[len++]=in[i];
            end=i;
            count++;
        } else if(in[i]<='9' && in[i]>='0' && in[i+1]<='z' && in[i+1]>='a') {
            num = num*10+in[i]-'0';
            for(int j=0;j<num-1;j++){
                for(int m=end-count+1;m<=end;m++){
                    out[len++] = in[m];
                }
            }
            count=num=0;
        } else {
            num = num*10+in[i]-'0';
        }
    }
    for(int i=0;i<len;i++)
    {
        printf("%c",out[i]);
    }
    return 0;
}