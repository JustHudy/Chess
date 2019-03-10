#ifndef LOADER_H
#define LOADER_H

#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <glm/glm.hpp>
#include <cstdlib>
#include <GL/glew.h>
#include <map>

class Loader
{
public:
	GLuint static loadShader(const char * vertex_file_path, const char * fragment_file_path);
	bool static loadObj(const char * path, GLuint& vertexbuffer, GLuint &normalbuffer, GLuint &elementbuffer, GLuint & indices);
	void static indexVBO(std::vector<glm::vec3> & in_vertices,std::vector<glm::vec3> & in_normals, std::vector<unsigned short> & out_indices, std::vector<glm::vec3> & out_vertices, std::vector<glm::vec3> & out_normals);
};

#endif
