#pragma once
#ifndef ES_CORE_COMPONENTS_BUSY_COMPONENT_H
#define ES_CORE_COMPONENTS_BUSY_COMPONENT_H

#include "components/ComponentGrid.h"
#include "components/NinePatchComponent.h"
#include "GuiComponent.h"
#include <SDL_mutex.h>

class AnimatedImageComponent;
class TextComponent;

class BusyComponent : public GuiComponent
{
public:
	BusyComponent(Window* window);
	~BusyComponent();
  
	void onSizeChanged() override;
	void setText(std::string txt);

	void reset(); // reset to frame 0
	virtual void render(const Transform4x4f& parentTrans);
private:
	NinePatchComponent mBackground;
	ComponentGrid mGrid;

	std::shared_ptr<AnimatedImageComponent> mAnimation;
	std::shared_ptr<TextComponent> mText;

	SDL_mutex *mutex;
	bool threadMessagechanged;
	std::string threadMessage;
};

#endif // ES_CORE_COMPONENTS_BUSY_COMPONENT_H
