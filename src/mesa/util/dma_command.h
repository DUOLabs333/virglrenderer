#include <stdio.h>
#ifdef __cplusplus
extern "C" {
#endif
struct buffer;
typedef struct buffer* dma_command;
dma_command command_init(int capacity);
int command_read(void* ptr, char* buf, int nbytes);
int command_write(void* ptr, const char* buf, int nbytes);
fpos_t command_seek(void* ptr,off_t offset, int whence);
int command_close(void* ptr);

#ifdef __cplusplus
}
#endif