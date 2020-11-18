#ifndef POINTS_H
#define POINTS_H

float skyboxVertices[] = {
	// positions          
	-1.0f,  1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f, -1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	1.0f, -1.0f, -1.0f,
	1.0f, -1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f,  1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,

	-1.0f, -1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f, -1.0f,  1.0f,
	-1.0f, -1.0f,  1.0f,

	-1.0f,  1.0f, -1.0f,
	1.0f,  1.0f, -1.0f,
	1.0f,  1.0f,  1.0f,
	1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f,  1.0f,
	-1.0f,  1.0f, -1.0f,

	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f,  1.0f,
	1.0f, -1.0f,  1.0f
};

float planeVertices[] = {
	// positions            // normals         // texcoords
	15.0f, -0.5f,  15.0f,  0.0f, 1.0f, 0.0f,  15.0f,  0.0f,
	-15.0f, -0.5f,  15.0f,  0.0f, 1.0f, 0.0f,   0.0f,  0.0f,
	-15.0f, -0.5f, -15.0f,  0.0f, 1.0f, 0.0f,   0.0f, 15.0f,

	15.0f, -0.5f,  15.0f,  0.0f, 1.0f, 0.0f,  15.0f,  0.0f,
	-15.0f, -0.5f, -15.0f,  0.0f, 1.0f, 0.0f,   0.0f, 15.0f,
	15.0f, -0.5f, -15.0f,  0.0f, 1.0f, 0.0f,  15.0f, 15.0f
};

float wall[] = {
	// back face
	-15.0f, -5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	15.0f,  5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 30.0f, 10.0f, // top-right
	15.0f, -5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 30.0f, 0.0f, // bottom-right         
	15.0f,  5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 30.0f, 10.0f, // top-right
	-15.0f, -5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	-15.0f,  5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 10.0f, // top-left
	// front face
	-15.0f, -5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	15.0f, -5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 30.0f, 0.0f, // bottom-right
	15.0f,  5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 30.0f, 10.0f, // top-right
	15.0f,  5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 30.0f, 10.0f, // top-right
	-15.0f,  5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 10.0f, // top-left
	-15.0f, -5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	// left face
	-15.0f,  5.0f,  1.0f, -1.0f,  0.0f,  0.0f, 30.0f, 0.0f, // top-right
	-15.0f,  5.0f, -1.0f, -1.0f,  0.0f,  0.0f, 30.0f, 10.0f, // top-left
	-15.0f, -5.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 10.0f, // bottom-left
	-15.0f, -5.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 10.0f, // bottom-left
	-15.0f, -5.0f,  1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-15.0f,  5.0f,  1.0f, -1.0f,  0.0f,  0.0f, 30.0f, 0.0f, // top-right
	// right face
	15.0f,  5.0f,  1.0f,  1.0f,  0.0f,  0.0f, 30.0f, 0.0f, // top-left
	15.0f, -5.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 10.0f, // bottom-right
	15.0f,  5.0f, -1.0f,  1.0f,  0.0f,  0.0f, 30.0f, 10.0f, // top-right         
	15.0f, -5.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 10.0f, // bottom-right
	15.0f,  5.0f,  1.0f,  1.0f,  0.0f,  0.0f, 30.0f, 0.0f, // top-left
	15.0f, -5.0f,  1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-left     
	// bottom face
	-15.0f, -5.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 10.0f, // top-right
	15.0f, -5.0f, -1.0f,  0.0f, -1.0f,  0.0f, 30.0f, 10.0f, // top-left
	15.0f, -5.0f,  1.0f,  0.0f, -1.0f,  0.0f, 30.0f, 0.0f, // bottom-left
	15.0f, -5.0f,  1.0f,  0.0f, -1.0f,  0.0f, 30.0f, 0.0f, // bottom-left
	-15.0f, -5.0f,  1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-15.0f, -5.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 10.0f, // top-right
	// top face
	-15.0f,  5.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 10.0f, // top-left
	15.0f,  5.0f , 1.0f,  0.0f,  1.0f,  0.0f, 30.0f, 0.0f, // bottom-right
	15.0f,  5.0f, -1.0f,  0.0f,  1.0f,  0.0f, 30.0f, 10.0f, // top-right     
	15.0f,  5.0f,  1.0f,  0.0f,  1.0f,  0.0f, 30.0f, 0.0f, // bottom-right
	-15.0f,  5.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 10.0f, // top-left
	-15.0f,  5.0f,  1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f  // bottom-left        
};

float board[] = {
	// back face
	-2.0f, -0.5f, -2.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	2.0f,  0.5f, -2.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
	2.0f, -0.5f, -2.0f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f, // bottom-right         
	2.0f,  0.5f, -2.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
	-2.0f, -0.5f, -2.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	-2.0f,  0.5f, -2.0f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f, // top-left
	// front face
	-2.0f, -0.5f,  2.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	2.0f, -0.5f,  2.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f, // bottom-right
	2.0f,  0.5f,  2.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
	2.0f,  0.5f,  2.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
	-2.0f,  0.5f,  2.0f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f, // top-left
	-2.0f, -0.5f,  2.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	// left face
	-2.0f,  0.5f,  2.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
	-2.0f,  0.5f, -2.0f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-left
	-2.0f, -0.5f, -2.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
	-2.0f, -0.5f, -2.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
	-2.0f, -0.5f,  2.0f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-2.0f,  0.5f,  2.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
	// right face
	2.0f,  0.5f,  2.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
	2.0f, -0.5f, -2.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
	2.0f,  0.5f, -2.0f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-right         
	2.0f, -0.5f, -2.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
	2.0f,  0.5f,  2.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
	2.0f, -0.5f,  2.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-left     
	// bottom face
	-2.0f, -0.5f, -2.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
	2.0f, -0.5f, -2.0f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // top-left
	2.0f, -0.5f,  2.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
	2.0f, -0.5f,  2.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
	-2.0f, -0.5f,  2.0f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-2.0f, -0.5f, -2.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
	// top face
	-2.0f,  0.5f, -2.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
	2.0f,  0.5f , 2.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
	2.0f,  0.5f, -2.0f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f, // top-right     
	2.0f,  0.5f,  2.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
	-2.0f,  0.5f, -2.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
	-2.0f,  0.5f,  2.0f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f  // bottom-left        
};

