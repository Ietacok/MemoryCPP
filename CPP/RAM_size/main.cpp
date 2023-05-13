#include <iostream>
#include <windows.h>

int main()
{ 
 MEMORYSTATUS* memory_status = (MEMORYSTATUS*)malloc(sizeof(MEMORYSTATUS)); 
 memory_status->dwLength = sizeof(MEMORYSTATUS);
 GlobalMemoryStatus(memory_status);

 MEMORYSTATUS var = *memory_status;
 
 std::cout << var.dwTotalPhys; 

 return 0;
}