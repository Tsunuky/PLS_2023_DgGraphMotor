#pragma once

#include <event.hpp>

namespace dg {

class appTickEvent : public event {
public:
	appTickEvent() = default;
	EVENT_CLASS_TYPE(appTick)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
};
class appUpdateEvent : public event {
public:
	appUpdateEvent() = default;
	EVENT_CLASS_TYPE(appUpdate)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
};
class appRenderEvent : public event {
public:
	appRenderEvent() = default;
	EVENT_CLASS_TYPE(appRender)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
};
}