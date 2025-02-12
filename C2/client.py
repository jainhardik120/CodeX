# An example script to connect to Google using socket
# programming in Python
import socket # for socket
import sys 
 
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    print ("Socket successfully created")
except socket.error as err:
    print ("socket creation failed with error %s" %(err))
 
# default port for socket
port = 80
 
try:
    host_ip = socket.gethostbyname('localhost')
except socket.gaierror:
 
    # this means could not resolve the host
    print ("there was an error resolving the host")
    sys.exit()
 
# connecting to the server
s.connect((host_ip, port))
 
print ("the socket has successfully connected to server on port == %s" %(host_ip))
MESSAGE = 'GET /helloworld.html HTTP/1.1\nHost: localhost:85'
s.send(MESSAGE.encode('utf-8'))
i=0
while True:
    data = s.recv(1024)
    if not data:
        break
    print (data.decode("utf-8"));
    i=i+1
s.close()