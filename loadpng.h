#include <SOIL2.h>
GLuint tex_2d = SOIL_load_OGL_texture
    (
        "pic.png",
        SOIL_LOAD_AUTO,
        SOIL_CREATE_NEW_ID,
        SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
        );
