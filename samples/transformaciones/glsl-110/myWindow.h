#pragma once

#include "glutWindow.h"
#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 

#include <vector>

class myWindow : public cwc::glutWindow
{
public:
	myWindow();

	virtual void OnRender(void);
	virtual void OnIdle();

	// When OnInit is called, a render context (in this case GLUT-Window) 
	// is already available!
	virtual void OnInit();

	virtual void OnResize(int w, int h);
	virtual void OnClose(void);
	virtual void OnMouseDown(int button, int x, int y);
	virtual void OnMouseUp(int button, int x, int y);
	virtual void OnMouseWheel(int nWheelNumber, int nDirection, int x, int y);

	virtual void OnKeyDown(int nKey, char cAscii);

	virtual void OnKeyUp(int nKey, char cAscii);

    	// Scene functions
    	void renderArm(glm::mat4 model_matrix);

private:

    void changeObjectColor(float r, float g, float b);

    void createSpiralSphere(const float radius, const unsigned int loops, const unsigned int segmentsPerLoop);
    void createGrid(int size);
    void createCube();

    void renderSpiralSphere(glm::mat4 model_matrix);
    void renderGrid(glm::mat4 model_matrix);
    void renderCube(glm::mat4 model_matrix);

    glm::mat4 view_matrix;

    // Sphere
    GLfloat* sphere_vertex_buffer;
    GLuint* sphere_index_buffer;
    std::vector<float> vertex_buffer;
    std::vector<unsigned int> index_buffer;
    
    // Cube
    GLfloat* cube_vertex_buffer;
    GLfloat* cube_normal_buffer;
    GLuint* cube_index_buffer;
    unsigned int cube_vertex_buffer_size;
    unsigned int cube_normal_buffer_size;
    unsigned int cube_index_buffer_size;
    
    // Grid 
    GLfloat* grid_vertex_buffer;
    unsigned int grid_vertex_buffer_size;
    GLuint* grid_index_buffer;
    unsigned int grid_index_buffer_size;

    GLuint programHandle;
    GLuint vertShader;
    GLuint fragShader;
};
