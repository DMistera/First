#pragma once
#include "State.h"
#include "SFML/System/Vector2.hpp"
#include "Block.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "MapObject.h"
#include <vector>
#include "Map.h"

using namespace sf;

class EditorUI :
	public State {
public:
	EditorUI();
	~EditorUI();

	bool init(Vector2i* mousePos);

	bool update(int deltaTime, bool& saveCommand);
	MapObject* getSelectedTemplate();
protected:
	virtual void draw(RenderTarget& target, RenderStates states) const override;
private:
	unsigned int m_iconSize;
	unsigned int m_layoutWidth;
	Vector2i* m_mousePos;
	RectangleShape m_templateLayout;
	MapObject* m_selectedTemplate;
	vector<MapObject*> m_templates;
	MapObject* getTemplateFromCursor();

	bool m_saveButtonPressed;
};

