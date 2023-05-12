#pragma once

#include <input.hpp>


namespace dg {

class linuxInput : public input {
protected:
    virtual bool isKeyPressImpl(int keycode) override;
    virtual bool isButtonPressImpl(int button) override;
    virtual bool whileKeyPressImpl(int button) override;
    virtual bool whileButtonPressImpl(int button) override;

    virtual std::pair<int, int> getMousePosImpl() override;
    virtual int getMouseXImpl() override;
    virtual int getMouseYImpl() override;
};

}