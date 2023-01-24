#include "window.hpp"
#include "texture.hpp"

int main(int argc, char **argv) {
    dg::window window; //can chnge name and size of width and height
    dg::texture texture("./asset/bunny.png");
    
    texture.bind();
    window.setOrtho();
    window.start(argc, argv, false);
    return 0;
}