#pragma once

#include <renderer/renderCommand.hpp>

namespace dg {

class renderer {
public:
    static void beginScene();
    static void endScene();

    static void submit(const std::shared_ptr<vertexArray> &vertexArray);
public:
    inline static rendererAPI::API getAPI() {return rendererAPI::getAPI();};
};

}
