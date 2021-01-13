#include <iostream>
#include <assert.h>

#include "Textures.hpp"

#include <SFML/Graphics.hpp>

using namespace Textures;

void TextureHolder::load(ID id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> texture(new sf::Texture());

    if (!texture->loadFromFile(filename))
        throw std::runtime_error("TextureHolder::load - failed to load the file " + filename);
    auto inserted = mTextureMap.insert(std::make_pair(id, std::move(texture)));
    assert(inserted.second);
}

sf::Texture& TextureHolder::get(ID id)
{
    auto texturePtr = mTextureMap.find(id);
    assert(texturePtr != mTextureMap.end());
    return *texturePtr->second;
}

const sf::Texture& TextureHolder::get(ID id) const
{
    auto texturePtr = mTextureMap.find(id);
    assert(texturePtr != mTextureMap.end());
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