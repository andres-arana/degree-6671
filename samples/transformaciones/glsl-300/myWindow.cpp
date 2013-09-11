#include <GL/glew.h>
#include <GL/freeglut.h>

#include <glm/glm.hpp> 
#include <glm/gtc/matrix_transform.hpp> 
#include <glm/gtx/transform2.hpp> 
#include <glm/gtx/projection.hpp>

#include "myWindow.h"
   
#include <iostream>
#include <fstream>
#include <vector>

void myWindow::createCube()
{
    if (this->cube_vertex_buffer != NULL)
    {
        delete this->cube_vertex_buffer;
    }
    this->cube_vertex_buffer_size = 3*8;
    this->cube_vertex_buffer = new GLfloat[this->cube_vertex_buffer_size];
    
    
    if (this->cube_index_buffer != NULL)
    {
        delete this->cube_index_buffer;
    }
    this->cube_index_buffer_size = 4 * 6;
    this->cube_index_buffer = new GLuint[this->cube_index_buffer_size];

    this->cube_vertex_buffer[0] = 0.5f;
    this->cube_vertex_buffer[1] = 0.5f;
    this->cube_vertex_buffer[2] = -0.5f;

    this->cube_vertex_buffer[3] = 0.5f;
    this->cube_vertex_buffer[4] = -0.5f;
    this->cube_vertex_buffer[5] = -0.5f;

    this->cube_vertex_buffer[6] = -0.5f;
    this->cube_vertex_buffer[7] = -0.5f;
    this->cube_vertex_buffer[8] = -0.5f;

    this->cube_vertex_buffer[9] = -0.5f;
    this->cube_vertex_buffer[10] = 0.5f;
    this->cube_vertex_buffer[11] = -0.5f;

    this->cube_vertex_buffer[12] = 0.5f;
    this->cube_vertex_buffer[13] = 0.5f;
    this->cube_vertex_buffer[14] = 0.5f;

    this->cube_vertex_buffer[15] = 0.5f;
    this->cube_vertex_buffer[16] = -0.5f;
    this->cube_vertex_buffer[17] = 0.5f;

    this->cube_vertex_buffer[18] = -0.5f;
    this->cube_vertex_buffer[19] = -0.5f;
    this->cube_vertex_buffer[20] = 0.5f;

    this->cube_vertex_buffer[21] = -0.5f;
    this->cube_vertex_buffer[22] = 0.5f;
    this->cube_vertex_buffer[23] = 0.5f;

    this->cube_index_buffer[0] = 0;
    this->cube_index_buffer[1] = 3;
    this->cube_index_buffer[2] = 2;
    this->cube_index_buffer[3] = 1;
 
    this->cube_index_buffer[4] = 4;
    this->cube_index_buffer[5] = 5;
    this->cube_index_buffer[6] = 6;
    this->cube_index_buffer[7] = 7;
    
    this->cube_index_buffer[8] = 0;
    this->cube_index_buffer[6] = 1;
    this->cube_index_buffer[7] = 5;
    this->cube_index_buffer[8] = 4;

    this->cube_index_buffer[8] = 1;
    this->cube_index_buffer[6] = 2;
    this->cube_index_buffer[7] = 6;
    this->cube_index_buffer[8] = 5;

    this->cube_index_buffer[8] = 2;
    this->cube_index_buffer[6] = 3;
    this->cube_index_buffer[7] = 7;
    this->cube_index_buffer[8] = 6;

    this->cube_index_buffer[8] = 3;
    this->cube_index_buffer[6] = 0;
    this->cube_index_buffer[7] = 4;
    this->cube_index_buffer[8] = 7;
}

