
# a bunch of MACROS
# followed by a bunch of RULES

# a MARCO
# <name> = <some strings>
# -- if the make saw $(name) in RULE or another MACRO,
# then it will replace it with <some strings> defines in the MACRO
# note: MACRO is useful because the programmer only needs to change one PLACE (if...).

# a RULE
# <Target>:<tab key><Dependence><space_key><Dependence>...
# <tab key><command Line>
# <tab key><command Line>
# <tab key><command Line>
# <one empty>

# ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
#	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

# target is ecs36b_JSON.o
# dependency #1 is ecs36b_JSON.cpp
# timestamps (of the last modification) of these two files:
#  ecs36b_JSON.o       (01/01/2023)
#  ecs36b_JSON.cpp     (01/02/2022)
# should I trigger the rule? (to compile ecs36b_JSON.cpp ==> ecs36b_JSON.o)

# dependency #2+
# INC     =       ecs36b_Common.h ecs36b_Exception.h
# ecs36b_Common.h
# ecs36b_Exception.h
# ecs36b_JSON.o:		ecs36b_JSON.cpp ecs36b_Common.h ecs36b_Exception.h
# if ANY of those three depenecncy files has a NEWER timestamp than  ecs36b_JSON.o,
# we need to trigger the command line!

# $ make <target>
# $ make      <-- fire the first rule

# Makefile for s2023, ecs36b
# https://macappstore.org/libjson-rpc-cpp/
# https://github.com/cinemast/libjson-rpc-cpp

CC = g++ -std=c++14
# CFLAGS = -g -Wall
CFLAGS = -O3

# LDFLAGS = 	-L/Users/sfwu/vcpkg/installed/arm64-osx/lib -ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

LDFLAGS = 	-ljsoncpp -L/opt/homebrew/lib/ -lmicrohttpd -ljsonrpccpp-common -ljsonrpccpp-server -ljsonrpccpp-client -lcurl

INC	=	ecs36b_Common.h ecs36b_Exception.h
INC_CL	=	Core.h GPS.h JvTime.h SP_Person.h Team.h Commutable.h Message.h
OBJ	=	Core.o GPS.o JvTime.o SP_Person.o Team.o Commutable.o Message.o

# rules.
all: 	mobility_server mobility_send mobility_dump

#
#
# <target> : [... tab...] <dependency>
# [... tab ....] <action>

mobility_client.h:		ecs36b_mobility.json
	jsonrpcstub ecs36b_mobility.json --cpp-server=mobility_Server --cpp-client=mobility_Client

mobility_server.h:		ecs36b_mobility.json
	jsonrpcstub ecs36b_mobility.json --cpp-server=mobility_Server --cpp-client=mobility_Client

mobility_send.o:		mobility_send.cpp mobility_client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) mobility_send.cpp

mobility_dump.o:		mobility_dump.cpp mobility_client.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) mobility_dump.cpp

mobility_server.o:		mobility_server.cpp mobility_server.h $(INC_CL) $(INC)
	$(CC) -c $(CFLAGS) mobility_server.cpp

ecs36b_JSON.o:		ecs36b_JSON.cpp $(INC)
	$(CC) -c $(CFLAGS) ecs36b_JSON.cpp

GPS.o:		GPS.cpp GPS.h $(INC)
	$(CC) -c $(CFLAGS) GPS.cpp

Core.o:		Core.cpp Core.h $(INC)
	$(CC) -c $(CFLAGS) Core.cpp

Message.o:		Message.cpp Message.h $(INC)
	$(CC) -c $(CFLAGS) Message.cpp

Commutable.o:		Commutable.cpp Commutable.h $(INC)
	$(CC) -c $(CFLAGS) Commutable.cpp

JvTime.o:	JvTime.cpp JvTime.h $(INC)
	$(CC) -c $(CFLAGS) JvTime.cpp

SP_Person.o:	SP_Person.cpp SP_Person.h $(INC)
	$(CC) -c $(CFLAGS) SP_Person.cpp

Team.o:	Team.cpp Team.h $(INC)
	$(CC) -c $(CFLAGS) Team.cpp

mobility_server:	mobility_server.o ecs36b_JSON.o $(OBJ)
	$(CC) -o mobility_server mobility_server.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

mobility_send:	mobility_send.o ecs36b_JSON.o $(OBJ)
	$(CC) -o mobility_send mobility_send.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

mobility_dump:	mobility_dump.o ecs36b_JSON.o $(OBJ)
	$(CC) -o mobility_dump mobility_dump.o ecs36b_JSON.o $(OBJ) $(LDFLAGS)

clean:
	rm -f *.o *~ core mobility_client.h mobility_server.h mobility_dump mobility_send mobility_server


