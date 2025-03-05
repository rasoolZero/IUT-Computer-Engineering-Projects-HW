from socket import *
import os

def printCommands():
	print()
	print("HELP : list of commands")
	print("LIST : list of files and directories")
	print("PWD : prints working directory")
	print("DWLD file_path : downloads file_path from server")
	print("CD dir_name : changes directory to dir_name")
	print("QUIT : Exit")

HOST = "127.0.0.1"
PORT = 2121



print("# connecting to server")
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((HOST,PORT))
print("# connected")


printCommands()
while True:
	command=input("\n>> Enter a command: ")
	if command == "help" or command == "HELP":
		printCommands()
		continue
	if command == "QUIT" or command == "quit":
		clientSocket.send("CLOSE".encode())
		break
	if command == "pwd" or command == "PWD":
		clientSocket.send("PWD".encode())
		wrkDir = clientSocket.recv(512).decode()
		print(wrkDir)
		continue
	if command.split(' ')[0] == "cd" or command.split(' ')[0] == "CD":
		clientSocket.send(command.encode())
		response = clientSocket.recv(1024).decode()
		print(response)
		continue
	if command == "LIST" or command == "list":
		clientSocket.send("LIST".encode())
		response = clientSocket.recv(1024).decode()
		print(response)
		continue
	if command.split(' ')[0] == "dwld" or command.split(' ')[0] == "DWLD":
		clientSocket.send(command.encode())
		response = clientSocket.recv(1024).decode()
		if response == "## bad request" or response == "## DWLD command must contain a path":
			print(response)
			continue
		port = int(response)
		dataChannel = socket(AF_INET,SOCK_STREAM)
		dataChannel.connect((HOST,port))
		fileName = os.path.split(command[5:])[1]
		file = open(fileName, "wb")
		data = dataChannel.recv(1024)
		while (data):
			print("## Receiving data")
			file.write(data)
			data = dataChannel.recv(1024)
		file.close()
		dataChannel.close()
		print("File Received:",fileName)
		continue
		
	
	print("## Unknown command")


print("# closing connection")
clientSocket.close()