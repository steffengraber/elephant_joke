#include <pybind11/pybind11.h>

std::string elephant_joke() {
    return "Warum tragen Elefanten keine Turnschuhe? - Weil sie sonst die ganze Savanne auslaufen!";
}

PYBIND11_MODULE(_elephant_joke, m) {
    m.def("elephant_joke", &elephant_joke, "Returns a funny elephant joke");
}
