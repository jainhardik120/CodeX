// A Java program for a Client
import java.io.*;
import java.net.*;

public class Client {
	// initialize socket and input output streams
	private Socket socket = null;
	private DataInputStream input = null;
	private DataOutputStream out = null;

	// constructor to put ip address and port
	public Client(String address, int port)
	{
		// establish a connection
		System.out.println(address + " " + port);
		try {
			socket = new Socket(address, port);
			System.out.println("Connected");
			out = new DataOutputStream(
				socket.getOutputStream());
		}
		catch (UnknownHostException u) {
			System.out.println(u);
			return;
		}
		catch (IOException i) {
			System.out.println(i);
			return;
		}

		String line = "";
		int count = 0;
		// keep reading until "Over" is input
		while (!line.equals("Over") && count < 10) {
			try {
				line = "hello\n\0";
				out.writeUTF(line);
				count++;
			}
			catch (IOException i) {
				System.out.println(i);
			}
		}

		// close the connection
		try {
			input.close();
			out.close();
			socket.close();
		}
		catch (IOException i) {
			System.out.println(i);
		}
	}

	public static void main(String args[])
	{
		Client client = new Client("10.103.160.67", 27015);
		// Client client = new Client("127.0.0.1", 9155);
	}
}
