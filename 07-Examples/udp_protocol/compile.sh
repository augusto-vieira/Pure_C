#!/bin/bash

gcc -g -I. UDPServer.c -o UDPServer 
gcc -g UDPClient.c -o UDPClient
