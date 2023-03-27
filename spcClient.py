# -*- coding: utf-8 -*-
"""
spcClient
Simple Python Chat Client
Codey Sivley
for CS415 Operating Systems
Dr. Lewis

original code sourced from: https://www.geeksforgeeks.org/simple-chat-room-using-python/
then modified for python3 and assignment requirements
"""

# Python program to implement client side of chat room.
import socket
import select
import sys
import threading
 
server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
if len(sys.argv) != 3:
    print ("Correct usage: script, IP address, port number")
    exit()
IP_address = str(sys.argv[1])
Port = int(sys.argv[2])
server.connect((IP_address, Port))

def recieveMsg(ioMutex):
    ioMutex.acquire()
    message = server.recv(2048)
    print(str(message))
    ioMutex.release()
    
def sendMsg(ioMutex):
    ioMutex.acquire()
    message = sys.stdin.readline()
    server.send(message)
    sys.stdout.write("<You>")
    sys.stdout.write(message)
    sys.stdout.flush()
    ioMutex.release()
    
while True:
 
    # maintains a list of possible input streams
    sockets_list = [socket.socket(), server]
 
    """ There are two possible input situations. Either the
    user wants to give manual input to send to other people,
    or the server is sending a message to be printed on the
    screen. Select returns from sockets_list, the stream that
    is reader for input. So for example, if the server wants
    to send a message, then the if condition will hold true
    below.If the user wants to send a message, the else
    condition will evaluate as true"""
    read_sockets,write_socket, error_socket = select.select(sockets_list,[],[])
 
    ioMutex = threading.Lock()
    recieveThread = threading.Thread(target=recieveMsg, args=((ioMutex)))
    sendThread = threading.Thread(target=sendMsg, args=((ioMutex)))
    
    recieveThread.start()
    sendThread.start()
    """
    for socks in read_sockets:
        if socks == server:
            message = socks.recv(2048)
            print (str(message))
        else:
            message = sys.stdin.readline()
            message = input(">")
            server.send(message)
            sys.stdout.write("<You>")
"""
            
server.close()

