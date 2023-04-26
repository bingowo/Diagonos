 #include <iostream>
 #include <string>
 using namespace std;
 string x[] = { "A","B","C" };
 void del(int& ans,string tmp)
 {
     int len=tmp.size();
     while()
     {
         int flag=;//判断是否可以继续消除
         for(string::iterator it=tmp.begin(),t,s;it<tmp.end()-;)//小心it越界
             if(*(it+)==*it)
             {
                 flag=;
                 int x=it-tmp.begin();//x记录上次消除位置，以便从后继续消除
                 t=it;
                 while(it<tmp.end()-&&*(it+)==*it) it++;
                 tmp.erase(t,it+);
                 x=x<?:x;
                 it=tmp.begin()+x;
             }
             else it++;
         if(flag==) break;
     }
     ans=ans>(len-tmp.size())?ans:len-tmp.size();
 }
 int main()
 {
     int T;cin>>T;
     for(int m=;m<T;m++)
     {
         string s;cin>>s;
         int ans=;
         for(int i=;i<=s.size();i++)
         {
             for(int j=;j<;j++)
             {
                 string tmp=s;tmp.insert(i,x[j]);
                 del(ans,tmp);
             }
         }
         printf("case #%d:\n%d\n",m,ans);
 
     }
     return ;
 }