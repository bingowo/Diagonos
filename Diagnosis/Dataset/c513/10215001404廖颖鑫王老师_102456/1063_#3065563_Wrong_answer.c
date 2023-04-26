int main()
{
   unsigned int x,y,ans=0,temp;
   scanf("%u %u",&x,&y);

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
       printf("%u",ans);
   }
   return 0;
}
