
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSamples/Sphere.hpp"

#include <vector>
#include <cmath>
#include "Fjordimm3DEngine/(Util)/(Tran)/Vec.hpp"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(Util)/(Math)/Math.hpp"

namespace Fjordimm3DEngine::MeshSamples
{
	inline Vec2 posToTextureCoords(Vec vec)
	{ return Vec2(vec.x * 0.5f + 0.5f, vec.z * 0.5f + 0.5f); }

	template <std::size_t Size>
	void Sphere<Size>::generateData(bool doVertPositions3D, std::vector<Vec>& vertPositions3D, bool doVertNormals3D, std::vector<Vec>& vertNormals3D, bool doVertTextureCoords, std::vector<Vec2>& vertTextureCoords, std::vector<std::tuple<GLuint, GLuint, GLuint>>& triangles) const
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(Size > 0);

		const int numLayers = Size;
		const int numVertsPerLayer = Size * 2 + 2;
		const int numVerts = 1 + numLayers * numVertsPerLayer + 1;
		const int numTriangles = numVertsPerLayer * (1 + 2 * (numLayers - 1) + 1);

		/* Vertices */

		{
			// bottom vert
			Vec bottomVert = Vec(0.0f, 0.0f, -1.0f);
			if (doVertPositions3D)
			{ vertPositions3D.push_back(bottomVert); }
			if (doVertNormals3D)
			{ vertNormals3D.push_back(glm::normalize(bottomVert)); }
			if (doVertTextureCoords)
			{ vertTextureCoords.push_back(posToTextureCoords(bottomVert)); }

			// middle verts
			for (int i = 0; i < numLayers; i++)
			{
				float fractionOfVerticalSemicircle = (float)(i + 1) / (float)(numLayers + 1);
				float z = std::sin(Math::Pi * fractionOfVerticalSemicircle - Math::PiOver2);
				float r = std::cos(Math::Pi * fractionOfVerticalSemicircle - Math::PiOver2);

				for (int j = 0; j < numVertsPerLayer; j++)
				{
					float fractionOfHorizontalCircle = (float)j / (float)numVertsPerLayer;
					float x = r * std::cos(Math::TwoPi * fractionOfHorizontalCircle);
					float y = r * std::sin(Math::TwoPi * fractionOfHorizontalCircle);

					Vec vert = Vec(x, y, z);
					if (doVertPositions3D)
					{ vertPositions3D.push_back(vert); }
					if (doVertNormals3D)
					{ vertNormals3D.push_back(glm::normalize(vert)); }
					if (doVertTextureCoords)
					{ vertTextureCoords.push_back(posToTextureCoords(vert)); }
				}
			}

			// top vert
			Vec topVert = Vec(0.0f, 0.0f, +1.0f);
			if (doVertPositions3D)
			{ vertPositions3D.push_back(topVert); }
			if (doVertNormals3D)
			{ vertNormals3D.push_back(glm::normalize(topVert)); }
			if (doVertTextureCoords)
			{ vertTextureCoords.push_back(posToTextureCoords(topVert)); }
		}

		/* Triangles */

		{
			int bottomVert_i = 0;
			int topVert_i = numVerts - 1;

			// bottom cap
			for (int j = 0; j < numVertsPerLayer; j++)
			{
				GLuint vertBottom = bottomVert_i;
				GLuint vertTopLeft = 1 + j + 0;
				GLuint vertTopRight = (j == numVertsPerLayer - 1) ?
					1 + 0 :
					1 + j + 1;

				triangles.push_back(std::make_tuple(vertBottom, vertTopRight, vertTopLeft));
			}

			// middle squares
			for (int i = 0; i < numLayers - 1; i++)
			{
				for (int j = 0; j < numVertsPerLayer; j++)
				{
					GLuint vertBottomLeft = (1 + (numVertsPerLayer * (i + 0))) + j + 0;
					GLuint vertBottomRight = (j == numVertsPerLayer - 1) ?
						(1 + (numVertsPerLayer * (i + 0))) + 0 :
						(1 + (numVertsPerLayer * (i + 0))) + j + 1;
					GLuint vertTopLeft = (1 + (numVertsPerLayer * (i + 1))) + j + 0;
					GLuint vertTopRight = (j == numVertsPerLayer - 1) ?
						(1 + (numVertsPerLayer * (i + 1))) + 0 :
						(1 + (numVertsPerLayer * (i + 1))) + j + 1;
					
					triangles.push_back(std::make_tuple(vertTopRight, vertTopLeft, vertBottomLeft));
					triangles.push_back(std::make_tuple(vertTopRight, vertBottomLeft, vertBottomRight));
				}
			}

			// top cap
			for (int j = 0; j < numVertsPerLayer; j++)
			{
				GLuint vertTop = topVert_i;
				GLuint vertBottomLeft = (1 + (numVertsPerLayer * (numLayers - 1))) + j + 0;
				GLuint vertBottomRight = (j == numVertsPerLayer - 1) ?
					(1 + (numVertsPerLayer * (numLayers - 1))) + 0 :
					(1 + (numVertsPerLayer * (numLayers - 1))) + j + 1;

				triangles.push_back(std::make_tuple(vertTop, vertBottomLeft, vertBottomRight));
			}
		}
	}

	// solves linker errors
	Sphere<1>   sphere1;
	Sphere<2>   sphere2;
	Sphere<3>   sphere3;
	Sphere<4>   sphere4;
	Sphere<5>   sphere5;
	Sphere<6>   sphere6;
	Sphere<7>   sphere7;
	Sphere<8>   sphere8;
	Sphere<9>   sphere9;
	Sphere<10>  sphere10;
	Sphere<11>  sphere11;
	Sphere<12>  sphere12;
	Sphere<13>  sphere13;
	Sphere<14>  sphere14;
	Sphere<15>  sphere15;
	Sphere<16>  sphere16;
	Sphere<17>  sphere17;
	Sphere<18>  sphere18;
	Sphere<19>  sphere19;
	Sphere<20>  sphere20;
	Sphere<21>  sphere21;
}
