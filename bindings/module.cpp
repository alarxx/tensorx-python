#include <pybind11/pybind11.h>
namespace py = pybind11;

#include <iostream>

#include "TensorX/Tensor.hpp"   // путь поправь под свой include

int add_ints(int a, int b){
    return a + b;
}

PYBIND11_MODULE(_tensorx, m) {
    m.doc() = "TensorX Python bindings";
    m.def("add_ints", &add_ints, "A test function");

    m.def("make_tensor", []() {
        tensor::Tensor<float> t(2, 3);   // использует шаблон + ctor
        std::cout << t << std::endl;
        return t.getRank();
    });
}
