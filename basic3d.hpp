#include <GL/freeglut.h>
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
            enum {VERTEXESLASTID,NORMALESLASTID,ENDERDcLASTID};
        //Points decloration
        Point *VERTEXES = new Point;
        Point *NORMALES = new Point;
        Point *TEX_VERT = new Point;
        Polygon *RENDERDC = new Polygon; //x - VERTEX.point, y - NORMALES.point, z - TEX_VERT.point, id - id
        //functions decloration
        int pushNewPoint(Point *VERTEX_TARGET, Point point);
        int getObjFromFile(char *string);
        char *FileWithTex;
    };
    int obj::getObjFromFile(char *string){
        VERTEXES[0].id = NORMALES[0].id = TEX_VERT[0].id = RENDERDC[0].points[0].id = 0;
        ifstream fin(string);
        std::string substr;
        while(fin.eof()){
            fin >> substr;
            if(substr == "v"){
                for(int i = 0; i<3; i++){
                    fin >> substr;
                    VERTEXES[++VERTEXES[0].id].x = std::stof(substr);
                }
            }else if(substr == "vn"){
                for(int i = 0; i<3; i++){
                    fin >> substr;
                    NORMALES[++NORMALES[0].id].x = std::stof(substr);
                }
            }else if(substr == "vt"){
                for(int i = 0; i<3; i++){
                    fin >> substr;
                    TEX_VERT[++TEX_VERT[0].id].x = std::stof(substr);
                }
            }else if(substr == "f"){
                for(int i = 0; i<4; i++){
                    fin >> substr;
                    RENDERDC[RENDERDC[0].points[0].id].points[i].x = substr[0];
                    if(substr[2] != '/') {
                        RENDERDC[RENDERDC[0].points[0].id].points[i].y = substr[2];
                        RENDERDC[RENDERDC[0].points[0].id].points[i].z = substr[5];
                    }else RENDERDC[RENDERDC[0].points[0].id].points[i].z = substr[3];
                }
            }
        }
    fin.close();
    }
    int obj::pushNewPoint(Point *VERTEX_TARGET, Point point){
        VERTEX_TARGET[VERTEX_TARGET[0].id] = point;
    }
    class model{
      public:
      obj main;
        void draw(){
            glBegin(GL_POLYGON);
            //drawing start
            for(int i = 1; i < main.RENDERDC[0].points[0].id; i++, glEnd())
                for(int y = 0; y < 4; y++){
                    /*TEXTURE:   ((main.TEX_VERT[main.RENDERDC[i].points[y].y].x,main.TEX_VERT[main.RENDERDC[i].points[y].y].y,main.TEX_VERT[main.RENDERDC[i].points[y].y].z))*/
                    /*NORMALE:   ((main.NORMALES[main.RENDERDC[i].points[y].z].x,main.NORMALES[main.RENDERDC[i].points[y].z].y,main.NORMALES[main.RENDERDC[i].points[y].z].z))*/
                        glVertex3f(main.VERTEXES[int(main.RENDERDC[i].points[y].x)].x,main.VERTEXES[int(main.RENDERDC[i].points[y].x)].y,main.VERTEXES[int(main.RENDERDC[i].points[y].x)].z);
                    }
            //drawing end
        }
    };
}
