#pragma once

#include <memory>
#include <map>

#include <SFML/Graphics.hpp>

namespace Resources {

template<typename Resource, typename Identifier>
class ResourceHolder
{
    private:
        std::map<Identifier, std::unique_ptr<Resource>> mResourceMap;
    public:
        void load(Identifier id, const std::string& filename);
        Resource& get(Identifier id);
        const Resource& get(Identifier id) const;
};

#include "Textures.inl"

} // namespace Resources