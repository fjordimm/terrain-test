
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Vec.hpp"
#include "Fjordimm3DEngine/TerrainTest/TerrainTestHead.hpp"

int main(void)
{
	using namespace Fjordimm3DEngine;

	// TODO: assertions checking for nullptr

	// Vec bottomLeft = Vec(0.0f, 0.0f, 0.0f);
	// Vec bottomRight = Vec(1.0f, 2.0f, 1.75f);
	// Vec topLeft = Vec(0.0f, 1.0f, 0.84f);
	// Vec topRight = Vec(1.0f, 3.0f, 0.98f);

	TerrainTest::TerrainTestHead head;
	head.start(1300, 750);

	return 0;
}
