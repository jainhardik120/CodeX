// import java.io.*;
// import java.net.*;
// import java.util.*;
// import java.awt.*;
// import java.awt.event.KeyEvent;
// import java.lang.*;

public class Main {
    private static ServerSocket serverSocket;
    private static Socket clientSocket;
    private static InputStreamReader inputStreamReader;
    private static BufferedReader bufferedReader;
    private static String str;
    private static Robot robot;

    public static void sleep(long ms) {
        try {
            Thread.sleep(ms);
        } catch (Exception ignored) {
        }
    }

    public static void main(String[] args) {
        // try {
        //     Enumeration e = NetworkInterface.getNetworkInterfaces();
        //     while (e.hasMoreElements()) {
        //         NetworkInterface n = (NetworkInterface) e.nextElement();
        //         Enumeration ee = n.getInetAddresses();
        //         while (ee.hasMoreElements()) {
        //             InetAddress i = (InetAddress) ee.nextElement();
        //             System.out.println(i.getHostAddress());
        //         }
        //     }
        // } catch (SocketException e2) {
        //     System.out.println(e2.getMessage());
        // }

        try{
            final DatagramSocket socket = new DatagramSocket();
            socket.connect(InetAddress.getByName("8.8.8.8"), 10002);
            String ip = socket.getLocalAddress().getHostAddress();
            System.out.println(ip);
          } catch(SocketException e){
            System.out.println(e);
          } catch(UnknownHostException e){
            System.out.println(e);
          }

        try {
            serverSocket = new ServerSocket(9155);
        } catch (IOException e2) {
            System.out.println(e2.getMessage());
        }
        System.out.println("Listening on 9155");
        try {
            robot = new Robot();
        } catch (AWTException exception) {
            System.out.println(exception.getMessage());
        }
        while (true) {
            try {
                clientSocket = serverSocket.accept();
                inputStreamReader = new InputStreamReader(clientSocket.getInputStream());
                bufferedReader = new BufferedReader(inputStreamReader);
                str = bufferedReader.readLine();
                if (str.equals("Over")) {
                    break;
                }
                System.out.println(str);
                // try {
                //     int number = Integer.parseInt(str);
                //     try {
                //         robot.keyPress(number);
                //     } catch (IllegalArgumentException ex) {
                //         ex.printStackTrace();
                //     }
                //     // System.out.println(number); // output = 25
                // } catch (NumberFormatException ex) {
                //     ex.printStackTrace();
                // }
                for (int i = 0; i < str.length(); i++) {
                // Check if the current character is a capital letter
                // if (Character.isUpperCase(str.charAt(i))) {
                // // Press shift key
                // robot.keyPress(KeyEvent.VK_SHIFT);
                // // Press the current character
                // robot.keyPress(Character.toUpperCase(str.charAt(i)));
                // // Release shift key
                // robot.keyRelease(KeyEvent.VK_SHIFT);
                // }
                // // else display the character as it is
                // else
                // robot.keyPress(Character.toUpperCase(str.charAt(i)));
                // // wait for 200ms
                // sleep(20);

                int keyCode = KeyEvent.getExtendedKeyCodeForChar(str.charAt(i));
                if (KeyEvent.CHAR_UNDEFINED == keyCode) {
                    throw new RuntimeException(
                        "Key code not found for character '" + str.charAt(i) + "'");
                }
                robot.keyPress(keyCode);
                robot.delay(10);
                robot.keyRelease(keyCode);
                robot.delay(10);

                }
                inputStreamReader.close();
                clientSocket.close();
            } catch (IOException e2) {
                System.out.println(e2.getMessage());
            }
        }
    }
}
