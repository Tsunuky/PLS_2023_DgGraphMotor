#pragma once

namespace dg {

enum class renderAPI {
    none = 0,
    openGL = 1
};

class renderer {
public:
    inline static renderAPI getAPI() {return _rendererAPI;};
private:
    static renderAPI _rendererAPI;
};

}
