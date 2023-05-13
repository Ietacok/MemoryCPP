#include <iostream>
#include <windows.h>

int main()
{ 
 MEMORYSTATUS* memory_status = (MEMORYSTATUS*)malloc(sizeof(MEMORYSTATUS)); 
 memory_status->dwLength = sizeof(MEMORYSTATUS);
 GlobalMemoryStatus(memory_status);

 MEMORYSTATUS var = *memory_status;

 int * n_ptr = 0x0;
 
 std::cout << n_ptr[0]; 

 return 0;
}