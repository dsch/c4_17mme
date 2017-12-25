#ifndef RESOURCE_MANAGER_H_
#define RESOURCE_MANAGER_H_

#include <vector>
#include "ImageResource.h"

/**
 * Manages game resource files such as images and sounds
 */
class ResourceManager {
public:
    /**
     * Returns a loaded image
     *
     * @param file Resource file to return
     * @return Image resource
     */
    static ImageResource* get_image(const char* file);

    /**
     * Loads an image and stores it
     *
     * @param file Resource file to load
     * @return Image resource
     */
    static ImageResource* load_image(const char* file);

    /**
     * Deletes a image
     *
     * @param file Resource file to unload
     */
    static void unload_image(const char* file);

private:
    /// Stores pointers to instances of an Image_resource
    static std::vector<std::pair<std::string, ImageResource*> > images;
};

#endif
