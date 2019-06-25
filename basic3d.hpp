#include <GL/glut.h>
#include <fstream>
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
        char *FileWithTex;
    };
    int obj::getObjFromFile(std::string string){
        VERTEXES[0].id = NORMALES[0].id = TEX_VERT[0].id = RENDERDC[0].points[0].id = 0;
        ifstream fin(string);
        std::string substr;
        if(!fin.is_open())
            return 95;
        while(!fin.eof()){
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
                TEX_VERT[0].id = 0;
                    fin >> substr;
                    TEX_VERT[TEX_VERT[0].id].x = std::stof(substr);
                    fin >> substr;
                    TEX_VERT[TEX_VERT[0].id].y = std::stof(substr);
                    fin >> substr;
                    TEX_VERT[TEX_VERT[0].id].z = std::stof(substr);
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
            }
        }
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
            glColor3f(1,1,0);
            for(int i = 1; i < main.PolygobCount; i++)
            {
                glBegin(GL_POLYGON);
                
                // for(int y = 0; y < 4; y++){
                //     /*TEXTURE:   ((main.TEX_VERT[main.RENDERDC[i].points[y].y].x,main.TEX_VERT[main.RENDERDC[i].points[y].y].y,main.TEX_VERT[main.RENDERDC[i].points[y].y].z))*/
                //     /*NORMALE:   ((main.NORMALES[main.RENDERDC[i].points[y].z].x,main.NORMALES[main.RENDERDC[i].points[y].z].y,main.NORMALES[main.RENDERDC[i].points[y].z].z))*/
                //         glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[y].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[y].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[y].x)].z);
                //     }
                //     glEnd();

                        glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[0].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[0].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[0].x)].z);
                        glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[1].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[1].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[1].x)].z);
                        glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[2].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[2].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[2].x)].z);
                        glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[3].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[3].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[3].x)].z);
            //drawing end
            glEnd();
            }
            
        }
    };
}