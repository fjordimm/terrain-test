
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/TerrainTest/TerrainTestHead.hpp"

#include "lodepng.h"

int main(void)
{
	using namespace Fjordimm3DEngine;

	std::vector<unsigned char> image;
	unsigned width;
	unsigned height;

	unsigned error = lodepng::decode(image, width, height, std::string(CMAKECONFIG_SOURCE_DIR) + "/libs/Fjordimm3DEngine/" + "res/textures/star.png");

	Debug::Log("haha image");
	for (std::size_t i = 0; i < image.size(); i++)
	{
		Debug::Printf("%i ", image[i]);
	}

	// TerrainTest::TerrainTestHead head;
	// head.start(1300, 750);

	return 0;
}
