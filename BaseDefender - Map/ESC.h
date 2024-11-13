#pragma once

#include<iostream>
#include<vector>
#include<algorithm>
#include<memory>
#include<bitset>
#include<array>

class Componet{};
class Entity{};

using ComponentID = std::size_t;
inline ComponentID getComponentID() {
    static ComponentID lastID = 0;
    return lastID++;
}
template <typename T> inline ComponentID getComponentID() noexcept {
    static ComponentID typeID = getComponentID();
    return typeID();
}
constexpr std::size_t maxComponent = 32;
using ComponentBitSet = std::bitset<maxComponent>;
using ComponentArray = std::array<Component*, maxComponent>;
class Component {
private:
public:
    Entity* entity;
    virtual void init() {};
    virtual void update() {};
    virtual void draw() {};

    virtual ~Component() {};
};
class Entity {
public:
    void update() {
        for (auto& c : components) c->update();
        for (auto& c : components) c->draw();
        
    }
    void draw() {}
    bool isActive() const { return active; }
    void destroy() { active = false; }
    template <typename T> bool hasComponent() const
    {
        return ComponentBitSet[getComponentID<T>];
    }
    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&...mArgs) {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{ c };
        component.emplace_back(std::move(uPtr));
        componentArray[getComponentTypeID<T>];
    }

    ;
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitSet componentBitSet;
};