#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <shader.h>
#include <Acamera.h>
#include <WholeModel.h>
#include <points.h>

#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void mouse_callback(GLFWwindow* window, double xpos, double ypos);
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
void processInput(GLFWwindow *window);
unsigned int loadTexture(const char *path);
unsigned int loadCubemap(vector<std::string> faces);

// settings
const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

// camera
Camera camera(glm::vec3(0.0f, 2.0f, 3.0f));
float lastX = (float)SCR_WIDTH / 2.0;
float lastY = (float)SCR_HEIGHT / 2.0;
bool firstMouse = true;

// timing
float deltaTime = 0.0f;
float lastFrame = 0.0f;
bool day = true;

//=================================================================================
unsigned int wallVAO = 0;
unsigned int wallVBO = 0;
void renderWall()
{
	// initialize (if necessary)
	if (wallVAO == 0)
	{
		glGenVertexArrays(1, &wallVAO);
		glGenBuffers(1, &wallVBO);
		// fill buffer
		glBindBuffer(GL_ARRAY_BUFFER, wallVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(wall), wall, GL_STATIC_DRAW);
		// link vertex attributes
		glBindVertexArray(wallVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	// render Cube
	glBindVertexArray(wallVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

unsigned int boardVAO = 0;
unsigned int boardVBO = 0;
void renderBoard()
{
	// initialize (if necessary)
	if (boardVAO == 0)
	{
		glGenVertexArrays(1, &boardVAO);
		glGenBuffers(1, &boardVBO);
		// fill buffer
		glBindBuffer(GL_ARRAY_BUFFER, boardVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(board), board, GL_STATIC_DRAW);
		// link vertex attributes
		glBindVertexArray(boardVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	// render Cube
	glBindVertexArray(boardVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

unsigned int planeVAO = 0;
unsigned int planeVBO;
void renderPlane() {
	if (planeVAO == 0)
	{
		// setup plane VAO
		glGenVertexArrays(1, &planeVAO);
		glGenBuffers(1, &planeVBO);
		glBindVertexArray(planeVAO);
		glBindBuffer(GL_ARRAY_BUFFER, planeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(planeVertices), planeVertices, GL_STATIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	}
	glBindVertexArray(planeVAO);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glBindVertexArray(0);
}

unsigned int cubeVAO = 0;
unsigned int cubeVBO = 0;
void renderCube()
{
	// initialize (if necessary)
	if (cubeVAO == 0)
	{
		glGenVertexArrays(1, &cubeVAO);
		glGenBuffers(1, &cubeVBO);
		// fill buffer
		glBindBuffer(GL_ARRAY_BUFFER, cubeVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(Cubevertices), Cubevertices, GL_STATIC_DRAW);
		// link vertex attributes
		glBindVertexArray(cubeVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	// render Cube
	glBindVertexArray(cubeVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

unsigned int columnVAO = 0;
unsigned int columnVBO = 0;
void renderColumn()
{
	// initialize (if necessary)
	if (columnVAO == 0)
	{
		glGenVertexArrays(1, &columnVAO);
		glGenBuffers(1, &columnVBO);
		// fill buffer
		glBindBuffer(GL_ARRAY_BUFFER, columnVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(column), column, GL_STATIC_DRAW);
		// link vertex attributes
		glBindVertexArray(columnVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(1);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(2);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	// render Cube
	glBindVertexArray(columnVAO);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindVertexArray(0);
}

unsigned int ballVAO = 0;
unsigned int ballVBO = 0;
void renderBall(const Shader &shader,float radius) 
{
	// initialize (if necessary)
	int uStepsNum = 20, vStepsNum = 20;
	shader.setFloat("radius", radius);
	shader.setInt("uStepsNum", uStepsNum);
	shader.setInt("vStepsNum", vStepsNum);
	if (ballVAO == 0)
	{
		glGenVertexArrays(1, &ballVAO);
		glGenBuffers(1, &ballVBO);
		// fill buffer
		glBindBuffer(GL_ARRAY_BUFFER, ballVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(ball), ball, GL_STATIC_DRAW);
		// link vertex attributes
		glBindVertexArray(ballVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	glBindVertexArray(ballVAO);
	float ustep = 1.0f / uStepsNum;
	for (int i = 0; i < uStepsNum; i++) {
		shader.setFloat("uStep", ustep*i);
		glDrawArrays(GL_POINTS, 0, 1);
	}
	glBindVertexArray(0);
}

unsigned int vaseVAO = 0;
unsigned int vaseVBO = 0;
void renderVase(const Shader &shader, float radius)
{
	// initialize (if necessary)
	int uStepsNum = 20, vStepsNum = 20;
	shader.setFloat("radius", radius);
	shader.setInt("uStepsNum", uStepsNum);
	shader.setInt("vStepsNum", vStepsNum);
	if (vaseVAO == 0)
	{
		glGenVertexArrays(1, &vaseVAO);
		glGenBuffers(1, &vaseVBO);
		// fill buffer
		glBindBuffer(GL_ARRAY_BUFFER, vaseVBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vase), vase, GL_STATIC_DRAW);
		// link vertex attributes
		glBindVertexArray(vaseVAO);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}
	glBindVertexArray(vaseVAO);
	float ustep = 1.0f / uStepsNum;
	for (int i = 0; i < uStepsNum; i++) {
		shader.setFloat("uStep", ustep*i);
		glDrawArrays(GL_POINTS, 0, 1);
	}
	glBindVertexArray(0);
}

void renderScene(Model &ourModel, Shader &shader, Shader &shader2, Shader &shader3, Shader &shader4, Shader &shader5)
{
	shader.use();
	// floor
	glm::mat4 model;
	shader.setMat4("model", model);
	renderPlane();
	// top
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(0.0f, 9.0f, 0.0f));
	model = glm::rotate(model, glm::radians(180.0f), glm::normalize(glm::vec3(1.0, 0.0, 0.0)));
	shader.setMat4("model", model);
	renderPlane();

	// column
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(0.0f, 4.0f, 12.0));
	shader.setMat4("model", model);
	renderColumn();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(0.0f, 4.0f, -12.0));
	shader.setMat4("model", model);
	renderColumn();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(12.0f, 4.0f, 12.0));
	shader.setMat4("model", model);
	renderColumn();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(12.0f, 4.0f, -12.0));
	shader.setMat4("model", model);
	renderColumn();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(-12.0f, 4.0f, 12.0));
	shader.setMat4("model", model);
	renderColumn();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(-12.0f, 4.0f, -12.0));
	shader.setMat4("model", model);
	renderColumn();

	/*
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(-1.0f, 0.0f, 2.0));
	model = glm::rotate(model, glm::radians(60.0f), glm::normalize(glm::vec3(1.0, 0.0, 1.0)));
	model = glm::scale(model, glm::vec3(0.25));
	shader.setMat4("model", model);
	renderCube();*/
	
	shader2.use();
	//ball
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(-5.0f, 2.5f, 0.0));
	shader2.setMat4("model", model);
	renderBall(shader2,0.5f);

	shader3.use();
	//vase
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(0.0f, 2.0f, 0.0));
	shader3.setMat4("model", model);
	renderVase(shader3,0.5f);

	shader4.use();
	//table1
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(0.0f, 1.5f, 0.0f));
	model = glm::scale(model, glm::vec3(0.5));
	shader4.setMat4("model", model);
	renderBoard();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(0.0f, 0.5f, 0.0));
	model = glm::scale(model, glm::vec3(0.2));
	shader4.setMat4("model", model);
	renderColumn();

	//table2
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(-5.0f, 1.5f, 0.0f));
	model = glm::scale(model, glm::vec3(0.5));
	shader4.setMat4("model", model);
	renderBoard();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(-5.0f, 0.5f, 0.0));
	model = glm::scale(model, glm::vec3(0.2));
	shader4.setMat4("model", model);
	renderColumn();

	//table3
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(5.0f, 1.5f, 0.0f));
	model = glm::scale(model, glm::vec3(0.5));
	shader4.setMat4("model", model);
	renderBoard();
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(5.0f, 0.5f, 0.0));
	model = glm::scale(model, glm::vec3(0.2));
	shader4.setMat4("model", model);
	renderColumn();

	shader5.use();
	//dragon
	model = glm::mat4();
	model = glm::translate(model, glm::vec3(5.0f, 2.2f, 0.0));
	shader5.setMat4("model", model);
	ourModel.Draw(shader5);
}

int main()
{
	// glfw: initialize and configure
	// ------------------------------
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
#endif

	// glfw window creation
	// --------------------
	GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "myRoom", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetCursorPosCallback(window, mouse_callback);
	glfwSetScrollCallback(window, scroll_callback);

	// tell GLFW to capture our mouse
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	// glad: load all OpenGL function pointers
	// ---------------------------------------
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//==========================================================================

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	// build and compile shaders
	// -------------------------
	Shader skyboxShader("skybox.vs", "skybox.fs");
	Shader shader("shadow_mapping.vs", "shadow_mapping.fs");
	Shader simpleDepthShader("shadow_mapping_depth.vs", "shadow_mapping_depth.fs");
	Shader shader2("shadow_mapping_g.vs", "shadow_mapping_g.fs", "geometry_shader.gs");
	Shader simpleDepthShader2("shadow_mapping_depth_g.vs", "shadow_mapping_depth_g.fs", "geometry_shader_depth.gs");
	Shader shader3("shadow_mapping_g.vs", "shadow_mapping_g.fs", "geometry_shader2.gs");
	Shader simpleDepthShader3("shadow_mapping_depth_g.vs", "shadow_mapping_depth_g.fs", "geometry_shader_depth2.gs");
	Shader shader4("shadow_mapping.vs", "shadow_mapping.fs");
	Shader simpleDepthShader4("shadow_mapping_depth.vs", "shadow_mapping_depth.fs");
	Shader shader5("shadow_mapping.vs", "shadow_mapping_dragon.fs");
	Shader simpleDepthShader5("shadow_mapping_depth.vs", "shadow_mapping_depth.fs");

	// load models
	// -----------
	Model ourModel("resources/objects/dragon.obj");

	// skybox VAO
	unsigned int skyboxVAO, skyboxVBO;
	glGenVertexArrays(1, &skyboxVAO);
	glGenBuffers(1, &skyboxVBO);
	glBindVertexArray(skyboxVAO);
	glBindBuffer(GL_ARRAY_BUFFER, skyboxVBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	// configure depth map FBO
	// -----------------------
	const unsigned int SHADOW_WIDTH = 1024, SHADOW_HEIGHT = 1024;
	unsigned int depthMapFBO;
	glGenFramebuffers(1, &depthMapFBO);
	// create depth texture
	unsigned int depthMap;
	glGenTextures(1, &depthMap);
	glBindTexture(GL_TEXTURE_2D, depthMap);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, SHADOW_WIDTH, SHADOW_HEIGHT, 0, GL_DEPTH_COMPONENT, GL_FLOAT, NULL);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	float borderColor[] = { 1.0, 1.0, 1.0, 1.0 };
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
	// attach depth texture as FBO's depth buffer
	glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_ATTACHMENT, GL_TEXTURE_2D, depthMap, 0);
	glDrawBuffer(GL_NONE);
	glReadBuffer(GL_NONE);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);

	// load textures
	// -------------
	unsigned int cubeTexture = loadTexture("resources/textures/floor.jpg");
	unsigned int ballTexture = loadTexture("resources/textures/map.jpg");
	unsigned int woodTexture = loadTexture("resources/textures/timg.jpg");
	unsigned int vaseTexture = loadTexture("resources/textures/timg.jpg");
	unsigned int dragonTexture = loadTexture("resources/textures/dragon.jpg");

	vector<std::string> faces
	{
		"resources/textures/skybox/right.jpg",
		"resources/textures/skybox/left.jpg",
		"resources/textures/skybox/top.jpg",
		"resources/textures/skybox/bottom.jpg",
		"resources/textures/skybox/back.jpg",
		"resources/textures/skybox/front.jpg"
	};
	unsigned int cubemapTexture = loadCubemap(faces);

	// shader configuration
	// --------------------

	shader.use();
	shader.setInt("diffuseTexture", 0);
	shader.setInt("shadowMap", 5);
	shader2.use();
	shader2.setInt("diffuseTexture", 1);
	shader2.setInt("shadowMap", 5);
	shader3.use();
	shader3.setInt("diffuseTexture", 3);
	shader3.setInt("shadowMap", 5);
	shader4.use();
	shader4.setInt("diffuseTexture", 2);
	shader4.setInt("shadowMap", 5);
	shader5.use();
	shader5.setInt("diffuseTexture", 4);
	shader5.setInt("shadowMap", 5);
	skyboxShader.use();
	skyboxShader.setInt("skybox", 0);

	glm::vec3 lightPos;
	// render loop
	// -----------
	while (!glfwWindowShouldClose(window))
	{
		// per-frame time logic
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// input
		// -----
		processInput(window);

		// render
		// ------
		glClearColor(0.15f, 0.15f, 0.15f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// 1. render depth of scene to texture (from light's perspective)
		// --------------------------------------------------------------
		if(day)
			lightPos= glm::vec3(-20.0f, 10.0f, 0.0f);
		else
			lightPos = glm::vec3(0.0f, 8.0f, 0.0f);

		glm::mat4 lightProjection, lightView;
		glm::mat4 lightSpaceMatrix;
		float near_plane, far_plane;
		if (day) {
			near_plane = 1.0f, far_plane = 45.0f;
			lightProjection = glm::ortho(-20.0f, 20.0f, -20.0f, 20.0f, near_plane, far_plane);
			lightView = glm::lookAt(lightPos, glm::vec3(0.0f), glm::vec3(0.0, 1.0, 0.0));
		}
		else {
			near_plane = 1.0f, far_plane = 10.0f;
			lightProjection = glm::perspective(glm::radians(150.0f), (GLfloat)SHADOW_WIDTH / (GLfloat)SHADOW_HEIGHT, near_plane, far_plane);
			// note that if you use a perspective projection matrix you'll have to change the light position as the current light position isn't enough to reflect the whole scene
			lightView = glm::lookAt(lightPos, glm::vec3(0.0f), glm::vec3(0.0, 0.0, 1.0));
		}

		lightSpaceMatrix = lightProjection * lightView;
		// render scene from light's point of view
		simpleDepthShader.use();
		simpleDepthShader.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		simpleDepthShader2.use();
		simpleDepthShader2.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		simpleDepthShader3.use();
		simpleDepthShader3.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		simpleDepthShader4.use();
		simpleDepthShader4.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		simpleDepthShader5.use();
		simpleDepthShader5.setMat4("lightSpaceMatrix", lightSpaceMatrix);

		glViewport(0, 0, SHADOW_WIDTH, SHADOW_HEIGHT);
		glBindFramebuffer(GL_FRAMEBUFFER, depthMapFBO);
		glClear(GL_DEPTH_BUFFER_BIT);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, cubeTexture);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, ballTexture);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, woodTexture);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, vaseTexture);
		glActiveTexture(GL_TEXTURE4);
		glBindTexture(GL_TEXTURE_2D, dragonTexture);
		renderScene(ourModel,simpleDepthShader, simpleDepthShader2, simpleDepthShader3, simpleDepthShader4,simpleDepthShader5);
		glBindFramebuffer(GL_FRAMEBUFFER, 0);

		// reset viewport
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// 2. render scene as normal using the generated depth/shadow map  
		// --------------------------------------------------------------
		glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();
		shader.use();
		shader.setMat4("projection", projection);
		shader.setMat4("view", view);
		shader.setVec3("viewPos", camera.Position);
		shader.setVec3("lightPos", lightPos);
		shader.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		shader2.use();
		shader2.setMat4("projection", projection);
		shader2.setMat4("view", view);
		shader2.setVec3("viewPos", camera.Position);
		shader2.setVec3("lightPos", lightPos);
		shader2.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		shader3.use();
		shader3.setMat4("projection", projection);
		shader3.setMat4("view", view);
		shader3.setVec3("viewPos", camera.Position);
		shader3.setVec3("lightPos", lightPos);
		shader3.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		shader4.use();
		shader4.setMat4("projection", projection);
		shader4.setMat4("view", view);
		shader4.setVec3("viewPos", camera.Position);
		shader4.setVec3("lightPos", lightPos);
		shader4.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		shader5.use();
		shader5.setMat4("projection", projection);
		shader5.setMat4("view", view);
		shader5.setVec3("viewPos", camera.Position);
		shader5.setVec3("lightPos", lightPos);
		shader5.setMat4("lightSpaceMatrix", lightSpaceMatrix);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, cubeTexture);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, ballTexture);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, woodTexture);
		glActiveTexture(GL_TEXTURE3);
		glBindTexture(GL_TEXTURE_2D, vaseTexture);
		glActiveTexture(GL_TEXTURE4);
		glBindTexture(GL_TEXTURE_2D, dragonTexture);
		glActiveTexture(GL_TEXTURE5);
		glBindTexture(GL_TEXTURE_2D, depthMap);
		renderScene(ourModel,shader, shader2, shader3, shader4, shader5);

		if (day) {
			// draw skybox as last
			glDepthFunc(GL_LEQUAL);  // change depth function so depth test passes when values are equal to depth buffer's content
			skyboxShader.use();
			view = glm::mat4(glm::mat3(camera.GetViewMatrix())); // remove translation from the view matrix
			skyboxShader.setMat4("view", view);
			skyboxShader.setMat4("projection", projection);
			// skybox cube
			glBindVertexArray(skyboxVAO);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_CUBE_MAP, cubemapTexture);
			glDrawArrays(GL_TRIANGLES, 0, 36);
			glBindVertexArray(0);
			glDepthFunc(GL_LESS); // set depth function back to default
		}

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(window);
		glfwPollEvents();
	}



	glfwTerminate();
	return 0;
}
//==========================================================================

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.ProcessKeyboard(RIGHT, deltaTime);

	if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
		day = !day;
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	// make sure the viewport matches the new window dimensions; note that width and 
	// height will be significantly larger than specified on retina displays.
	glViewport(0, 0, width, height);
}

// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
void mouse_callback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;

	camera.ProcessMouseMovement(xoffset, yoffset);
}

// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.ProcessMouseScroll(yoffset);
}

// utility function for loading a 2D texture from file
// ---------------------------------------------------
unsigned int loadTexture(char const * path)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);

	int width, height, nrComponents;
	unsigned char *data = stbi_load(path, &width, &height, &nrComponents, 0);
	if (data)
	{
		GLenum format;
		if (nrComponents == 1)
			format = GL_RED;
		else if (nrComponents == 3)
			format = GL_RGB;
		else if (nrComponents == 4)
			format = GL_RGBA;

		glBindTexture(GL_TEXTURE_2D, textureID);
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Texture failed to load at path: " << path << std::endl;
		stbi_image_free(data);
	}

	return textureID;
}

// loads a cubemap texture from 6 individual texture faces
// order:
// +X (right)
// -X (left)
// +Y (top)
// -Y (bottom)
// +Z (front) 
// -Z (back)
// -------------------------------------------------------
unsigned int loadCubemap(vector<std::string> faces)
{
	unsigned int textureID;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height, nrChannels;
	for (unsigned int i = 0; i < faces.size(); i++)
	{
		unsigned char *data = stbi_load(faces[i].c_str(), &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			stbi_image_free(data);
		}
		else
		{
			std::cout << "Cubemap texture failed to load at path: " << faces[i] << std::endl;
			stbi_image_free(data);
		}
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	return textureID;
}