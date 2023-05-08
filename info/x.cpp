#include <iostream>
#include <string>

namespace Logo {
    class ConsoleLogo {
    public:
        static constexpr int logo_line_lenght = 32;
        static const std::string logo[17];
    };

    const std::string ConsoleLogo::logo[17] =
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
}

int main() {
    for (const auto& line : Logo::ConsoleLogo::logo) {
        std::cout << line << std::endl;
    }
    return 0;
}
