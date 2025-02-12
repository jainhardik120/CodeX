import java.io.*;
import java.net.*;
import java.util.*;
import java.awt.*;
import java.awt.event.KeyEvent;

public class MyKeyboard {
    private static Robot robot;

    public static void sleep(long ms) {
        try {
            Thread.sleep(ms);
        } catch (Exception ignored) {
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        try {
            robot = new Robot();
        } catch (AWTException exception) {
            System.out.println(exception.getMessage());
        }
        
        robot.keyPress(i);
    }
}
