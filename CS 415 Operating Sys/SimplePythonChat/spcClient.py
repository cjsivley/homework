# Codey Sivley
# For CS415 Operating Systems
# Dr Lewis
import socket
import select
import sys

#global stuff for port connections
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

def commandInterpreter(cmd):
	#not sure how to do this other than an if tree?
	cmdParse = cmd.split()
	if cmdParse[0] == "CONNECT":
		try:
			server.connect((str(cmdParse[1]), int(cmdParse[2])))
		except:
			print("Connection failed. Please check address and try again.")
		
	elif cmdParse[0] == "MESSAGE":
		outgoing = " ".join(cmdParse[1:])
		server.send(cmd.encode()) #send the whole thing!
		sys.stdout.write("<You>")
		sys.stdout.write(outgoing + "\n")
		sys.stdout.flush()
		
	elif cmdParse[0] == "USERS":
		server.send("USERS".encode())
		
	elif cmdParse[0] == "DISCONNECT":
		server.send("DISCONNECT".encode()) #graceful disconnect
		
	elif cmdParse[0] == "HELP":
		print("Accepted commands:\n CONNECT [ip-address][port]\n MESSAGE [message]\n USERS\n DISCONNECT")
		
	else:
		print("Unrecognized command. Type \"HELP\" for help.")
###################### splash page ####################
print("Welcome to evilChat!")
commandInterpreter(sys.stdin.readline())

def chat():
	while True:
		# maintains a list of possible input streams
		sockets_list = [sys.stdin, server]
	
		read_sockets,write_socket, error_socket = select.select(sockets_list,[],[])
	
		for socks in read_sockets:
			if socks == server:
				message = socks.recv(2048)
				print (message.decode())
			else:
				message = sys.stdin.readline()
				commandInterpreter(message)
				sys.stdout.flush()
	server.close()
chat()

