#pragma once

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/spdlog.h>
#include <memory>

namespace dg {

class log {
public:
    log() {};
    ~log() = default;
public:
    static void init();
    inline static std::shared_ptr<spdlog::logger> &getCoreLogger() {return _coreLogger;}
    inline static std::shared_ptr<spdlog::logger> &getClientLogger() {return _clientLogger;}
private:
    static std::shared_ptr<spdlog::logger> _coreLogger;
    static std::shared_ptr<spdlog::logger> _clientLogger;
};

}

//core log macro
#define DG_CORE_FATAL(...)   dg::log::getCoreLogger()->critical(__VA_ARGS__)
#define DG_CORE_ERROR(...)   dg::log::getCoreLogger()->error(__VA_ARGS__)
#define DG_CORE_TRACE(...)   dg::log::getCoreLogger()->trace(__VA_ARGS__)
#define DG_CORE_WARN(...)    dg::log::getCoreLogger()->warn(__VA_ARGS__)
#define DG_CORE_INFO(...)    dg::log::getCoreLogger()->info(__VA_ARGS__)

//client log macro
#define DG_FATAL(...)        dg::log::getClientLogger()->critical(__VA_ARGS__)
#define DG_ERROR(...)        dg::log::getClientLogger()->error(__VA_ARGS__)
#define DG_TRACE(...)        dg::log::getClientLogger()->trace(__VA_ARGS__)
#define DG_WARN(...)         dg::log::getClientLogger()->warn(__VA_ARGS__)
#define DG_INFO(...)         dg::log::getClientLogger()->info(__VA_ARGS__)