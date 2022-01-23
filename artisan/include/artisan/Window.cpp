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

        glfwSwapInterval(1);

        // TODO: USE FRAMEBUFFER FOR VIEWPORT
        glViewport(0, 0, this->m_Width, this->m_Height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // quickly clear the screen with white

        glEnable(GL_BLEND); // transparency
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, this->m_Width, this->m_Height, 0, 0, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        return true;
    };

    void Window::setBgColor(RGBColor col)
    {
        this->clampedBGCol = { col.r / 255.0f, col.g / 255.0f, col.b / 255.0f, col.alpha };
    }
}