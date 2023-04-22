#include <iostream>
#include <Windows.h>
#include <string>

int main()
{
    std::string hwid;

    // Get the processor information
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    hwid += "Processor: ";
    hwid += std::to_string(sysInfo.dwProcessorType);
    hwid += "-"; // Add a separator

    // Get the memory information
    MEMORYSTATUSEX memStatus;
    memStatus.dwLength = sizeof(memStatus);
    GlobalMemoryStatusEx(&memStatus);
    hwid += "Memory: ";
    hwid += std::to_string(memStatus.ullTotalPhys);
    hwid += "-"; // Add a separator

    // Get the hard disk information
    ULARGE_INTEGER freeBytesAvailable, totalNumberOfBytes, totalNumberOfFreeBytes;
    GetDiskFreeSpaceEx(NULL, &freeBytesAvailable, &totalNumberOfBytes, &totalNumberOfFreeBytes);
    hwid += "Hard Disk: ";
    hwid += std::to_string(totalNumberOfBytes.QuadPart);
    hwid += "-"; // Add a separator

    // Print the HWID
    std::cout << "HWID: " << hwid << std::endl;

    return 0;
}