void myWindow::createGrid(int size)
{
    if (this->grid_vertex_buffer != NULL)
    {
        delete this->grid_vertex_buffer;
    }
    this->grid_vertex_buffer_size = 12*(2*size +1);
    this->grid_vertex_buffer = new GLfloat[this->grid_vertex_buffer_size];
    
    
    if (this->grid_index_buffer != NULL)
    {
        delete this->grid_index_buffer;
    }
    this->grid_index_buffer_size = 4*(2*size +1);
    this->grid_index_buffer = new GLuint[this->grid_index_buffer_size];

    int offset;
    for (int i=0; i<size; i++)
    {
        offset = 24*i;
        this->grid_vertex_buffer[offset++] = -size;
        this->grid_vertex_buffer[offset++] = i+1;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = size;
        this->grid_vertex_buffer[offset++] = i+1;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = -size;
        this->grid_vertex_buffer[offset++] = -(i+1);
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = size;
        this->grid_vertex_buffer[offset++] = -(i+1);
        this->grid_vertex_buffer[offset++] = 0;


        this->grid_vertex_buffer[offset++] = i+1;
        this->grid_vertex_buffer[offset++] = -size;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = i+1;
        this->grid_vertex_buffer[offset++] = size;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = -(i+1);
        this->grid_vertex_buffer[offset++] = -size;
        this->grid_vertex_buffer[offset++] = 0;

        this->grid_vertex_buffer[offset++] = -(i+1);
        this->grid_vertex_buffer[offset++] = size;
        this->grid_vertex_buffer[offset++] = 0;
    }

    offset = 24 * size;
    this->grid_vertex_buffer[offset++]   = -size;
    this->grid_vertex_buffer[offset++] = 0;
    this->grid_vertex_buffer[offset++] = 0;

    this->grid_vertex_buffer[offset++] = size;
    this->grid_vertex_buffer[offset++] = 0;
    this->grid_vertex_buffer[offset++] = 0;

    this->grid_vertex_buffer[offset++] = 0;
    this->grid_vertex_buffer[offset++] = -size;
    this->grid_vertex_buffer[offset++] = 0;

    this->grid_vertex_buffer[offset++] = 0;
    this->grid_vertex_buffer[offset++] = size;
    this->grid_vertex_buffer[offset++] = 0;

    for (int i=0; i< this->grid_index_buffer_size; i++)
    {
        this->grid_index_buffer[i] = i;
    }
}

void myWindow::renderGrid(glm::mat4 model_matrix)
{
    // Normal Matrix
    glm::mat3 normal_matrix = glm::mat3 ( 1.0f );
    
    // Bind Normal MAtrix
    GLuint location_normal_matrix = glGetUniformLocation( this->sphere_program_handle, "NormalMatrix"); 
    if( location_normal_matrix >= 0 ) 
	{ 
        glUniformMatrix3fv( location_normal_matrix, 1, GL_FALSE, &normal_matrix[0][0]); 
	}

    // Bind Model Matrix
    GLuint location_model_matrix = glGetUniformLocation( this->sphere_program_handle, "ModelMatrix"); 
    if( location_model_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_model_matrix, 1, GL_FALSE, &model_matrix[0][0]); 
	}

    changeObjectColor(0.5f, 1.0f, 0.5f);
    glBindVertexArray(this->grid_vao_handle);
    glDrawElements(GL_LINES, this->grid_index_buffer_size, GL_UNSIGNED_INT, this->grid_index_buffer);
}

