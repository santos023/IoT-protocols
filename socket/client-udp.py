#!usr/bin/python

import socket

socketObject = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)      # For UDP

UDP_HOST = socket.gethostname()			# Host IP
UDP_PORT = 12345			        # specified port to connect

print "UDP target IP:", UDP_HOST
print "UDP target Port:", UDP_PORT

while True:
    msg = raw_input("Enter a message : ")
    socketObject.sendto(msg, (UDP_HOST, UDP_PORT))		# Sending message to UDP server
