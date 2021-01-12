#pragma once

#include <memory>
#include <map>

#include <SFML/Graphics.hpp>

namespace Textures {

enum class ID { Landscape, Airplane, Missile };

class TextureHolder
{
    private:
        std::map<ID, std::unique_ptr<sf::Texture>> mTextureMap;
    public:
        void load(ID id, const std::string& filename);
        sf::Texture& get(ID id);
        const sf::Texture& get(ID id) const;
};

} // namespace Textures