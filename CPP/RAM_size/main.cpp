#include <windows.h>

int GET_MEM_SIZE_PHYS()
{ 
 MEMORYSTATUS* memory_status = (MEMORYSTATUS*)malloc(sizeof(MEMORYSTATUS)); 
 memory_status->dwLength = sizeof(MEMORYSTATUS);
 GlobalMemoryStatus(memory_status);

 MEMORYSTATUS var = *memory_status;

 return var.dwTotalPhys;
}