#include "window.hpp"

int main(int argc, char **argv) {
    dg::window window; //cna chnge name and size of width and height
    
    window.setOrtho();
    window.start(argc, argv, false);
    return 0;
}