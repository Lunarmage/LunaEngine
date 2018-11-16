#include "Texture.h"
#include "stb_image\stb_image.h"



void Texture::load(std::string path)
{

	int w = 0;
	int h = 0;
	int channels = 0;

	unsigned char *data = stbi_load(path.c_str(), &w, &h, &channels, 4);
	if (!data) {
		throw std::exception();
	}//abort}

		glGenTextures(1, &id);

		glBindTexture(GL_TEXTURE_2D, id);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		free(data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glBindTexture(GL_TEXTURE_2D, 0);

		this->path = path;
	
}

GLuint Texture::getID()
{
	return id;
}

