
int main()
{
   unsigned long long int x,y,ans=0,temp;
   scanf("%llu %llu",&x,&y);

   while(x%y!=0)
   {
      ans+=(x/y)*4*y;
      temp=y;
      y=x%y;
      x=temp;
   }
   if(x%y==0)
   {
       ans+=4*x;
       printf("%llu",ans);
   }
   return 0;
}
