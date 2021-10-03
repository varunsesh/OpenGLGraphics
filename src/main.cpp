#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>
#include<string.h>

// Vertex Shader source code
// const char* vertexShaderSource = "#version 330 core\n"
// "layout (location = 0) in vec3 aPos;\n"
// "void main()\n"
// "{\n"
// "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
// "}\0";
// //Fragment Shader source code
// const char* fragmentShaderSource = "#version 330 core\n"
// "out vec4 FragColor;\n"
// "void main()\n"
// "{\n"
// "   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
// "}\n\0";

char *state ;
void setNewColor();
void processInput(GLFWwindow *window, float r, float g, float b);

int main(){
    state = new char (10);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(800, 800, "TestRender", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create window" << std::endl;
        glfwTerminate();
        return -1;
    }
   
    glfwMakeContextCurrent(window);
    gladLoadGL();
    glViewport(0,0,800,800);
    
    float r = 0.2f, g = 0.3f, b = 0.3f;
    strcpy(state,"green");
    setNewColor();
    

    int count = 0;
    
    //Rendering loop
    while(!glfwWindowShouldClose(window)){
        processInput(window, r, g, b);
        glfwSwapBuffers(window);    
        glfwPollEvents();
        count += 1;
    }


    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}



void setNewColor(){
    float r = 0.0f, g = 0.0f, b = 0.0f;
    if (strcmp(state, "green") == 0){
        r = 0.2f, g = 0.3f, b = 0.3f;
    }
    else if(strcmp(state, "blue") == 0){
        r = 0.0f, g = 0.0f, b = 0.5f;
    }
    glClearColor(r, g, b, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void processInput(GLFWwindow *window, float r=0.0f, float g=0.0f, float b = 0.5f)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS){
        glfwSetWindowShouldClose(window, true);
    }
    else if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
        if (strcmp(state, "green") == 0){
            strcpy(state, "blue");
        }
        else if (strcmp(state, "blue") == 0){
            strcpy(state, "green");
        }
        setNewColor();
        
    }
    
}
