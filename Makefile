C_FILES = main.c ChatBot.c ChatMessage.c ChatRoom.c ChatUser.c cJSON.c Client.c Command.c RunningCommand.c -lcurl

all: compile


compile:
	gcc $(C_FILES) -lcurl  -lpthread -lm -o firealarm