void myWindow::createSpiralSphere(const float radius, const unsigned int loops, const unsigned int segmentsPerLoop)
{
 
    if (this->vertex_buffer.size() >0)
    {
        this->vertex_buffer.clear();
    }

    if (this->index_buffer.size() >0)
    {
        this->index_buffer.clear();
    }

    float PI = 3.1415f;

	for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
	{
		float theta = 0;
		float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
		float sinTheta = std::sin(theta);
		float sinPhi = std::sin(phi);
		float cosTheta = std::cos(theta);
		float cosPhi = std::cos(phi);

        // 
        this->vertex_buffer.push_back(radius * cosPhi * sinTheta); // Vx
        this->vertex_buffer.push_back(radius * sinPhi * sinTheta); // Vy
        this->vertex_buffer.push_back(radius * cosTheta);          // Vz
	}
	for (unsigned int loopNumber = 0; loopNumber <= loops; ++loopNumber)
	{
		for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
		{
			float theta = (loopNumber * PI / loops) + ((PI * loopSegmentNumber) / (segmentsPerLoop * loops));
			if (loopNumber == loops)
			{
				theta = PI;
			}
			float phi = loopSegmentNumber * 2 * PI / segmentsPerLoop;
			float sinTheta = std::sin(theta);
			float sinPhi = std::sin(phi);
			float cosTheta = std::cos(theta);
			float cosPhi = std::cos(phi);

            this->vertex_buffer.push_back(radius * cosPhi * sinTheta);
            this->vertex_buffer.push_back(radius * sinPhi * sinTheta);
            this->vertex_buffer.push_back(radius * cosTheta);
		}
	}
	for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
	{
		this->index_buffer.push_back(loopSegmentNumber);
		this->index_buffer.push_back(segmentsPerLoop + loopSegmentNumber);
	}
	for (unsigned int loopNumber = 0; loopNumber < loops; ++loopNumber)
	{
		for (unsigned int loopSegmentNumber = 0; loopSegmentNumber < segmentsPerLoop; ++loopSegmentNumber)
		{
			this->index_buffer.push_back(((loopNumber + 1) * segmentsPerLoop) + loopSegmentNumber);
			this->index_buffer.push_back(((loopNumber + 2) * segmentsPerLoop) + loopSegmentNumber);
		}
	}

    //
    if (this->sphere_vertex_buffer != NULL)
    {
        delete[] this->sphere_vertex_buffer;
    }
    this->sphere_vertex_buffer = new float[this->vertex_buffer.size()];
    
    if ( this->sphere_index_buffer != NULL)
    {
        delete[] this->sphere_index_buffer;
    }
    this->sphere_index_buffer = new unsigned int[this->index_buffer.size()];

    std::vector<float>::iterator vertex_it;
    unsigned int v = 0;
    for (vertex_it = this->vertex_buffer.begin(); vertex_it != this->vertex_buffer.end(); vertex_it++)
    {
        this->sphere_vertex_buffer[v] = *vertex_it;
        v++;
    }

    std::vector<unsigned int>::iterator index_it;
    unsigned int i = 0;
    for (index_it = this->index_buffer.begin(); index_it != this->index_buffer.end(); index_it++)
    {
        this->sphere_index_buffer[i] = *index_it;
        i++;
    }
}

void myWindow::setupSphereVAO()
{
    // Create and set-up the vertex array objet
    glGenVertexArrays( 1, &this->sphere_vao_handle );
    glBindVertexArray( this->sphere_vao_handle );

    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);
    GLuint positionBufferHandle = vboHandles[0];
    GLuint normalBufferHandle = vboHandles[1];

    glBindBuffer( GL_ARRAY_BUFFER, positionBufferHandle );
    glBufferData( GL_ARRAY_BUFFER, vertex_buffer.size() * sizeof (float), sphere_vertex_buffer, GL_STATIC_DRAW );

    glBindBuffer( GL_ARRAY_BUFFER, normalBufferHandle );
    glBufferData( GL_ARRAY_BUFFER, vertex_buffer.size() * sizeof (float), sphere_vertex_buffer, GL_STATIC_DRAW );

    // Enable the vertex attributes array
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);

    // Map index 0 to the position buffer
    glBindBuffer( GL_ARRAY_BUFFER, positionBufferHandle);
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL);

    // Map index 1 to the color buffer
    glBindBuffer( GL_ARRAY_BUFFER, normalBufferHandle);
    glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL);

    glBindVertexArray(0);
}

