#pragma once

class Entity;
class Component
{
public:
	enum class ComponentType
	{
		BASE,
		TRANSFORM,
		MESH,
		STATS
	};

	Component() = default;
	Component(Entity* pEntity) : m_pEntity(pEntity) {};
	virtual ~Component() = 0;

	void SetEntity(Entity* pEntity) { m_pEntity = pEntity; };

	virtual ComponentType GetType() = 0;
	static const ComponentType m_type = ComponentType::BASE;

protected:
	Entity* m_pEntity = nullptr;
};


class Transform : public Component
{
public:
	Transform() { mx = my = mz = 0.0f; };
	Transform(Entity* pEntity, float x, float y, float z) : mx(x), my(y), mz(z) { m_pEntity = pEntity; };
	ComponentType GetType() override { return m_type; };

	float mx, my, mz;
	static const ComponentType m_type = ComponentType::TRANSFORM;
};


class Mesh : public Component
{
public:
	Mesh();
	Mesh(Entity* pEntity) { m_pEntity = pEntity; };
	ComponentType GetType() override { return m_type; };

	static const ComponentType m_type = ComponentType::MESH;
};


class Stats : public Component
{
public:
	Stats() : m_attack(0), m_health(0), m_defense(0), m_speed(0) {};
	Stats(Entity* pEntity, float attack = 0, float health = 0, float defense = 0, float speed = 0) : m_attack(attack), m_health(health), m_defense(defense), m_speed(speed) { m_pEntity = pEntity; };
	ComponentType GetType() override { return m_type; };

	float m_attack;
	float m_health;
	float m_defense;
	float m_speed;
	static const ComponentType m_type = ComponentType::STATS;
};
