
#version 150 core

uniform mat4 uni_SunRot;
uniform float uni_SunBrightness;
uniform float uni_SunAmbientLight;
uniform vec3 uni_SunColor;
uniform bool uni_HasTexture;
uniform sampler2D uni_TextureSampler0;

in vec3 g_Normal;
in vec2 g_TextureCoord;

out vec4 f_Color;

const highp float DITHERING_NOISE_GRANULARITY = 1.0 / 255.0;
highp float dithering_random(highp vec2 coords)
{
	return fract(sin(dot(coords.xy, vec2(12.9898, 78.233))) * 43758.5453);
}

void main()
{
	vec4 rotatedNormal = uni_SunRot * vec4(normalize(g_Normal), 1.0);

	float shadingMult = 0.5 + 0.5 * rotatedNormal.z; // clamp in range [0.0, 1.0]
	shadingMult *= shadingMult; // still clamped in [0.0, 1.0]
	shadingMult = uni_SunBrightness * shadingMult; // clamp in range [0.0, uni_SunBrightness]
	shadingMult = (uni_SunBrightness - uni_SunAmbientLight) * shadingMult + uni_SunAmbientLight; // clamp in range [uni_SunAmbientLight, uni_SunBrightness]
	
	shadingMult += mix(-DITHERING_NOISE_GRANULARITY, DITHERING_NOISE_GRANULARITY, dithering_random(rotatedNormal.xy));

	f_Color = vec4(shadingMult * uni_SunColor, 1.0);

	// if (uni_HasTexture)
	// { f_Color = texture(uni_TextureSampler0, g_TextureCoord) * f_Color; }
}
