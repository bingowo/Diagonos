public class problem4 {
    public static void main(String []args){
        int x1=Integer.parseInt(args[0]);
        int y1=Integer.parseInt(args[1]);
        int x2=Integer.parseInt(args[2]);
        int y2=Integer.parseInt(args[3]);
        double m=Math.pow(x1-x2,2);
        double n=Math.pow(y1-y2,2);
        double ans=Math.sqrt(m+n);
        System.out.println(ans);
    }
}