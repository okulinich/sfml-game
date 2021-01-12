#include <iostream>

#include "Textures.hpp"

#include <SFML/Graphics.hpp>

using namespace Textures;

void TextureHolder::load(ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());

    texture->loadFromFile(filename);
    mTextureMap.insert(std::make_pair(id, std::move(texture)));
}

sf::Texture& TextureHolder::get(ID id)
{
    auto texturePtr = mTextureMap.find(id);
    return *texturePtr->second;
}

const sf::Texture& TextureHolder::get(ID id) const
{
    auto texturePtr = mTextureMap.find(id);
    return *texturePtr->second;
}

// test
// int main()
// {
//     TextureHolder holder;
//     holder.load(ID::Airplane,"resources/textures/player.png");

//     sf::Sprite sprite;
//     sprite.setTexture(holder.get(ID::Airplane));

//     return 0;
// }