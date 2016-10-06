//
//  misc_commands.h
//  chatbot
//
//  Created by NobodyNada on 5/9/16.
//  Copyright © 2016 NobodyNada. All rights reserved.
//

#ifndef misc_commands_h
#define misc_commands_h

void listCommands(RunningCommand *command, void *ctx) {
    ChatBot *bot = ctx;
    postReply(bot->room, "Running commands:", command->message);
    const size_t maxLineSize = 256;
    pthread_mutex_lock(&bot->runningCommandsLock);
    postMessage(bot->room, "@Ultron hw -> Hello World");
    pthread_mutex_unlock(&bot->runningCommandsLock);
}

char * append(char * string1, char * string2)
{
    char * result = NULL;
    asprintf(&result, "%s%s", string1, string2);
    return result;
}

void helloWorld (RunningCommand *command, void *ctx)
{
    ChatBot *bot = ctx;
    //char* username = append("@",command->message->user->name);
    //postMessage (bot->room, append(username," : Hello World!"));
    postReply (bot->room , "Hello World!" , command->message);
    return;
}

void pingUsers (RunningCommand *command, void *ctx)
{
    ChatBot *bot = ctx;
    if (command->argc < 2)
    {
        postReply (bot->room, "**Usage:** `@Ultron ping <username> <number>`", command->message);
        return;
    }
    
    char *username = command->argv [0];
    int num = strtol (command->argv [1], NULL, 10);
    char *str;
    
    for (unsigned i = 0; i < num; i ++)
    {
        //char *str;
        asprintf (&str, "@%s", username);
        postMessage (bot->room, str);
    }
    
    free (str);
    return;
}

#endif /* misc_commands_h */
