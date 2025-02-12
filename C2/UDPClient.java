import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;

public class UDPClient {
    public static void main(String[] args) {
        try {
            // Server details
            String serverHostname = "localhost";
            int serverPort = 2053; // Use the port number your server is listening on

            // Create a DatagramSocket
            DatagramSocket socket = new DatagramSocket();

            // Prepare data to send
            String message = "Hello, UDP Server!";
            byte[] buffer = message.getBytes();

            // Create a packet to send data to the server
            InetAddress serverAddress = InetAddress.getByName(serverHostname);
            DatagramPacket packet = new DatagramPacket(buffer, buffer.length, serverAddress, serverPort);

            // Send the packet
            socket.send(packet);
            System.out.println("Packet sent to the server.");

            // Optionally, receive a response from the server
            byte[] responseBuffer = new byte[1024];
            DatagramPacket responsePacket = new DatagramPacket(responseBuffer, responseBuffer.length);
            socket.receive(responsePacket);

            // Print server's response
            String response = new String(responsePacket.getData(), 0, responsePacket.getLength());
            System.out.println("Response from server: " + response);

            // Close the socket
            socket.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
