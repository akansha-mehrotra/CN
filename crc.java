import java.util.*;
public class crc{
    public static int n;
    public static void main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        crc ob=new crc();
        String code,copy,zero="0000000000000000";
        System.out.print("Enter polynomial: ");
        code=in.nextLine();
        System.out.println("Generating polynomial: 10001000000100001");
        n=code.length();
        copy=code;
        code+=zero;
        System.out.println("Modified polynomial: "+code);
        code=ob.divide(code);
        System.out.println("CheckSum: "+code.substring(n));
        copy=copy.substring(0,n)+code.substring(n);
        String results=copy;
        System.out.println("Final Codeword: "+copy);
        System.out.print("Enter polynomial at receiver's end: ");
        code=in.nextLine();
        n=code.length();
        copy=code;
        code+=zero;
        code=ob.divide(code);
        copy=copy.substring(0,n)+code.substring(n);
        if (copy.equals(results)==true)
        {
            System.out.println("No Error Detected");
        }
        else
        {
            System.out.println("Received codeword: "+copy);
            System.out.println("Error detected");
        }
    }
    public String divide(String s){
        int i,j;
        char x;
        String div="10001000000100001";

        for(i=0;i<n;i++){
            x=s.charAt(i);

            for(j=0;j<17;j++){
                if(x=='1'){
                    if(s.charAt(i+j)!=div.charAt(j))
                        s=s.substring(0,i+j)+"1"+s.substring(i+j+1);
                    else
                        s=s.substring(0,i+j)+"0"+s.substring(i+j+1);
                }
            }
        }
        return s;
    }
}
