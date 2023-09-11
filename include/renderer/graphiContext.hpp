#pragma once

namespace dg {

class GraphiContext {
public:
	virtual ~GraphiContext() = default;
public:
    virtual void init() = 0;
    virtual void swapBuffer() = 0;
};

}