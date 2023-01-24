#pragma once

namespace dg {

class application {
public:
    application();
    virtual ~application();
public:
    application *createApplication();
public:
    void run();
private:
    /* data */
};

}