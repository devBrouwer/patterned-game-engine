#ifndef MESH_H
#define MESH_H
#include <vector>
#include <GL/glew.h>
#include "glm.hpp"
#include "Visitable.hpp"

class Renderer;

class Mesh : public Visitable
{
	private: // data mambers
		std::vector< unsigned int > indices; // index to the v/n/t/u/
		std::vector< glm::vec3 > vertices; // all the vertices
		std::vector< glm::vec3 > normals; // normal to the vertex
		std::vector< glm::vec2 > uvs; // uv to the vertex


		GLuint indicesBuffer; // id of buffered mesh;
		GLuint verticesBuffer; // id of buffered mesh;
		GLuint normalsBuffer; // buffered normals id
		GLuint uvsBuffer; // buffered uv's id

	public: // functions
		Mesh();
		virtual ~Mesh();

		static Mesh * load( const char * fileName , glm::vec3 scale = glm::vec3(1.0,1.0,1.0) );

		unsigned int size();

        virtual void accept(Visitor * visitor);

        GLuint getIndicesBuffer();
        GLuint getVerticesBuffer();
        GLuint getNormalsBuffer();
        GLuint getUvsBuffer();
        std::vector<glm::vec3> getVertices();

	private:
		void buffer();
		void unBuffer();

		class PackedIndex { // for loading and converting to indexed arrays
			public:
				unsigned int v;
				unsigned int n;
				unsigned int t;
				PackedIndex( unsigned int aV, unsigned int aN, unsigned int aT )
				:	v(aV),n(aN),t(aT) {
				}
				bool operator<(const PackedIndex other) const{ // needed for use as key in map
					return memcmp((void*)this, (void*)&other, sizeof(PackedIndex))>0;
				}
		};

};

#endif // MESH_H
