import java.lang.*;

public class MyClass{
    public static void main(String args[]){
        Runtime runtime = Runtime.getRuntime();
        System.out.println(runtime.availableProcessors());
        System.out.println(runtime.totalMemory()/8/1024/1024);
        System.out.println(runtime.freeMemory());
    }
};