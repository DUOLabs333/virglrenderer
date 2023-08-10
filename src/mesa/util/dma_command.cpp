#include <DriverKit/IOBufferMemoryDescriptor.h>
#include "dma_command.h"
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <string.h>

struct buffer {
   IOBufferMemoryDescriptor* buffer;
   void* start;
   void* end;
   void* cur;
};

extern "C" {
	dma_command command_init(int capacity){
		if (capacity<0){
			capacity=(int)pow(10,5);
		}
      dma_command command = new buffer;
      kern_return_t test;
       test=IOBufferMemoryDescriptor::Create(kIOMemoryDirectionInOut,capacity,0,&command->buffer);
       fprintf(stderr,"Return code: %d\n",test);
       fprintf(stderr,"Return code: %d\n", kIOReturnNotReady);
      IOAddressSegment range = {};
      fprintf(stderr, "1\n");
      command->buffer->GetAddressRange(&range);
      fprintf(stderr, "1\n");
      command->start=(void*)range.address;
      fprintf(stderr,"1\n");
      command->end=(void *)((uint64_t)(command->start)+range.length);
      fprintf(stderr, "1\n");

      return command;
   }
   
   int command_read(void* ptr, char* buf, int nbytes){
   		dma_command command=(dma_command)ptr;
   		nbytes=std::min((uint64_t)nbytes,(uint64_t)(command->end)-(uint64_t)(command->end));
      	memcpy(buf,command->cur,nbytes);
      	command_seek(command,nbytes,SEEK_CUR);
      	return nbytes;
   }

   int command_write(void* ptr, const char* buf, int nbytes){
   		dma_command command=(dma_command)ptr;
   	  nbytes=std::min(nbytes,(int)(sizeof(char)*strlen(buf)));
   	  memcpy(command->cur,buf,nbytes);
      command_seek(command,nbytes,SEEK_CUR);
      return nbytes;
   }
   fpos_t command_seek(void* ptr,off_t offset, int whence){
   	dma_command command=(dma_command)ptr;
      if (whence==SEEK_CUR){
         command->cur=(void*)((uint64_t)(command->cur)+offset);
      }else if (whence==SEEK_END){
         command->cur=(void*)((uint64_t)(command->end)+offset);
  	  }else if (whence==SEEK_SET){
  	  	command->cur=(void*)((uint64_t)(command->start)+offset);
  	  }
  	  return (uint64_t)command->cur;
  	}
  int command_close(void* ptr){
  		dma_command command=(dma_command)ptr;
  		command_seek(command,0,SEEK_SET);
  		return 0;
  }
}