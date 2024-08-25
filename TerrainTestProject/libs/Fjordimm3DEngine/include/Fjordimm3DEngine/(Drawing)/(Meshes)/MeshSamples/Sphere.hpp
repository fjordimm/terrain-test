
#pragma once

#include <cstdlib>
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSample.hpp"

namespace Fjordimm3DEngine::MeshSamples
{
	template <std::size_t Size>
	class Sphere : public MeshSample
	{
	   protected:
		void generateData(bool doVertPositions3D, std::vector<Vec>& vertPositions3D, bool doVertNormals3D, std::vector<Vec>& vertNormals3D, bool doVertTextureCoords, std::vector<Vec2>& vertTextureCoords, std::vector<std::tuple<GLuint, GLuint, GLuint>>& triangles) const final;
	};
}
