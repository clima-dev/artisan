#include "Window.h"

namespace artisan {

    Window::Window(int width, int height, const char* title) :
        m_Width(width),
        m_Height(height),
        m_Title(title)
    {
        if (!init())
        {
            glfwTerminate();
        }
    };

    bool Window::init()
    {
        if (!glfwInit())
        {
            std::cout << "ERROR: GLFW INIT FAIL. ABORT" << std::endl;
            return false;
        }

        m_Window = glfwCreateWindow(this->m_Width, this->m_Height, this->m_Title, NULL, NULL);

        if (!m_Window)
        {
            std::cout << "ERROR: WINDOW INIT FAIL. ABORT" << std::endl;
            return false;
        }

        glfwMakeContextCurrent(this->m_Window);
        glfwWindowHint(GLFW_RESIZABLE, false);

        glViewport(0, 0, m_Width, m_Height); glMatrixMode(GL_PROJECTION); glLoadIdentity(); glOrtho(0, 0, m_Width, m_Height, 0, 0); glMatrixMode(GL_MODELVIEW); glLoadIdentity();


        return true;
    };

    void Window::setBgColor(RGBColor col)
    {
        this->clampedBGCol = { col.r / 255.0f, col.g / 255.0f, col.b / 255.0f, col.alpha };
    }

    void Window::update()
    {
        glfwPollEvents();
        glfwGetFramebufferSize(this->m_Window, &this->m_Width, &this->m_Height);
        glViewport(0, 0, this->m_Width, this->m_Height);
        glfwSwapBuffers(this->m_Window);
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(clampedBGCol.r, clampedBGCol.g, clampedBGCol.b, clampedBGCol.alpha);

        glMatrixMode(GL_MODELVIEW);
        glPushMatrix();
    }
}