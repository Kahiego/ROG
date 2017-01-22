#ifndef INCLUDED_ENTITY_HH
#define INCLUDED_ENTITY_HH

#if 0

using Entity = unsigned int;

class Component
{
public:

    void update(World&) = 0;
};

class ComponentLocation: public Component
{
    sf::Vector2f position;

public:

    void update(World& w)
    {
        
    }
};

class ComponentTexture: public Component
{
    sf::Texture texture;

public:

    void update(World& w)
    {
        
    }
};

#endif

#endif
