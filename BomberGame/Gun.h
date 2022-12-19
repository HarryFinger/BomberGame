#pragma once

#include "GameResourceManager.h"
#include "VisibleObject.h"

#include <SFML/Graphics.hpp>

#include <functional>
#include <list>

class Gun final : public sf::Drawable
{
public:
    Gun(const sf::Texture &cannon_texture, const sf::Texture &stand_texture, const sf::Texture &shield_texture);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
    void update(float delta_time);

    void UpdateAimPosition(const sf::Vector2f &pos)
    {
        aim_position = pos;
    };

    const sf::Vector2f &getForwardVercor() const
    {
        return forward_vector;
    }

    const sf::Vector2f &getPosition() const
    {
        return cannon.getPosition();
    }

    void TryToShoot();

    float getShieldRadius() const
    {
        return radius;
    }

    const sf::Vector2f &getShieldPosition() const
    {
        return shield.getPosition();
    }

    using CreateCannonballFunction = std::function<void()>;
    void setCreateCannonballFunction(CreateCannonballFunction create_cannonball_func);
    bool IsDead() const;
    void DealingDamage(int32_t damage);

private:
    void IndicateCooldown();

private:
    VisibleObject cannon;
    VisibleObject stand;
    VisibleObject shield;

    sf::Vector2f forward_vector;
    sf::Vector2f aim_position;
    sf::Color original_color;

    const float time_between_shots = 1.f;
    float cooldown = 0.f;

    int32_t shield_hp = 100;
    int32_t gun_hp = 10;
    float radius;

    float time_accumulator = 0.0f;
    float frequency = 7.0f;

    CreateCannonballFunction create_cannonball_function;
};
