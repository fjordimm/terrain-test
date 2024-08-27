
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Vec.hpp"
#include "Fjordimm3DEngine/TerrainTest/TerrainTestHead.hpp"
#include "Fjordimm3DEngine/(World)/GlTaskRequestManager.hpp"

float shmee(int a, int b)
{
	return ((float)a + (float)b) / 2.0f;
}

int main(void)
{
	using namespace Fjordimm3DEngine;

	// TODO: mutexs for all the stuff that needs it (start with the managers in WorldState)

	GlTaskRequestManager uh;
	std::future<float> yoinks = uh.request(shmee, 7, 8);
	Debug::Log("result = %f", yoinks.get());

	// TerrainTest::TerrainTestHead head;
	// head.start(1300, 750);

	return 0;
}
