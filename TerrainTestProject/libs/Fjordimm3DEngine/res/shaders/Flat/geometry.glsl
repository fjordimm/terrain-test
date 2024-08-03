
#version 150 core

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;

in vec4 v_Coord[];
in vec2 v_TextureCoord[];

out vec3 g_Normal;
out vec2 g_TextureCoord;

void main()
{
	vec3 normalVector = normalize(cross((v_Coord[1] - v_Coord[0]).xyz, (v_Coord[2] - v_Coord[0]).xyz));

	for (int i = 0; i < gl_in.length(); i++)
	{
		gl_Position = gl_in[i].gl_Position;
		g_Normal = normalVector;
		g_TextureCoord = v_TextureCoord[i];
		EmitVertex();
	}

	EndPrimitive();
}
