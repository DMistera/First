#include "EditorMap.h"
#include <iostream>


EditorMap::EditorMap()
{
}


EditorMap::~EditorMap()
{
}

bool EditorMap::init(Vector2i* mousePos, Map& map)
{
	m_mousePos = mousePos;
	m_map = &map;
	m_selectionHighlight.setSize(Vector2f((float)Map::BLOCK_SIZE, (float)Map::BLOCK_SIZE));
	return true;
}

bool EditorMap::update(int deltaTime, MapObject* selectedTemplate)
{
	Vector2f mousePos = convertFromCursor(*m_mousePos);

	if (selectedTemplate != nullptr)
	{
		selectedTemplate->getFrame().setFixedSize(Vector2f((float)Map::BLOCK_SIZE, (float)Map::BLOCK_SIZE));
	}

	//Highlight
	float x = float(mousePos.x - (int)mousePos.x % Map::BLOCK_SIZE);
	float y = float(mousePos.y - (int)mousePos.y % Map::BLOCK_SIZE);
	m_selectionHighlight.setPosition(Vector2f(x, y));

	//Insert
	if (Mouse::isButtonPressed(Mouse::Left))
	{
		if (selectedTemplate != nullptr)
		{
			bool add = true;
			for (MapObject* mapObject : m_map->getMapObjects())
			{
				if (mapObject->getFrame().getPosition() == Vector2f(x, y))
				{
					add = false;
				}
			}
			if (add)
			{
				MapObject* o = (MapObject*)selectedTemplate->copy();
				o->getFrame().setPosition(Vector2f(x, y));
				o->setMapPosition(Vector2i((int)x / Map::BLOCK_SIZE, (int)y / Map::BLOCK_SIZE));
				m_map->addObject(o);
			}
		}
	}

	//Delete
	if (Mouse::isButtonPressed(Mouse::Right))
	{
		for (MapObject* mapObject : m_map->getMapObjects())
		{
			if (mapObject->getFrame().getPosition() == Vector2f(x, y))
			{
				m_map->remove(mapObject);
				delete mapObject;
			}
		}
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_view.move(Vector2f(1.0f * (float)deltaTime, 0.0f));
	}
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_view.move(Vector2f(-1.0f * (float)deltaTime, 0.0f));
	}

	return true;
}

Map* EditorMap::getMap()
{
	return m_map;
}

void EditorMap::draw(RenderTarget& target, RenderStates states) const
{
	State::draw(target, states);
	target.draw(*m_map);
	target.draw(m_selectionHighlight);
}

Vector2i EditorMap::getBlock(Vector2i point)
{
	int x = point.x / Map::BLOCK_SIZE;
	int y = point.y / Map::BLOCK_SIZE;
	return Vector2i(x, y);
}
