// #include <GL/glut.h>
#include <GL/gl.h>
// #include <GL/glew.h>
#include <stb_image.h>
namespace images
{
    class png{
      public:
      char *path = new char;
        int height, width, comp;
        unsigned int texture;
        unsigned char *pngFhhatexture = new unsigned char;// = stbi_load(path, &hieght, &width, &comp, STBI_rgb);
        void update(){
            pngFhhatexture = stbi_load(path, &height, &width, &comp, STBI_rgb);
            glGenTextures(1,&texture);
            glBindTexture(GL_TEXTURE_2D, texture);  
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pngFhhatexture);
            // glGenerateMipmap(GL_TEXTURE_2D);
            stbi_image_free(pngFhhatexture);
            glDisable(GL_TEXTURE_2D);
            // glDisable()
        }
    };
    class jpeg{

    };
} // namespace images
