/**
 * RCOS-EasyContact
 * EasyContact/Backend/include/EasyContact
 * ColorfulOutput.hpp
 * Copyright [2013] <Joel Sjögren>
 */
#ifndef BACKEND_INCLUDE_EASYCONTACT_COLORFULOUTPUT_HPP_
#define BACKEND_INCLUDE_EASYCONTACT_COLORFULOUTPUT_HPP_
// C++ Standard Library
#include <ostream>
namespace COLOR {
enum VALUE {
  FG_RED = 31,
  FG_GREEN = 32,
  FG_BLUE = 34,
  FG_DEFAULT = 39,
  BG_RED = 41,
  BG_GREEN = 42,
  BG_BLUE = 44,
  BG_DEFAULT = 49
};
class Modifier {
 private:
  VALUE __CODE;

 public:
  Modifier(const VALUE& INPUT) : __CODE(INPUT) {}
  friend std::ostream& operator<<(std::ostream& FILE,
                                  const Modifier& INSTANCE) {
    return FILE << "\033[" << INSTANCE.__CODE << "m";
  }
};
}  // namespace COLOR
#endif  // BACKEND_INCLUDE_EASYCONTACT_COLORFULOUTPUT_HPP_
