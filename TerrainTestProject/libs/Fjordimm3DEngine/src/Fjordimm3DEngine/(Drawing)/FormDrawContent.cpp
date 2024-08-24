
#include "Fjordimm3DEngine/(Drawing)/FormDrawContent.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	FormDrawContent::FormDrawContent(Tran* tran, Mesh* mesh, Color materialColor, Texture* texture) :
		tran(tran),
		mesh(mesh),
		materialColor(materialColor),
		texture(texture)
	{}
}
