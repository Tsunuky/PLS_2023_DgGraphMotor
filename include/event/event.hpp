#pragma once

#define BIT(x) (1 << x)

#include <string>

namespace dg {

enum class evenType {
    none = 0,
    windowClose, windowResize, windowFocus, windowLostFocus, windowMoved, windowId,
    appTick, appUpdate, appRender,
    KeyPressed, keyReleased, KeySpePressed, KeySpeReleased,
    mouseButtonPressed, mouseButtonReleased, mouseMoved, mouseMovedClick, mouseScrolled,
};

enum eventCategory {
    none = 0,
    eventCategoryApplication    = BIT(0),
    eventCategoryInput          = BIT(1),
    eventCategoryKeyboard       = BIT(2),
    eventCategoryMouse          = BIT(3),
    eventCategoryMouseButton    = BIT(4),
};

#define EVENT_CLASS_TYPE(type) static evenType getStaticType() {return evenType::type;} \
                               virtual evenType getEvenType() const override {return getStaticType();} \
                               virtual const char *getName() const override {return #type;}


#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlag() const override {return category;}


class event {
    friend class eventDispatcher;
public:
    virtual evenType getEvenType()  const = 0;
    virtual const char *getName()   const = 0;
    virtual int getCategoryFlag()   const = 0;
    virtual std::string toString()  const {return getName();};
public:
    inline bool isInCategory(eventCategory category) {
        return getCategoryFlag() & category;
    }
public:
    bool handled = false;
};

class eventDispatcher {
public:
    eventDispatcher(event &event): _event(event) {}
public:
	template<typename T, typename F>
	bool Dispatch(const F& func) {
		if (_event.getEvenType() == T::getStaticType()) {
			_event.handled |= func(static_cast<T&>(_event));
			return true;
		}
		return false;
	}
private:
    event &_event;
};

inline std::ostream &operator <<(std::ostream &os, const event &e) {
    return os << e.toString();
}

}