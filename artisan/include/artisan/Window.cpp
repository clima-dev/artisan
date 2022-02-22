#include "Window.h"
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include <stdio.h>
#include "imgui_impl_opengl2.h"

namespace artisan {

    static void glfw_error_callback(int error, const char* description)
    {
        fprintf(stderr, "Glfw Error %d: %s\n", error, description);
    }

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
        // Setup window
        glfwSetErrorCallback(glfw_error_callback);
        if (!glfwInit())
            return 1;
        m_Window = glfwCreateWindow(1280, 720, this->m_Title, NULL, NULL);
        if (m_Window == NULL)
            return 1;
        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1); // Enable vsync

        // Setup Dear ImGui context
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
        //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows
        //io.ConfigViewportsNoAutoMerge = true;
        //io.ConfigViewportsNoTaskBarIcon = true;

        // Setup Dear ImGui style
        ImGui::StyleColorsDark();
        //ImGui::StyleColorsClassic();

        // When viewports are enabled we tweak WindowRounding/WindowBg so platform windows can look identical to regular ones.
        ImGuiStyle& style = ImGui::GetStyle();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 0.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }

        // Setup Platform/Renderer backends
        ImGui_ImplGlfw_InitForOpenGL(m_Window, true);
        ImGui_ImplOpenGL2_Init();

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