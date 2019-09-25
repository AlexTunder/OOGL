What is it?
    It's a cross-platform sub-libary for friendly API for openGL 3D fraphics. Libary wroten in C++ and all features realeased at classes
Keywords
    |________________________________________________________________________________________________
    |==========================================basic3d.hpp===========================================
    |===>Classes and namespaces:
    |    glClass - global namespace, where store almost of classes for display and algorithms.
    |    glClass::obj - Class with obj data and links for some resources.
    |    glClass::texture - Class, Where store texture, file path and other info. Uses in glClass::model.
    |    glClass::animation - Class with animation skelet and animation cadrs. (NOT REALESE!)
    |    glClass::model - Class, where have obj, image, animation, phisics box, & other data about model.
    |             Don't use as static data. In function throw only pointers or description of pointer.
    |    glClass::Point - array of 3 float.
    |    glClass::Polygon - array of 4 glClass::Points.
    |    glClass::Window - Class for all windows. (Wait for realise at 25.10.2019).
    |===>Methods    |===>glClass::model:
    |===============|draw() - start model projection.
    |===============|===>glClass::obj:
    |===============|getObjFromFile(path) - load obj model.
    |===> Global variavles and functions:
    |    glClass::makePoint(x, y, z) - make point with data x,y,z.
    |=========================================EventCore.hpp==========================================
    |===> Before include:
    |    #define DEFAULT_EVENT_32 1 - if you want to use Handler32 and Event32 as glClass::Event by default
    |    #define EVENTBUFFERSIZE [size] - set up size of event buffer. min - 1 max - 50. (1 by default)
    |===> Defines:
    |    EVENTBUFFERSIZE - is size of all buffers for Events. You can change this(read upply). By default = 1
    |    Event - is default event to usage(for more read upply).
    |    Handler - is default handler for usage. Shoud be same like Event
    |===> Classes and namespaces:
    |    glClass::Event16 - Class of event with 16-byte buffer. (low info size, for short data)
    |    glClass::Event32 - Class of event with 32-byte buffer. (a lot of info size, for long data)
    |    glClass::Handler16 - Class for catch 16-byte events and do somethink. Haven't default constructor.
    |    glClass::Handler32 - Class for catch 32-byte events and do somethink. Haven't default constructor.
    |    glClass::EventException - Object for callEventing some exception on handler/event work time.
    |===> Global variables and functions:
    |    glClass::EventBuffer16[size] - Array of char pointers, where 16-byte events throw pointer to itsaelf |             of short data.
    |    glClass::EventBuffer32[size] - Array of char pointers, where 32-byte events throw pointer to itsaelf |             of data.
    |    glClass::checkEventBuffer(1 - is 16 bit, 0 - 32) - This buffer is clear(1/0)
    |===> Methods   |glClass::Event16/32
    |===============|call(eventdata, static index of buffer) - call a event
    |===============|Event16/32() - default constructor
