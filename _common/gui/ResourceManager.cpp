/*
 * Connect Four
 * MIT Licence, Copyright 2017 Chris Kempson (chriskempson.com)
 */

#include <iostream>
#include <string>
#include "ResourceManager.h"

// Define vectors to store pointers to instances of resource classes
std::vector<std::pair<std::string, ImageResource*> > ResourceManager::images;

ImageResource* ResourceManager::get_image(const char* file) {

	// Check each entry until we find one that matches file as file is being
	// used an ID
	for (unsigned int i = 0; i < images.size(); i++) {
		if (images[i].first == file) {
			return images[i].second;
		}
	}

	std::cout << "Could not find resource: " << file << std::endl;
	return NULL;
}

ImageResource* ResourceManager::load_image(const char* file) {

	// Load a resource file, store the instance and then return it
	ImageResource* image = new ImageResource();
	image->load_from_file(file);
	images.insert(images.end(), std::make_pair(file, image));
	return get_image(file);
}

void ResourceManager::unload_image(const char* file) {

	// Check each entry until we find one that matches file as file is being
	// used an ID
	for (unsigned int i = 0; i < images.size(); i++) {
		if (images[i].first == file) {

			// Delete instance since it was created with new
			delete images[i].second;
			images[i].second = NULL;

			// Remove unneeded entry from vector
			images.erase(images.begin() + i);
		}
	}
}
