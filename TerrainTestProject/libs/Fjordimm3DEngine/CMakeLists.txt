
configure_file("cmakeconfig/CMakeConfig.h.in" "cmakeconfig/CMakeConfig.h")

add_executable(Fjordimm3DEngineExec
	"src/Fjordimm3DEngine/Program.cpp"
	"src/Fjordimm3DEngine/(World)/Head.cpp"
	"src/Fjordimm3DEngine/(World)/WorldState.cpp"
	"src/Fjordimm3DEngine/(Debug)/_globals.cpp"
	"src/Fjordimm3DEngine/(Debug)/_logging.cpp"
	"src/Fjordimm3DEngine/(FileLoading)/FileLoading.cpp"
	"src/Fjordimm3DEngine/(Util)/(Math)/_functions.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/Flat.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/Smooth.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgramManager.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/In3DSpace.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/Has3DShape.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasNormals.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasTexture.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/HasMaterial.cpp"
	"src/Fjordimm3DEngine/(Drawing)/FormDrawContent.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshData.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSample.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSamples/Cube.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSamples/Sphere.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Textures)/Texture.cpp"
	"src/Fjordimm3DEngine/(Util)/(Tran)/Tran.cpp"
	"src/Fjordimm3DEngine/(Util)/(Tran)/Vec.cpp"
	"src/Fjordimm3DEngine/(Util)/(Tran)/Quat.cpp"
	"src/Fjordimm3DEngine/(Form)/FormManager.cpp"
	"src/Fjordimm3DEngine/(Form)/Form.cpp"
	"src/Fjordimm3DEngine/(Form)/Forms/Camera.cpp"
	"src/Fjordimm3DEngine/(Form)/PhysicForm.cpp"
	"src/Fjordimm3DEngine/(PtrForGlfw)/PtrForGlfw.cpp"
	"src/Fjordimm3DEngine/(InputManager)/InputManager.cpp"
	"src/Fjordimm3DEngine/(Util)/(Color)/Color.cpp"
	"src/Fjordimm3DEngine/(Util)/(Random)/Random.cpp"
	"src/Fjordimm3DEngine/TerrainTest/TerrainTestHead.cpp"
	"src/Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainManager.cpp"
	"src/Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.cpp"
	"src/Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/ChunkMesh.cpp"
	"src/Fjordimm3DEngine/(Util)/(OpenSimplexNoise)/OpenSimplexNoise.cpp"
	"src/Fjordimm3DEngine/(World)/GlTaskRequestManager.cpp"
)

target_include_directories(Fjordimm3DEngineExec PUBLIC "include")
target_include_directories(Fjordimm3DEngineExec PUBLIC "${PROJECT_BINARY_DIR}/libs/Fjordimm3DEngine/cmakeconfig")

target_include_directories(Fjordimm3DEngineExec PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../GLFW/include")
target_link_libraries(Fjordimm3DEngineExec "${CMAKE_CURRENT_SOURCE_DIR}/../GLFW/lib/ninja-libglfw3.a")

target_include_directories(Fjordimm3DEngineExec PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../GLEW/include")
target_link_libraries(Fjordimm3DEngineExec "${CMAKE_CURRENT_SOURCE_DIR}/../GLEW/lib/ninja-libglew32.a")

target_include_directories(Fjordimm3DEngineExec PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../GLM/include")

find_package(OpenGL REQUIRED)
target_link_libraries(Fjordimm3DEngineExec OpenGL::GL)
target_link_libraries(Fjordimm3DEngineExec OpenGL::GLU)

target_include_directories(Fjordimm3DEngineExec PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/../LodePNG/include")
target_link_libraries(Fjordimm3DEngineExec LodePNG)

# target_compile_options(Fjordimm3DEngineExec PRIVATE -O2)
target_compile_options(Fjordimm3DEngineExec PRIVATE -Wall -pedantic -Wno-unused-variable)
