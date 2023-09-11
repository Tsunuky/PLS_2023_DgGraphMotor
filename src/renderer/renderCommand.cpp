#include <renderer/renderCommand.hpp>
#include <OpenGL/OpenGLRendererAPI.hpp>

namespace dg {

rendererAPI *renderCommand::_rendererAPI = new OpenGLRendererAPI;


}