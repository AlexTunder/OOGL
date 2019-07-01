#include <GL/glut.h>
#include <fstream>
#include <SOIL2.h>
#include <cstring>
#include "loadpng.h"
#include <FreeImage.h>
// #include <lo
// #include <GL
// #include <SOIL
// #include <cstring.h>
using namespace std;
//САНЯ БЛЯТЬ, ЗАПОМНИ:
/*
    координаты вершин (v) 
    координаты текстуры (vt) 
    координаты нормали (vn)
    Параметры одной поверхности объекта (f)
    Комментарии (#)
    v - описание соединения точек по id. пример:
    v id_точи_в_пространстве/id_точки_с_текстурой/id_с_нормалью
    т.е.:
    v vertex/texture/narmale (v 1/2/3)
*/
/* Program entry point */

namespace glClass
{
    class Point{
        public:
        float x, y, z;
        long id;
    };
    Point makePoint(long x, long y, long z){
        Point subReturn;
        subReturn.x = x;
        subReturn.y = y;
        subReturn.z = z;
        return subReturn;
    }
    Point makePoint(long coordinats[3]){
        Point subReturn;
        subReturn.x = coordinats[0];
        subReturn.y = coordinats[1];
        subReturn.z = coordinats[2];
        return subReturn;
    }
    Point findPointById(Point *target, int targetSize, int targetId){
        for(int i = 0; i<targetSize||&target[i]!=nullptr; i++)
            if(target[i].id == targetId) return target[i];
    }
    class Polygon{
        public:
        Point points[4];
    };
    class obj{
        public:
        GLuint texture = SOIL_load_OGL_texture
            (
                "/home/alex/Леон.png",
                SOIL_LOAD_AUTO,
                SOIL_CREATE_NEW_ID,
                SOIL_FLAG_MIPMAPS | SOIL_FLAG_COMPRESS_TO_DXT
                );

        // if (0 == tex_2d)
        // {
        //     printf("SOIL loading error: '%s'\n", SOIL_last_result());
        // }
        int PolygobCount;
            enum {VERTEXESLASTID,NORMALESLASTID,ENDERDcLASTID};
        //Points decloration
        Point VERTEXES[150];
        Point NORMALES[150];
        Point TEX_VERT[150];
        Polygon RENDERDC[150]; //x - VERTEX.point, y - NORMALES.point, z - TEX_VERT.point, id - id
        //functions decloration
        int pushNewPoint(Point *VERTEX_TARGET, Point point);
        int getObjFromFile(std::string string);
        string mtlPath, imagePath;
    };
    int obj::getObjFromFile(std::string string){
        VERTEXES[0].id = NORMALES[0].id = TEX_VERT[0].id = RENDERDC[0].points[0].id = 0;
        ifstream fin(string);
        std::string substr;
        if(!fin.is_open())
            return 95;
        while(!fin.eof()){ // OBJ file read
            fin >> substr;
            if(substr == "v"){
                VERTEXES[0].id++;
                    fin >> substr;
                    VERTEXES[VERTEXES[0].id].x = std::stof(substr);
                    fin >> substr;
                    VERTEXES[VERTEXES[0].id].y = std::stof(substr);
                    fin >> substr;
                    VERTEXES[VERTEXES[0].id].z = std::stof(substr);
            }else if(substr == "vn"){
                NORMALES[0].id++;
                    fin >> substr;
                    NORMALES[NORMALES[0].id].x = std::stof(substr);
                    fin >> substr;
                    NORMALES[NORMALES[0].id].y = std::stof(substr);
                    fin >> substr;
                    NORMALES[NORMALES[0].id].z = std::stof(substr);
            }else if(substr == "vt"){
                TEX_VERT[0].id++;
                    fin >> substr;
                    TEX_VERT[TEX_VERT[0].id].x = std::stof(substr);
                    fin >> substr;
                    TEX_VERT[TEX_VERT[0].id].y = std::stof(substr);
            }else if(substr == "f"){
                PolygobCount = RENDERDC[0].points[0].id++;
                for(int i = 0; i<4; i++){
                    fin >> substr;
                    RENDERDC[RENDERDC[0].points[0].id].points[i].x = substr[0]  - '0';
                    if(substr[2] != '/') {
                        RENDERDC[RENDERDC[0].points[0].id].points[i].y = substr[2] - '0';
                        RENDERDC[RENDERDC[0].points[0].id].points[i].z = substr[5] - '0';
                    }else RENDERDC[RENDERDC[0].points[0].id].points[i].z = substr[3] - '0';
                }
            }else if(substr == "mtllib"){
                fin >> mtlPath;
            }
        }
            // fin(mtlPath);
            ifstream newfin(mtlPath);
            if(!newfin.is_open()){
                newfin.close();
                return 85;
            }
            while(!newfin.eof()){
                newfin >> substr;
                if(substr == "map_Kd"){
                    newfin >> imagePath;
                }
            }
            char *ssyJJaszZPPaR = new char;
            strcpy(ssyJJaszZPPaR, imagePath.c_str());
            // if (imagePath != "")
            //     LoadGLTextures(ssyJJaszZPPaR);
    fin.close();
    return 0;
}
    int obj::pushNewPoint(Point *VERTEX_TARGET, Point point){
        VERTEX_TARGET[VERTEX_TARGET[0].id] = point;
    }
    class model{
      public:
      obj main;
        void draw(){
            //drawing start
            // glEnable(GL_TEXTURE_2D);
            // glBindTexture(GL_TEXTURE_2D, tga->texture[ 0 ].texID);
            glBindTexture(GL_TEXTURE_2D, main.texture);
            for(int i = 1; i <= main.PolygobCount; i++){
                glBegin(GL_QUADS);
                glTexCoord2f(main.TEX_VERT[int(main.RENDERDC[i].points[0].y)].x,main.TEX_VERT[int(main.RENDERDC[i].points[i].y)].y);
                glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[0].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[0].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[0].x)].z);
                glTexCoord2f(main.TEX_VERT[int(main.RENDERDC[i].points[1].y)].x,main.TEX_VERT[int(main.RENDERDC[i].points[i].y)].y);
                glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[1].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[1].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[1].x)].z);
                glTexCoord2f(main.TEX_VERT[int(main.RENDERDC[i].points[2].y)].x,main.TEX_VERT[int(main.RENDERDC[i].points[i].y)].y);
                glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[2].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[2].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[2].x)].z);
                glTexCoord2f(main.TEX_VERT[int(main.RENDERDC[i].points[3].y)].x,main.TEX_VERT[int(main.RENDERDC[i].points[i].y)].y);
                glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[3].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[3].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[3].x)].z);
                glEnd();
            }
            
        }
    };
}