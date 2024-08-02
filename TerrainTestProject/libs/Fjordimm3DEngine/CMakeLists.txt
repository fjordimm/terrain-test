
configure_file(CMakeConfig.h.in CMakeConfig.h)

add_executable(Fjordimm3DEngineExec
	"src/Fjordimm3DEngine/Program.cpp"
	"src/Fjordimm3DEngine/(World)/Head.cpp"
	"src/Fjordimm3DEngine/(World)/WorldState.cpp"
	"src/Fjordimm3DEngine/(Debug)/_logging.cpp"
	"src/Fjordimm3DEngine/(FileLoading)/FileLoading.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/Flat.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgramManager.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/In3DSpace.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/Has3DShape.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshData.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSample.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshVertAttribs.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSamples/Cube.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSamples/Sphere.cpp"
	"src/Fjordimm3DEngine/(Drawing)/(Meshes)/MeshManager.cpp"
	"src/Fjordimm3DEngine/(Util)/(Tran)/Tran.cpp"
	"src/Fjordimm3DEngine/(Util)/(Tran)/Vec.cpp"
	"src/Fjordimm3DEngine/(Util)/(Tran)/Quat.cpp"
	"src/Fjordimm3DEngine/(Form)/Form.cpp"
	"src/Fjordimm3DEngine/(Form)/Forms/Camera.cpp"
	"src/Fjordimm3DEngine/(Form)/PhysicForm.cpp"
	"src/Fjordimm3DEngine/(PtrForGlfw)/PtrForGlfw.cpp"
	"src/Fjordimm3DEngine/(InputManager)/InputManager.cpp"
	"src/Fjordimm3DEngine/(Util)/(Color)/Color.cpp"
	"src/Fjordimm3DEngine/TerrainTest/TerrainTestHead.cpp"
)

target_include_directories(Fjordimm3DEngineExec PUBLIC include)
target_include_directories(Fjordimm3DEngineExec PUBLIC "${PROJECT_BINARY_DIR}/libs/Fjordimm3DEngine")

target_include_directories(Fjordimm3DEngineExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../GLFW/include)
target_link_libraries(Fjordimm3DEngineExec ${CMAKE_CURRENT_SOURCE_DIR}/../GLFW/lib/ninja-libglfw3.a)

target_include_directories(Fjordimm3DEngineExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../GLEW/include)
target_link_libraries(Fjordimm3DEngineExec ${CMAKE_CURRENT_SOURCE_DIR}/../GLEW/lib/ninja-libglew32.a)

target_include_directories(Fjordimm3DEngineExec PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../GLM/include)

find_package(OpenGL REQUIRED)
target_link_libraries(Fjordimm3DEngineExec OpenGL::GL)

target_compile_options(Fjordimm3DEngineExec PRIVATE)
