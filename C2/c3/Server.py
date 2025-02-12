from socket import *
serverSocket = socket(AF_INET, SOCK_STREAM)
serverSocket.bind(("", 80))
serverSocket.listen(1)
while True:
	print ("Ready to serve...")
	connectionSocket, addr = serverSocket.accept()
	print(addr)
	try:
		message =  connectionSocket.recv(1024).decode("utf-8")
		connectionSocket.send("HTTP/1.1 200 OK\r\n\r\n".encode('utf-8'))
		connectionSocket.close()

	except IOError as err:
		print("IOError : " + err)
		connectionSocket.close()

serverSocket.close()

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
	
    