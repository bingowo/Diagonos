#include<bits/stdc++.h>
using namespace std;
int T,len,cnt,num;
char tmp;
long long rst,base;
string s;
bool a[125];
int i,j,k;
int jdg(char c)
{
    if((c>='0'&&c<='9')||(c>='a'&&c<='z')||(c>='A'&&c<='Z'))return 1;
    return 0;
}
int main()
{
    cin>>T;
    for(i=0;i<T;++i){
        cin>>s;
        len=s.length();
        memset(a,1,sizeof(a));
        for(cnt=j=0;j<len;++j)if(a[s[j]])a[s[j]]=0,++cnt;
        cout<<"case #"<<i<<":\n";
        if(cnt==1)cout<<pow(2,len)-1<<endl;
        else{
            memset(a,1,sizeof(a));
            tmp=s[0],s[0]=1,a[tmp]=0;
            for(j=1;j<len;++j)if(s[j]==tmp)s[j]=1;
            for(j=1;j<len;++j){
                if(a[s[j]]&&jdg(s[j])){
                    tmp=s[j],s[j]=0,a[tmp]=0;
                    for(k=j+1;k<len;++k)if(s[k]==tmp)s[k]=0;
                    break;
                }
            }
            for(num=j=2;j<len;++j){
                if(a[s[j]]&&jdg(s[j])){
                    tmp=s[j],s[j]=num,a[tmp]=0;
                    for(k=j+1;k<len;++k)if(s[k]==tmp)s[k]=num;
                    ++num;
                }
            }
            for(j=len-1,rst=1,base=1;j>=0;--j){
                rst+=base*s[j],base*=cnt;
            }
            cout<<rst-1<<endl;
        }
    }
    return 0;
}