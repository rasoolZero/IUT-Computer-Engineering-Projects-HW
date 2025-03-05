from socket import *
import os
from random import *

seed()

os.chdir("files")
START_DIR = os.getcwd()
# print(START_DIR)
PORT = 2121
IP = "127.0.0.1"


def isSecure(dir):
	oldDir = os.getcwd()
	os.chdir(dir)
	newDir = os.getcwd()
	global START_DIR
	if START_DIR in newDir:
		os.chdir(oldDir)
		return True
	else:
		os.chdir(oldDir)
		return False
		
		

def get_size(start_path = '.'):
	total_size = 0
	for dirpath, dirnames, filenames in os.walk(start_path):
		for f in filenames:
			fp = os.path.join(dirpath, f)
			# skip if it is symbolic link
			if not os.path.islink(fp):
				total_size += os.path.getsize(fp)

	return total_size


print("# preparing and binding")
serverSocket = socket(AF_INET , SOCK_STREAM)
serverSocket.bind((IP,PORT))
serverSocket.listen(5)
print("# server bound and listening")

while True:
	print("# waiting for a connection")
	connection , addr = serverSocket.accept()
	print("# connection established",addr)
	os.chdir(START_DIR)
	while True:
		print("## waiting for a command")
		command = ""
		try:
			command = connection.recv(1024).decode()
		except ConnectionResetError:
			print("## connection closed by client")
			connection.close()
			break
	
		if command == "PWD":
			print("# sending working directory")
			wrkDir = os.getcwd().replace(START_DIR,"") + "\\"
			connection.send(wrkDir.encode())
		if command == "CLOSE":
			print("# closing connection")
			connection.close()
			break
			
			
		if command.split(' ')[0] == "cd" or command.split(' ')[0] == "CD":
			if len(command) < 4:
				connection.send("## CD command must contain an address".encode())
				continue
			newDir = command[3:]
			print("# changing directory :", newDir)
			try:
				if not isSecure(newDir):
					print("## access violation, client:",addr)
					connection.send("could not change the directory".encode())
				else:
					os.chdir(newDir)
					connection.send("directory changed".encode())
					print ("# directory changed")
			except (FileNotFoundError ,NotADirectoryError) as e:
				connection.send("Directory not found".encode())
				print ("## requested directory not found")
				
				
				
		if command == "LIST":
			print("# preparing list")
			totalBytes = 0
			response = ""
			with os.scandir(".") as it:
				for entry in it:
					size=0
					if entry.is_dir():
						response+=">"
						size = get_size(entry.name)
					else:
						size = entry.stat().st_size
					response+="  "+entry.name+" - "+str(size)+"B\n"
					totalBytes+=size
			response+=str(totalBytes)+"B"
			print("# sending list")
			connection.send(response.encode())
			
		if command.split(' ')[0] == "dwld" or command.split(' ')[0] == "DWLD":
			if len(command) < 6:
				connection.send("## DWLD command must contain a path".encode())
				continue
			print("# download request")
			fileName = command[5:]
			try:
				address = os.path.dirname(os.path.abspath(fileName))
				if not isSecure(address):
					print("## access violation, client:",addr)
					connection.send("## bad request".encode())
					continue
				if not os.path.isfile(fileName):
					print("## invalid path")
					connection.send("## bad request".encode())
					continue
			except:
				pass
			print("# preparing data channel")
			port = randint(3000,50000)
			dataChannel = socket(AF_INET, SOCK_STREAM)
			dataChannel.bind((IP,port))
			dataChannel.listen(5)
			connection.send(str(port).encode())
			print("# waiting for the client")
			dataConnection , addr = dataChannel.accept()
			print("# sending data")
			file = open(fileName , "rb")
			data=file.read()
			file.close()
			dataConnection.send(data)
			dataConnection.close()
			dataChannel.close()
			print("# data has been sent")
		
		
		
		
		
	
		
		
		
		
		
		