#include <log.hpp>

namespace dg {

std::shared_ptr<spdlog::logger> log::_coreLogger;
std::shared_ptr<spdlog::logger> log::_clientLogger;

void log::init() {
    spdlog::set_pattern("%^[%T] %n: %v%$");
    _coreLogger = spdlog::stdout_color_mt("DG_Core");
    _coreLogger->set_level(spdlog::level::trace);
    _clientLogger = spdlog::stdout_color_mt("APP");
    _clientLogger->set_level(spdlog::level::trace);
}

}