#this is cross-platfor Simple API for OOGL
=============Basic commands===============
==================C++=====================
Namespaces:		          glClass:
CLasses:	            glClass::model		Userfriendly interface for glClass::obj
              		   glClass::window		Basic class for Window
		 	     glClass::init		Init class
			    glClass::Point		Point with x,y,z cords
			  glClass::Polygon		4 points array
			      glClass::obj		Basic obj class for 3D models
Functions:
Solo:
glClass::Point makePoint(long x, long y, long z) - for make new example point (point[i] = makePoint(x,y,z))
glClass::Point makePoint(long cords[3]) - for making new point from long array (point[i] = makePoint(arr))
Methodes:
#####obj:		getObjFromFile(sting path) - loading 3D object from *path* file(.OBJ format)
#####obj:		pushNewPoint(Point *VERTEX_TARGET, Point point) - push point to end of VERTEX_TARGET
Cellas:
#####obj:		
