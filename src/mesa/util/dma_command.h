#ifdef __cplusplus
extern "C" {
#endif
typedef struct {
   IODMACommand* command;
   int offset;
   bool prepared;
} dma_command;

dma_command *command_init();
void command_prepare(dma_command* command, int offset);
void command_read(dma_command* command, void* buf, size_t nbytes);
void command_write(dma_command* command, void* buf, size_t nbytes);
void command_seek(dma_command* command,off_t offset, int whence);

#ifdef __cplusplus
}
#endif