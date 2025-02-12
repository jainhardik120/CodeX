import java.awt.*;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.AWTException;
import java.util.HashMap;

public class robo {


    private static HashMap<String, Integer> commandKeys = new HashMap<>();

    public static void main(String[] args){
        
        commandKeys.put("Ctrl", KeyEvent.VK_CONTROL);
        commandKeys.put("Win", KeyEvent.VK_WINDOWS);
        commandKeys.put("Shift", KeyEvent.VK_SHIFT);
        try{
            int keyCode = commandKeys.get("fd");
        }catch(Exception e){
            e.printStackTrace();
            System.out.println("Error");
        }
        
    }
}
