#!usr/bin/python

import socket

MAX_BUFFER_LEN=1024

socketObject = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)      # For UDP

UDP_HOST = socket.gethostname()		          	# Host IP
UDP_PORT = 12345			                # specified port to connect

socketObject.bind((UDP_HOST, UDP_PORT))

while True:
	print "Waiting for client..."
	data,addr = socketObject.recvfrom(MAX_BUFFER_LEN)	        #receive data from client
	print "\r\nReceived Messages:", data, "\r\nFrom", addr, "\r\n"
