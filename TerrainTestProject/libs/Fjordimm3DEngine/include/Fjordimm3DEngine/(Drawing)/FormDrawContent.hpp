
#pragma once

#include "Fjordimm3DEngine/(Util)/(Tran)/Tran.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Textures)/Texture.hpp"
#include "Fjordimm3DEngine/(Util)/(Color)/Color.hpp"

namespace Fjordimm3DEngine
{
	class FormDrawContent
	{
		/* Constructors */

	   public:
		FormDrawContent() = delete;
		FormDrawContent(const FormDrawContent&) = delete;
		FormDrawContent& operator=(const FormDrawContent&) = delete;
		
		FormDrawContent(Tran* tran, Mesh* mesh, Color materialColor, Texture* texture);
		
		/* Fields */

	   public:
		Tran* tran;
		Mesh* mesh;
		Color materialColor;
		Texture* texture;
	};
}
