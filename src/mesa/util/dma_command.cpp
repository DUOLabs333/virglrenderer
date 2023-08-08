#include <IOKit/IODMACommand.h>
#include "dma_command.h"
#include <stdio.h>

extern "C" {
	dma_command *command_init(){
      dma_command *command = new dma_command;

      command->command=IODMACommand::withSpecification(kIODMACommandOutputBig32,32,0);
      command->prepared=false;
      command_prepare(command,0);
      return command;
   }
   void command_prepare(dma_command* command, int offset){
      if (command->prepared){
         command->command->complete();
      }

      command->command->prepare(offset);
      command->offset=offset;
      command->prepared=true;
   }
   void command_read(dma_command* command, void* buf, size_t nbytes){
      int bytes=command->command->readBytes(command->offset,buf,nbytes);
      command_prepare(command,command->offset+bytes);
   }

   void command_write(dma_command* command, void* buf, size_t nbytes){
      int bytes=command->command->writeBytes(command->offset,buf,nbytes);
      command_prepare(command,command->offset+bytes);
   }
   void command_seek(dma_command* command,off_t offset, int whence){
      if (whence==SEEK_CUR){
         offset+=command->offset;
      }else if (whence==SEEK_END){
         offset=command->offset; //Buffers have no end
      command_prepare(command,offset);
  	  }
  	}
}