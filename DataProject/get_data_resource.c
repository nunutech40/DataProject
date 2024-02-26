//
//  get_data_resource.c
//  DataProject
//
//  Created by Nunu Nugraha on 22/02/24.
//

#include <stdio.h>
#include <sys/sysctl.h>
#include <sys/types.h>

void printNumberProcessor(void) {
    int nprocs;
    size_t length = sizeof(nprocs);
    sysctlbyname("hw.ncpu", &nprocs, &length, NULL, 0);
    printf("Number of processor: %d\n", nprocs);
}

void printPsyichalMemorySize(void) {
    int64_t physical_memory;
    size_t length = sizeof(physical_memory);
    sysctlbyname("hw.memsize", &physical_memory, &length, NULL, 0);
    printf("Physical memory size: %lld bytes\n", physical_memory);
}

void printSystemVersion(void) {
    char versionStr[256];
    size_t length = sizeof(versionStr);
    sysctlbyname("kern.osrelease", &versionStr, &length, NULL, 0);
    printf("System version: %s\n", versionStr);
}

int main(int argc, const char *argv[]) {
    printNumberProcessor();
    printPsyichalMemorySize();
    printSystemVersion();
    
    return 0;
}
