#include <iostream>
#include <utility>
#include <string>
#include <sys/sysctl.h>
#include <cstring>
#include <sys/types.h>
#include <sys/param.h>
#include <sys/mount.h>
#include <sys/resource.h>

// global vars
char buffer[1024];
size_t size = sizeof(buffer);

// function to get hostname
std::string hostname() {
    std::string host_name;

    if (sysctlbyname("kern.hostname", &buffer, &size, NULL, 0) == 0) {
        host_name = buffer;
    }

    // Find the first occurrence of the '.' character in the hostname
    size_t dot_pos = host_name.find('.');
    if (dot_pos != std::string::npos) {
        // If the '.' character is found, truncate the hostname at the '.' character
        host_name = host_name.substr(0, dot_pos);
    }

    return host_name;
}

// find os version
std::string osVersion() {
    std::string os_version;
    size = sizeof(buffer);
    if (sysctlbyname("kern.osrelease", &buffer, &size, NULL, 0) == 0) {
        os_version = buffer;
    }

    return os_version;
}

// find storage of the disk computer is using
std::pair<unsigned long long, unsigned long long> storage() {
    struct statfs fs_info;
    unsigned long long total_size, free_size;
    const char* path = "/System/Volumes/Data";  // path to the file system you want to check

    if (statfs(path, &fs_info) == 0) {
        total_size = static_cast<double>(fs_info.f_blocks * fs_info.f_bsize) / (1024*1024*1024);
        free_size = fs_info.f_bfree * fs_info.f_bsize / (1024*1024*1024);
    }
     
    else {
        throw std::runtime_error("Failed to check file system");
    }

    return std::make_pair(total_size, free_size);
}

// print out logo and information
void logo(std::string os_version, std::string hostname, unsigned long long total_size, unsigned long long free_size) {
    const std::string logo[17] =
    {
        "\x1b[38;5;76;1m                    'c.        ",
        "\x1b[38;5;76;1m                 ,xNMM.        ",
        "\x1b[38;5;76;1m               .OMMMMo         ",
        "\x1b[38;5;76;1m               OMMM0,          ",
        "\x1b[38;5;76;1m     .;loddo:' loolloddol;.    ",
        "\x1b[38;5;76;1m   cKMMMMMMMMMMNWMMMMMMMMMM0:  ",
        "\x1b[38;5;184;1m .KMMMMMMMMMMMMMMMMMMMMMMMWd.  ",
        "\x1b[38;5;184;1m XMMMMMMMMMMMMMMMMMMMMMMMX.    ",
        "\x1b[38;5;208;1m;MMMMMMMMMMMMMMMMMMMMMMMM:     ",
        "\x1b[38;5;208;1m:MMMMMMMMMMMMMMMMMMMMMMMM:     ",
        "\x1b[38;5;196;1m.MMMMMMMMMMMMMMMMMMMMMMMMX.    ",
        "\x1b[38;5;196;1m kMMMMMMMMMMMMMMMMMMMMMMMMWd.  ",
        "\x1b[38;5;129;1m .XMMMMMMMMMMMMMMMMMMMMMMMMMMk ",
        "\x1b[38;5;129;1m  .XMMMMMMMMMMMMMMMMMMMMMMMMK. ",
        "\x1b[38;5;45;1m    kMMMMMMMMMMMMMMMMMMMMMMd   ",
        "\x1b[38;5;45;1m     ;KMMMMMMMWXXWMMMMMMMk.    ",
        "\x1b[38;5;45;1m       .cooc,.    .,coo:.      "
    };

    std::cout << logo[0] << "\n";
    std::cout << logo[1] << "\n";
    std::cout << logo[3] << "\n";
    std::cout << logo[4] << "\n";
    std::cout << logo[5] << "\n";
    std::cout << logo[6] << "\n";
    std::cout << logo[7] << "Hostname: " << hostname << "\n";
    std::cout << logo[8] << "OS version: " << os_version << "\n";
    std::cout << logo[9] << "Memory Used: " << total_size - free_size << " GB" << "\n";
    std::cout << logo[10] << "Free Memory: " << free_size << " GB" << "\n";
    std::cout << logo[11] << "\n";
    std::cout << logo[12] << "\n";
    std::cout << logo[13] << "\n";
    std::cout << logo[14] << "\n";
    std::cout << logo[15] << "\n";
    std::cout << logo[16] << "\n";
}

// wrap it all together and call them all
int main() {
    std::pair<unsigned long long, unsigned long long> res = storage();
    logo(osVersion(), hostname(), res.first, res.second);

    return 0;
}