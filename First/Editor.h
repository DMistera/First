#pragma once
#include "State.h"
#include "EditorUI.h"
#include "EditorMap.h"

class Editor : public State {
public:
	Editor();
	~Editor();
	bool init(Vector2i* mousePos);
	virtual bool update(int deltaTime);
private:
	EditorUI m_editorUI;
	EditorMap m_editorMap;
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;

};

