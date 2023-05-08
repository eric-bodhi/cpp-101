#include <iostream>
#include <string>
#include <sys/sysctl.h>
#include <cstring>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/mount.h>
#include <sys/resource.h>

int main() {
    // Get the hostname
    std::string hostname;
    char buffer[1024];
    size_t size = sizeof(buffer);
    struct statfs fs_info;
    unsigned long long total_size, free_size;
    const char* path = "/";  // path to the file system you want to check

    if (sysctlbyname("kern.hostname", &buffer, &size, NULL, 0) == 0) {
        hostname = buffer;
    }

    // Find the first occurrence of the '.' character in the hostname
    size_t dot_pos = hostname.find('.');
    if (dot_pos != std::string::npos) {
        // If the '.' character is found, truncate the hostname at the '.' character
        hostname = hostname.substr(0, dot_pos);
    }

    // Get the OS version
    std::string os_version;
    size = sizeof(buffer);
    if (sysctlbyname("kern.osrelease", &buffer, &size, NULL, 0) == 0) {
        os_version = buffer;
    }

    if (statfs(path, &fs_info) == 0) {
        total_size = fs_info.f_blocks * fs_info.f_bsize / (1024*1024*1024);
        free_size = fs_info.f_bfree * fs_info.f_bsize / (1024*1024*1024);
    }

    // Get the maximum resident set size
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    long maxrss = usage.ru_maxrss; // in kilobytes

    // Convert to gigabytes
    double gb = maxrss / (1024.0*1024.0);

    std::cout << "Hostname: " << hostname << std::endl;
    std::cout << "OS version: " << os_version << std::endl;
    std::cout << "Total disk space: " << total_size << " GB" << "\n";
    std::cout << "Free disk space: " << free_size << " GB" << "\n";
    std::cout << "Memory used: " << gb << " GB" << std::endl;

    return 0;
}