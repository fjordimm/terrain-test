
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"
#include "Fjordimm3DEngine/TerrainTest/TerrainTestHead.hpp"

int main(void)
{
	using namespace Fjordimm3DEngine;

	// TODO: assertions checking for nullptr

	Random::Reseed();

	{
		for (int i = 0; i < 8; i++)
		{
			Debug::Logf("%i", Random::FromBernoulli());
		}
	}

	TerrainTest::TerrainTestHead head;
	head.start(1300, 750);

	return 0;
}
