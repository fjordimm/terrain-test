
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/TerrainTest/TerrainTestHead.hpp"

int main(void)
{
	using namespace Fjordimm3DEngine;

	// TODO: assertions checking for nullptr

	TerrainTest::TerrainTestHead head;
	head.start(1300, 750);

	return 0;
}
