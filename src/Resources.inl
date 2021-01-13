//#include <assert.h>

template<typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const std::string& filename)
{
    std::unique_ptr<sf::Texture> resource(new Resource());

    if (!resource->loadFromFile(filename))
        throw std::runtime_error("TextureHolder::load - failed to load the file " + filename);
    auto inserted = mResourceMap.insert(std::make_pair(id, std::move(resource)));
    assert(inserted.second);
}

template<typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
    auto resourcePtr = mResourceMap.find(id);
    assert(resourcePtr != mResourceMap.end());
    return *resourcePtr->second;
}

template<typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
    auto resourcePtr = mResourceMap.find(id);
    assert(resourcePtr != mResourceMap.end());
    return *resourcePtr->second;
}
