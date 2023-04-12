#pragma once

#include <event.hpp>

namespace dg {

class AppTickEvent : public event {
public:
	AppTickEvent() = default;
	EVENT_CLASS_TYPE(appTick)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
};
class AppUpdateEvent : public event {
public:
	AppUpdateEvent() = default;
	EVENT_CLASS_TYPE(appUpdate)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
};
class AppRenderEvent : public event {
public:
	AppRenderEvent() = default;
	EVENT_CLASS_TYPE(appRender)
	EVENT_CLASS_CATEGORY(eventCategoryApplication)
};
}