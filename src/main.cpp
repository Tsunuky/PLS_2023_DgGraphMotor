#include <sandbox.hpp>

int main(int argc, char **argv) {
    application *app = createApplication();

    app->run(argc, argv, true);
    return 0;
}

/*#include <application.hpp>

int main(int argc, char **argv) {
    application doggo;

    dg::log::init();
    doggo.run(argc, argv, true);
    return 0;
}*/



/*

#include <application.hpp>

int main(int argc, char **argv) {
    application doggo;
    char test[10];
    int leo = 17;

    test[0] = 'c';
    test[1] = 'h';
    test[2] = 'a';
    test[3] = 'r';
    dg::log::init();
    DG_CORE_WARN("initial log! ptr={0}", fmt::ptr(test));
    DG_CORE_TRACE("initial log! ptr={0}", test);
    DG_INFO("hello! var={0}", leo);
    doggo.run(argc, argv);
    return 0;
}

*/

/*

#include "window.hpp"

int main(int argc, char **argv) {
    dg::window window; //can chnge name and size of width and height
    
    window.setOrtho();
    window.start(argc, argv, false);
    return 0;
}
*/