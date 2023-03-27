# Python program to implement server side of chat room.
import socket
import select
import sys
import string

from _thread import *

"""The first argument AF_INET is the address domain of the
socket. This is used when we have an Internet Domain with
any two hosts The second argument is the type of socket.
SOCK_STREAM means that data or characters are read in
a continuous flow."""
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

if len(sys.argv) != 3:
	print ("Correct usage: script, IP address, port number")
	exit()

IP_address = str(sys.argv[1])
Port = int(sys.argv[2])
server.bind((IP_address, Port))
server.listen(100) #max connections

list_of_clients = [] #list of currently connected client objects

def clientthread(conn, addr):

	#successful connection greeting.
	conn.send(("You have entered the EVIL chatroom!").encode())

    #each client thread runs ad infinitum
	while True:
		try:
			message = conn.recv(2048)
		except:
			print("Message recieve error")
			conn.close()
			break #closes thread on server side, but client crashes
		else:
			if message:
				message = message.decode()
				messageParse = message.split()
                #message is parsed here for user commands.
				if messageParse[0] == "USERS":
                    #send only to requesting user
					userlist = str(list_of_clients)
					conn.send("USERS ONLINE\n".encode())
					for each in list_of_clients:
						conn.send(str(each.getpeername()).encode())
                        
				elif messageParse[0] == "DISCONNECT":
					print(str(conn) + " is disconnecting.")
					conn.send("Goodbye.".encode())
					remove(conn)
					conn.close()
                    break
				elif messageParse[0] == "MESSAGE":
					outgoing = " ".join(messageParse[1:])
					print ("<" + str(addr[1]) + "> " + outgoing)
					# Calls broadcast function to send message to all
					message_to_send = (str("<" + str(addr[1]) + "> " + outgoing + "\n"))
					broadcast(message_to_send.encode(), conn)
				else:
					print ("message not understood")
					print (message) #for debug mostly

"""Using the below function, we broadcast the message to all
clients who's object is not the same as the one sending
the message """
def broadcast(message, connection):
	print ("Broadcasting message: " + str(message))
	for clients in list_of_clients:
		if clients!=connection:
			try:
				clients.send(message)
			except:
				clients.close()

				# if the link is broken, we remove the client
				remove(clients)

def remove(connection):
	if connection in list_of_clients:
		list_of_clients.remove(connection)

print("Ready for clients.")
while True:

	"""Accepts a connection request and stores two parameters,
	conn which is a socket object for that user, and addr
	which contains the IP address of the client that just
	connected"""
	conn, addr = server.accept()

	"""Maintains a list of clients for ease of broadcasting
	a message to all available people in the chatroom"""
	list_of_clients.append(conn)

	# prints the address of the user that just connected
	print (str(addr[1]) + " connected")

	# creates and individual thread for every user
	# that connects
	start_new_thread(clientthread,(conn,addr))	

conn.close()
server.close()