void myWindow::setupGridVAO()
{
    // Create and set-up the vertex array objet
    glGenVertexArrays( 1, &this->grid_vao_handle );
    glBindVertexArray( this->grid_vao_handle );

    GLuint vboHandles[2];
    glGenBuffers(2, vboHandles);
    GLuint positionBufferHandle = vboHandles[0];
    GLuint normalBufferHandle = vboHandles[1];

    glBindBuffer( GL_ARRAY_BUFFER, positionBufferHandle );
    glBufferData( GL_ARRAY_BUFFER, this->grid_vertex_buffer_size * sizeof (float), this->grid_vertex_buffer, GL_STATIC_DRAW );

    // glBindBuffer( GL_ARRAY_BUFFER, normalBufferHandle );
    // glBufferData( GL_ARRAY_BUFFER, vertex_buffer.size() * sizeof (float), sphere_vertex_buffer, GL_STATIC_DRAW );

    // Enable the vertex attributes array
    glEnableVertexAttribArray(0);
    // glEnableVertexAttribArray(1);

    // Map index 0 to the position buffer
    glBindBuffer( GL_ARRAY_BUFFER, positionBufferHandle);
    glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL);

    // Map index 1 to the color buffer
    // glBindBuffer( GL_ARRAY_BUFFER, normalBufferHandle);
    // glVertexAttribPointer( 1, 3, GL_FLOAT, GL_FALSE, 0, (GLubyte*)NULL);

    glBindVertexArray(0);
}

void myWindow::renderSpiralSphere(glm::mat4 model_matrix)
{
    // Normal Matrix
    glm::mat3 normal_matrix = glm::mat3 ( 1.0f );
    glm::mat4 aux = this->view_matrix * model_matrix;
    for (int i=0; i<3; i++)
        for (int j=0; j<3; j++)
            normal_matrix[i][j] = aux[i][j];

    // Bind Normal MAtrix
    GLuint location_normal_matrix = glGetUniformLocation( this->sphere_program_handle, "NormalMatrix"); 
    if( location_normal_matrix >= 0 ) 
	{ 
        glUniformMatrix3fv( location_normal_matrix, 1, GL_FALSE, &normal_matrix[0][0]); 
	}

    // Bind Model Matrix
    GLuint location_model_matrix = glGetUniformLocation( this->sphere_program_handle, "ModelMatrix"); 
    if( location_model_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_model_matrix, 1, GL_FALSE, &model_matrix[0][0]); 
	}


    glBindVertexArray(this->sphere_vao_handle);
    glDrawElements(GL_TRIANGLE_STRIP, index_buffer.size(), GL_UNSIGNED_INT, sphere_index_buffer);

}

const char* loadShaderAsString(const char* file)
{
    std::ifstream shader_file(file, std::ifstream::in);
    std::string str((std::istreambuf_iterator<char>(shader_file)), std::istreambuf_iterator<char>());
    return str.c_str();
}

myWindow::myWindow()
{
    this->sphere_vertex_buffer = NULL;
    this->sphere_index_buffer = NULL;
    this->grid_index_buffer = NULL;
    this->grid_vertex_buffer = NULL;
}

void myWindow::changeObjectColor(float r, float g, float b)
{
    glm::vec3 diffuse_reflectivity = glm::vec3( r, g, b );

    GLuint location_diffuse_reflectivity = glGetUniformLocation( this->sphere_program_handle, "Kd"); 
    if( location_diffuse_reflectivity >= 0 ) 
	{ 
		glUniform3fv( location_diffuse_reflectivity, 1, &diffuse_reflectivity[0]); 
	}
}

