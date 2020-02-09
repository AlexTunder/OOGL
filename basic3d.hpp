#include <GL/glut.h>
#include <fstream>
#include "defines.hpp"
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
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
    class window{
        int size[2], pos[2];
    };
    class init{
            // void operator(){

            // }
            int ortho[6];
            int *mainCella;
            char **argCella;
            // char &*argv;
    };
    class Point{
        public:
        float x, y, z;
        long id;
        Point(){
            x = y= z= id= 0;
        }
    };
    Point makePoint(long x, long y, long z){
        Point subReturn;
        subReturn.x = x;
        subReturn.y = y;
        subReturn.z = z;
        return subReturn;
    }
    // Point makePoint(long coordinats[3]){
    //     Point subReturn;
    //     subReturn.x = coordinats[0];
    //     subReturn.y = coordinats[1];
    //     subReturn.z = coordinats[2];
    //     return subReturn;
    // }
    Point findPointById(Point *target, int targetSize, int targetId){
        for(int i = 0; i<targetSize||&target[i]!=nullptr; i++)
            if(target[i].id == targetId) return target[i];
    }
    class Polygon{
        public:
        Point *points = new Point[4];
    };
    class obj{
        public:
        unsigned char *tex;
        std::string name;
        long long vertcount[4];
        GLuint texture;
        int w = 0, h = 0, c = 0;
        // GLuint texture = loadPngImage("/home/alex/Леон.png",nullptr,nullptr);

        // if (0 == tex_2d)
        // {
        //     printf("SOIL loading error: '%s'\n", SOIL_last_result());
        // }
        int PolygobCount;
            // enum {VERTEXESLASTID,NORMALESLASTID,ENDERDcLASTID};
        //Points decloration
        Point *VERTEXES;
        Point *NORMALES;
        Point *TEX_VERT;
        Polygon *RENDERDC; //x - VERTEX.point, y - NORMALES.point, z - TEX_VERT.point, id - id
        //functions decloration
        int pushNewPoint(Point *VERTEX_TARGET, Point point);
        void getObjFromFile(std::string string);
        string mtlPath, imagePath;
        ~obj(){
            delete [] VERTEXES;
            delete [] NORMALES;
            delete [] TEX_VERT;
            delete [] RENDERDC;
        }
    };
    void obj::getObjFromFile(std::string string){
        // VERTEXES[0].id = NORMALES[0].id = TEX_VERT[0].id = RENDERDC[0].points[0].id = 0;
        ifstream fin(string);
        std::string substr;
        if(!fin.is_open())
            // throw ("Can't load image with stbi! See 94 str.");
            // return 95;
        while(!fin.eof()){ // OBJ file read
            fin >> substr;
            if(substr == "o"){
                fin >> name;
                for(int i = 0; i < 4; i++)
                    fin >> vertcount[i];
                VERTEXES = new Point[vertcount[0]];
                TEX_VERT = new Point[vertcount[1]];
                NORMALES = new Point[vertcount[2]];
                RENDERDC = new Polygon[++vertcount[3]];
            }else if(substr == "v"){
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
                //stof don't wok here. Don't change!
                PolygobCount = RENDERDC[0].points[0].id++;
                for(int i = 0; i<4; i++){
                    fin >> substr;
                    RENDERDC[RENDERDC[0].points[0].id].points[i].y = atoi(substr.c_str());
                    fin >> substr;
                    RENDERDC[RENDERDC[0].points[0].id].points[i].x = atoi(substr.c_str());
                    fin >> substr;
                    RENDERDC[RENDERDC[0].points[0].id].points[i].z = atoi(substr.c_str());
                }
            }else if(substr == "mtllib"){
                fin >> mtlPath;
            }
        }
            // fin(mtlPath);
            ifstream newfin(mtlPath);
            if(!newfin.is_open()){
                newfin.close();
                // return 85;
            }
            while(!newfin.eof()){
                newfin >> substr;
                if(substr == "map_Kd"){
                    newfin >> imagePath;
                }
            }
            tex = stbi_load(imagePath.c_str(), &w, &h, &c, 0);
            glGenTextures(1, &texture);
            glBindTexture(GL_TEXTURE_2D, texture);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            if(c == 4)  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex);
            else glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, tex);
            // ___png___
            // if (imagePath != "")
            //     LoadGLTextures(ssyJJaszZPPaR);
    fin.close();
    // return 0;
}
    int obj::pushNewPoint(Point *VERTEX_TARGET, Point point){
        VERTEX_TARGET[VERTEX_TARGET[0].id] = point;
    }
class model{
public:
    obj main;
    ~model(){
        delete &main;
    }
        void draw(){
            //drawing start
            // glEnable(GL_TEXTURE_2D);
            // glBindTexture(GL_TEXTURE_2D, tga->texture[ 0 ].texID);
            // glBindTexture(GL_TEXTURE_2D, *main.texture);
            for(int i = 1; i <= main.RENDERDC[0].points[0].id; i++){
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