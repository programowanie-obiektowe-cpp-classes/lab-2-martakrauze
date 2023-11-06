#pragma once

#include "Resource.hpp"

class ResourceManager
{
    // Twoja implementacja tutaj
public:
    ResourceManager()
    {
        w = new Resource();
    }
    ResourceManager(const ResourceManager& other)
    {
        w = new Resource();
        *w = *(other.w);
    }
    ResourceManager(ResourceManager&& other)
    {
        w = (other.w);
        other.w = nullptr;
    }
    
    ResourceManager& operator=(const ResourceManager& other)
    {
        *w = *other.w;
        return *this;
    }
    ResourceManager& operator=(ResourceManager&& other)
    {
        delete w;
        w = other.w;
        other.w = nullptr;

        return *this;
    }

    ~ResourceManager()
    {
        delete w;
    }

    double get()
    {
        return w->get();
    }
private:
    Resource* w;
};
