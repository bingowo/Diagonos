//#include <iostream>
//#include <cstring>
//using namespace std;
#include<stdio.h>
#include<string.h>

//void fun(string s)
void fun(char* str,int len)
{
    int j;
    char s[50];
    for(j=0;j<len;j++)
        s[j]=*(str++);
	int i;
    //int len=s.length();
    //int len=strlen(s);
    if(len<=1)
    {
        //cout<<len<<endl;
        printf("%d\n",len);
        return;
    }
    int max=0,t=1;
    if(s[1]!=s[0]) max=2;
    else max=1;
    t=max;
    for(i=2; i<len; i++)
    {
        if(s[i]!=s[i-1])
            t++;
        else
        {
            if(t>max) max=t;
            t=1;
        }
    }
    if(t>max) max=t;
    //cout<<max<<endl;
    printf("%d\n",max);
}
int main()
{
    //string str;
    char str[50];
    scanf("%s",&str);
    //while(cin>>str)
    //while()
    //{
    int l=strlen(str);
    char *s=str;
    fun(s,l);
    //}
    return 0;
}