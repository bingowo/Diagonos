#include <stdio.h>
#include <string.h>
using namespace std;
char s[100];
int a[1111],b[100];
void change(char s[])
{
 for(int i=0;i<strlen(s);i++)
 {
  if(s[i]>='0'&&s[i]<='9') b[i]=s[i]-'0';
  if(s[i]>='A'&&s[i]<='Z') b[i]=s[i]-'A'+10; //cout<<b[i]<<endl;
  for(int j=4*i+3;j>=4*i;j--)
  {
   a[j]=b[i]%2;
   b[i]/=2; 
  }  
 } //for(int i=0;i<4*strlen(s);i++) cout<<a[i]; cout<<endl;
}
int main()
{
 getchar();
 getchar();
 //unsigned long long n;
 long long ans1=0,ans2=0,p1=-1,p2=1,now1=1,now2=0;
 for(int i=1;i<1111;i++) a[i]=0;
 gets(s);//puts(s);cout<<endl;
 change(s);
 for(int i=4*strlen(s)-1;i>=0;i--)
 {
  if(a[i]&1)
  {
   ans1+=now1;
   ans2+=now2;
  }
  long long temp1=now1*p1-now2*p2,temp2=now1*p2+now2*p1;
  now1=temp1;
  now2=temp2;
  //n>>=1;
 } 
 if(ans1!=0)
 {
  if(ans2>1) cout<<ans1<<"+"<<ans2<<"i"<<endl;
  if(ans2==1) cout<<ans1<<"+"<<"i"<<endl;
  if(ans2==0) cout<<ans1<<endl;
  if(ans2==-1) cout<<ans1<<"-i"<<endl;
  if(ans2<-1) cout<<ans1<<ans2<<"i"<<endl;
 }
 if(ans1==0)
 {
  if(ans2>1||ans2<-1) cout<<ans2<<"i"<<endl;
  if(ans2==1) cout<<"i"<<endl;
  if(ans2==0) cout<<"0"<<endl;
  if(ans2==-1) cout<<"-i"<<endl;
 }

}