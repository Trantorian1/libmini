#ifndef COLOR_HPP
# define COLOR_HPP

# include <string>

namespace color {
	static const std::string RESET      = "\033[0m";
	static const std::string BOLD       = "\033[1m";
	static const std::string DIM        = "\033[2m";
	static const std::string ITALIC     = "\033[3m";
	static const std::string UNDERLINE  = "\033[4m";
	static const std::string BLINK      = "\033[5m";
	static const std::string REVERSE    = "\033[7m";
	static const std::string HIDDEN     = "\033[8m";

	static const std::string BLACK      = "\033[30m";
	static const std::string RED        = "\033[31m";
	static const std::string GREEN      = "\033[32m";
	static const std::string YELLOW     = "\033[33m";
	static const std::string BLUE       = "\033[34m";
	static const std::string MAGENTA    = "\033[35m";
	static const std::string CYAN       = "\033[36m";
	static const std::string WHITE      = "\033[37m";

	static const std::string BLACK_BG   = "\033[40m";
	static const std::string RED_BG     = "\033[41m";
	static const std::string GREEN_BG   = "\033[42m";
	static const std::string YELLOW_BG  = "\033[43m";
	static const std::string BLUE_BG    = "\033[44m";
	static const std::string MAGENTA_BG = "\033[45m";
	static const std::string CYAN_BG    = "\033[46m";
	static const std::string WHITE_BG   = "\033[47m";
}

#endif
