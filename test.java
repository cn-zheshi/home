import java.io.*;

public class test{
    public static void main(String[] args){
        String path = "./test.txt";
        try{
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            String s=new String(br.readLine());
            BufferedWriter bw=new BufferedWriter(new FileWriter(path));
            bw.write(path);
            System.out.println(path);
            bw.newLine();
            bw.write(s);
            System.out.println(s);
            bw.flush();
            bw.close();
            br.close();
            br=new BufferedReader(new FileReader(path));
            while((s=br.readLine())!=null){
                if(s.equals("hello")){
                    throw new IOException("message");
                }
            }
            br.close();
        }catch(IOException e){
            System.out.print(e.getMessage());
        }
    }
}