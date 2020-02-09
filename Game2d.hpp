namespace glClass{
    class EntityRule{
        public:
        bool friendly, ai;
        float *stat;
        char *aiLink, *name;
    };
    class Image{
        public:
        char *rawdata;
        bool mkImage();
        bool clearImage();
        bool loadImage();
        Image(char *raw){
            
        }
        bool loaded();
    };
    class Frames{
        public:
        int coor[4];
        Image image;
        bool loadFromFile(char *src);
        bool clear();
    };
    class Entity{
        EntityRule entityRule;
        Frames frames;
    };
    class Map{

    };
    class GameEvent{

    };
    class Event{

    };
    class Handler{

    };
}