void myWindow::OnRender(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    /////////////////////////////////////////////////
    // View and Projection Matrices Setting for Scene
    
    // View (camera) Matrix
    this->view_matrix = glm::lookAt ( glm::vec3 ( 8.0, 0.0, 3.0 ),
                                      glm::vec3 ( 0.0, 0.0, 0.0 ),
                                      glm::vec3 ( 0.0, 0.0, 1.0 ) );

    // Projection Matrix
    glm::mat4 projection_matrix = glm::mat4 ( 1.0f );
    projection_matrix = glm::infinitePerspective( 52.0f , (float)this->width / (float)this->height, 0.1f);



    /////////////////////////////////////////////////
    // Sphere Program Setup
    
    glUseProgram( this->sphere_program_handle );

    // Bind View MAtrix
    GLuint location_view_matrix = glGetUniformLocation( this->sphere_program_handle, "ViewMatrix"); 
    if( location_view_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_view_matrix, 1, GL_FALSE, &view_matrix[0][0]); 
	}

    // Bind View MAtrix
    GLuint location_projection_matrix = glGetUniformLocation( this->sphere_program_handle, "ProjectionMatrix"); 
    if( location_projection_matrix >= 0 ) 
	{ 
		glUniformMatrix4fv( location_projection_matrix, 1, GL_FALSE, &projection_matrix[0][0]); 
	}
    
    // Bind Light Settings
    glm::vec4 light_position = glm::vec4( 0.0f, 1.0f, 1.0f, 1.0f );
    glm::vec3 light_intensity = glm::vec3( 1.0f, 1.0f, 1.0f );
       
    GLuint location_light_position = glGetUniformLocation( this->sphere_program_handle, "LightPosition"); 
    if( location_light_position >= 0 ) 
	{ 
        glUniform4fv( location_light_position, 1, &light_position[0]); 
	}

    GLuint location_light_intensity = glGetUniformLocation( this->sphere_program_handle, "Ld"); 
    if( location_light_intensity >= 0 ) 
	{ 
		glUniform3fv( location_light_intensity, 1, &light_intensity[0]); 
	}
    //
    ///////////////////////////////////////////

    // Drawwing Grid
    glm::mat4 model_matrix_grid = glm::mat4 ( 1.0f );
    this->renderGrid(model_matrix_grid);

    // SUN
    //
    // Model Matrix for Sun
    
    glm::mat4 model_matrix = glm::mat4 ( 1.0f );
    changeObjectColor(0.8, 0.8, 0.3);
    this->renderSpiralSphere(model_matrix);
   
	glutSwapBuffers();
}

void  myWindow::OnIdle()
{
	static int hora = 0, nroDia = 0;
	hora++;
	if (hora >= 24) {
		hora = 0;
		nroDia ++;
	}
	if (nroDia >= 365) {
		nroDia = 0;
	}

	// TODO / rotar
	translationAngle = 360 * nroDia / 365;
	rotationAngle = 360 * hora / 24;
	glutPostRedisplay();
}

