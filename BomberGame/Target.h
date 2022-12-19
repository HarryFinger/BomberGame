#pragma once

#include "VisibleObject.h"

class Target : public VisibleObject
{
  public:
    enum class Type
    {
        GREEN,
        YELLOW,
        RED
    };

  public:
    Target(const sf::Texture &texture, Type type, const sf::Vector2f &for_vec, const sf::Vector2f &position);
    void update(float delta_time);

    void setForwardVector(const sf::Vector2f &for_vec)
    {
        forward_vector = for_vec;
    };

    float getRadius() const
    {
        return radius;
    }

    bool IsDead();
    void DealingDamage();

  private:
    const Type type_ = Type::GREEN;
    sf::Vector2f forward_vector;

    float radius;
    float speed = 0.0f;
    int32_t hit_points = 100;
};
