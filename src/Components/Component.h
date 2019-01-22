/*
* @author PELLETIER Benoit
*
* @file Component.h
*
* @date 16/01/2019
*
* @brief Define a component that modify a signal
*
*/

#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <iostream>
#include <vector>
#include "SFML/System.hpp"

using namespace std;


class ComponentInput;

class Component
{
	friend ComponentInput;

protected:
	vector<ComponentInput> m_inputs;
	string m_name;

public:
	Component();
	virtual ~Component();

	virtual float getOutput(float _time) = 0;

	ComponentInput* getInput(int _index);
	ComponentInput* getInput(string _name);

	string getName() { return m_name; }

private:
	bool _hasAlreadyInput(Component* _comp);
};

class ComponentInput
{
	friend Component;

private:
	Component* m_pParent = nullptr;
	Component* m_pComponent = nullptr;
	float m_defaultValue;
	string m_name;

public:
	ComponentInput(string _name, Component* _parent = nullptr);

	void setComponent(Component* _comp);
	void setDefaultValue(float _value) { m_defaultValue = _value; }
	string getName() { return m_name; }
	float getValue(float _time);
};

#endif // _COMPONENT_H