// When OnInit is called, a render context (in this case GLUT-Window) 
// is already available!
void  myWindow::OnInit()
{
	rotationAngle = 0.0f;
	translationAngle = 0.0f;

    // Create Vertex Data in Memory
    this->createSpiralSphere(1.0, 32, 32);
    this->createGrid(5);
    
	glClearColor(0.3f, 0.3f, 0.4f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);

    this->setupSphereVAO();
    this->setupGridVAO();

	// ********************************************
    // Compiling the shader programms
    //*********************************************

	// Do your GLEW experiments here:
    if (GLEW_ARB_shading_language_100) 
    { 
        std::cout << "GLEW_ARB_shading_language_100" << std::endl;
        int major, minor, revision;
        const GLubyte* sVersion = glGetString(GL_SHADING_LANGUAGE_VERSION_ARB);
        if (glGetError() == GL_INVALID_ENUM)
        {
            major = 1; minor = 0; revision=51;
        }
        else
        {
            std::string version((char*)sVersion);
            std::cout << version.c_str() << std::endl;
        }

        // Load vertex Shader
        this->sphere_vert_shader = glCreateShader (GL_VERTEX_SHADER);
        if ( 0 == this->sphere_vert_shader )
        {
            std::cout << "Error creating vertex shader" << std::endl;
        }

        std::ifstream v_shader_file("DiffuseShadingVShader.vert", std::ifstream::in);
        std::string v_str((std::istreambuf_iterator<char>(v_shader_file)), std::istreambuf_iterator<char>());
        const char* vs_code_array[] = {v_str.c_str()};
        
        glShaderSource( this->sphere_vert_shader, 1, vs_code_array, NULL);

        // Compilar el shader
        glCompileShader( this->sphere_vert_shader );

        // verificar resultado de la compilacion
        GLint vs_compilation_result;
        glGetShaderiv( this->sphere_vert_shader, GL_COMPILE_STATUS, &vs_compilation_result );
        if( GL_FALSE == vs_compilation_result )
        {
            std::cout << "Vertex shader compilation failed!\n" << std::endl;
            GLint logLen;
            glGetShaderiv( this->sphere_vert_shader, GL_INFO_LOG_LENGTH, &logLen );
            if( logLen > 0 )
            {
                char * log = (char *)malloc(logLen);
                GLsizei written;
                glGetShaderInfoLog(sphere_vert_shader, logLen, &written, log);
                std::cout << "Shader log: " << log << std::endl;
                free(log);
            }
        }

         // Load fragment Shader
        this->sphere_frag_shader = glCreateShader (GL_FRAGMENT_SHADER);
        if ( 0 == this->sphere_frag_shader )
        {
            std::cout << "Error creating fragment shader" << std::endl;
        }

        std::ifstream f_shader_file("DiffuseShadingFShader.frag", std::ifstream::in);
        std::string f_str((std::istreambuf_iterator<char>(f_shader_file)), std::istreambuf_iterator<char>());
        const char* fs_code_array[] = {f_str.c_str()};
        
        glShaderSource( this->sphere_frag_shader, 1, fs_code_array, NULL);

        // Compilar el shader
        glCompileShader( this->sphere_frag_shader );

        // verificar resultado de la compilacion
        GLint fs_compilation_result;
        glGetShaderiv( this->sphere_frag_shader, GL_COMPILE_STATUS, &fs_compilation_result );
        if( GL_FALSE == fs_compilation_result )
        {
            std::cout << "Fragment shader compilation failed!\n" << std::endl;
            GLint logLen;
            glGetShaderiv( this->sphere_frag_shader, GL_INFO_LOG_LENGTH, &logLen );
            if( logLen > 0 )
            {
                char * log = (char *)malloc(logLen);
                GLsizei written;
                glGetShaderInfoLog( this->sphere_frag_shader, logLen, &written, log);
                std::cout << "Shader log: " << log << std::endl;
                free(log);
            }
        }
	// *******************************************

    // *******************************************
    // Linking the shader programms
    // *******************************************
        this->sphere_program_handle = glCreateProgram();
        if ( 0 == this->sphere_program_handle )
        {
            std::cout << "Error creating program object" << std::endl;
        }
        else
        {
            glAttachShader( this->sphere_program_handle, this->sphere_vert_shader );
            glAttachShader( this->sphere_program_handle, this->sphere_frag_shader );

            // *******************************************
            // Binding Input Data with input variables
            // *******************************************
        
            // Bind index 0 to the shader input variable "VertexPosition"
            glBindAttribLocation( this->sphere_program_handle, 0, "VertexPosition" );

            // Bind index 1 to the shader input variable "VertexColor"
            glBindAttribLocation( this->sphere_program_handle, 1, "VertexNormal" );

            // *******************************************

            glLinkProgram( this->sphere_program_handle );

            GLint status;
            glGetProgramiv( this->sphere_program_handle, GL_LINK_STATUS, &status );
            if( GL_FALSE == status )
            {
                std::cout << "Failed to link shader program!\n" << std::endl;
                GLint logLen;
                glGetProgramiv( this->sphere_program_handle, GL_INFO_LOG_LENGTH, &logLen);
                if( logLen > 0 )
                {
                    char * log = (char *)malloc(logLen);
                    GLsizei written;
                    glGetProgramInfoLog(sphere_program_handle, logLen, &written, log);
                    std::cout << "Program log: \n%s" << std::endl;
                    free(log);
                }
            }
        }
    }
}

void myWindow::OnResize(int w, int h) 
{
    glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
    this->width = w;
    this->height = h;
}

void  myWindow::OnClose(void)
{
}

void myWindow::OnMouseDown(int button, int x, int y)
{
}

void myWindow::OnMouseUp(int button, int x, int y)
{
}

void myWindow::OnMouseWheel(int nWheelNumber, int nDirection, int x, int y)
{
}

void myWindow::OnKeyDown(int nKey, char cAscii)
{       
	if (cAscii == 27) // 0x1b = ESC
	{
		this->Close(); // Close Window!
	} 
};

void myWindow::OnKeyUp(int nKey, char cAscii)
{
	if (cAscii == 'f')
	{
		SetFullscreen(true);
	}
	else if (cAscii == 'w')
	{
		SetFullscreen(false);
	}
};
