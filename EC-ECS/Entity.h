#pragma once
#include <vector>
#include "Component.h"

class Entity
{
public:
	Entity() { m_id = ++ID; };
	virtual ~Entity();

	int GetID() { return m_id; };
	
	template <typename T, typename... Args>
	T* AddComoponent(Args&&... args) {
		Component* pComponent = new T(std::forward<Args>(args)...);
		m_components.push_back(pComponent);
		return (T*)pComponent;
	};

	template <typename T>
	T* GetComponent() {
		for (auto& component : m_components)
		{
			if (T::m_type == component->GetType())
			{
				return reinterpret_cast<T*>(component);
			}
		}
		return nullptr;
	};

	std::vector<Component*> GetAllComponents() { return m_components; };

	template <typename T>
	T* RemoveComponent() {
		for (auto& component : m_components)
		{
			if (T::m_type == component->GetType())
			{
				m_components.erase(component);
				return reinterpret_cast<T*>(component);
			}
		}
		return nullptr;
	};

	void ClearComponents() { m_components.clear(); };

private:
	int m_id;
	std::vector<Component*> m_components;

protected:
	static int ID;
};

int Entity::ID = 0;
