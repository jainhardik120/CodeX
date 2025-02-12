from socket import *
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((gethostbyname('localhost'), 80))
try:
	clientSocket.send("HTTP/1.1 200 OK\r\n\r\n".encode('utf-8'))
	
	message =  clientSocket.recv(1024).decode("utf-8")
	print(message)
	clientSocket.close()

except IOError:
	print("IOError")
	clientSocket.close()