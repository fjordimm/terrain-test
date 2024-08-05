
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

void main()
{
	vec4 rotatedNormal = uni_SunRot * vec4(normalize(g_Normal), 1.0);

	float shadingMult = 0.5 + 0.5 * rotatedNormal.z; // clamp in range [0.0, 1.0]
	shadingMult *= shadingMult; // still clamped in [0.0, 1.0]
	shadingMult = uni_SunBrightness * shadingMult; // clamp in range [0.0, uni_SunBrightness]
	shadingMult = (uni_SunBrightness - uni_SunAmbientLight) * shadingMult + uni_SunAmbientLight; // clamp in range [uni_SunAmbientLight, uni_SunBrightness]

	f_Color = vec4(shadingMult * uni_SunColor, 1.0);
	
	if (uni_HasTexture)
	{ f_Color = texture(uni_TextureSampler0, g_TextureCoord) * f_Color; }
	// vec4 litColor = vec4(shadingMult * uni_SunColor, 1.0);
	// // vec4 texColor = texture(uni_TextureSampler0, g_TextureCoord);
	// vec4 texColor = mix(texture(uni_TextureSampler0, g_TextureCoord), texture(uni_TextureSampler1, g_TextureCoord), 0.9);
	// f_Color = texColor * litColor;
}
