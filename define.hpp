#ifndef DEFINE_HPP
# define DEFINE_HPP

# include <stdexcept>

# define delete { throw std::runtime_error("deleted function"); }

#endif