float Cubevertices[] = {
	// back face
	-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
	1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 0.0f, // bottom-right         
	1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 1.0f, 1.0f, // top-right
	-1.0f, -1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	-1.0f,  1.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 1.0f, // top-left
	// front face
	-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 0.0f, // bottom-right
	1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
	1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f, 1.0f, // top-right
	-1.0f,  1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 1.0f, // top-left
	-1.0f, -1.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	// left face
	-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
	-1.0f,  1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-left
	-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
	-1.0f, -1.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-left
	-1.0f, -1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-1.0f,  1.0f,  1.0f, -1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-right
	// right face
	1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
	1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
	1.0f,  1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 1.0f, // top-right         
	1.0f, -1.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 1.0f, // bottom-right
	1.0f,  1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 1.0f, 0.0f, // top-left
	1.0f, -1.0f,  1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-left     
	// bottom face
	-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
	1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // top-left
	1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
	1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
	-1.0f, -1.0f,  1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-1.0f, -1.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
	// top face
	-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
	1.0f,  1.0f , 1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
	1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f, // top-right     
	1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
	-1.0f,  1.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
	-1.0f,  1.0f,  1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f  // bottom-left        
};

float column[] = {
	// back face
	-1.0f, -5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	1.0f,  5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 2.0f, 10.0f, // top-right
	1.0f, -5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 2.0f, 0.0f, // bottom-right         
	1.0f,  5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 2.0f, 10.0f, // top-right
	-1.0f, -5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 0.0f, // bottom-left
	-1.0f,  5.0f, -1.0f,  0.0f,  0.0f, -1.0f, 0.0f, 10.0f, // top-left
	// front face
	-1.0f, -5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	1.0f, -5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 2.0f, 0.0f, // bottom-right
	1.0f,  5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 2.0f, 10.0f, // top-right
	1.0f,  5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 2.0f, 10.0f, // top-right
	-1.0f,  5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 10.0f, // top-left
	-1.0f, -5.0f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f, 0.0f, // bottom-left
	// left face
	-1.0f,  5.0f,  1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 10.0f, // top-right
	-1.0f,  5.0f, -1.0f, -1.0f,  0.0f,  0.0f, 2.0f, 10.0f, // top-left
	-1.0f, -5.0f, -1.0f, -1.0f,  0.0f,  0.0f, 2.0f, 0.0f, // bottom-left
	-1.0f, -5.0f, -1.0f, -1.0f,  0.0f,  0.0f, 0.0f, 10.0f, // bottom-left
	-1.0f, -5.0f,  1.0f, -1.0f,  0.0f,  0.0f, 2.0f, 10.0f, // bottom-right
	-1.0f,  5.0f,  1.0f, -1.0f,  0.0f,  0.0f, 2.0f, 0.0f, // top-right
	// right face
	1.0f,  5.0f,  1.0f,  1.0f,  0.0f,  0.0f, 2.0f, 0.0f, // top-left
	1.0f, -5.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 10.0f, // bottom-right
	1.0f,  5.0f, -1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // top-right         
	1.0f, -5.0f, -1.0f,  1.0f,  0.0f,  0.0f, 2.0f, 0.0f, // bottom-right
	1.0f,  5.0f,  1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 10.0f, // top-left
	1.0f, -5.0f,  1.0f,  1.0f,  0.0f,  0.0f, 0.0f, 0.0f, // bottom-left     
	// bottom face
	-1.0f, -5.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
	1.0f, -5.0f, -1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 1.0f, // top-left
	1.0f, -5.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
	1.0f, -5.0f,  1.0f,  0.0f, -1.0f,  0.0f, 1.0f, 0.0f, // bottom-left
	-1.0f, -5.0f,  1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 0.0f, // bottom-right
	-1.0f, -5.0f, -1.0f,  0.0f, -1.0f,  0.0f, 0.0f, 1.0f, // top-right
	// top face
	-1.0f,  5.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
	1.0f,  5.0f , 1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
	1.0f,  5.0f, -1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 1.0f, // top-right     
	1.0f,  5.0f,  1.0f,  0.0f,  1.0f,  0.0f, 1.0f, 0.0f, // bottom-right
	-1.0f,  5.0f, -1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 1.0f, // top-left
	-1.0f,  5.0f,  1.0f,  0.0f,  1.0f,  0.0f, 0.0f, 0.0f  // bottom-left        
};

float ball[] = {
	0.0f, 0.0f, 0.0f
};

float vase[] = {
	0.0f, 0.0f, 0.0f
};

#endif
