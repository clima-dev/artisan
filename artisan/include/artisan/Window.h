#pragma once

#include <GLFW/glfw3.h>
#include <iostream>
#include <string>
#define GLEW_STATIC
#include "RGBColor.h"

namespace artisan {
    class Window {
    public:
        Window(int width, int height, const char* title);

        bool closed() { return glfwWindowShouldClose(this->m_Window); };

		inline int KeyA() { return (glfwGetKey(m_Window, GLFW_KEY_A)); }
		inline int KeyB() { return (glfwGetKey(m_Window, GLFW_KEY_B)); }
		inline int KeyC() { return (glfwGetKey(m_Window, GLFW_KEY_C)); }
		inline int KeyD() { return (glfwGetKey(m_Window, GLFW_KEY_D)); }
		inline int KeyE() { return (glfwGetKey(m_Window, GLFW_KEY_E)); }
		inline int KeyF() { return (glfwGetKey(m_Window, GLFW_KEY_F)); }
		inline int KeyG() { return (glfwGetKey(m_Window, GLFW_KEY_G)); }
		inline int KeyH() { return (glfwGetKey(m_Window, GLFW_KEY_H)); }
		inline int KeyI() { return (glfwGetKey(m_Window, GLFW_KEY_I)); }
		inline int KeyJ() { return (glfwGetKey(m_Window, GLFW_KEY_J)); }
		inline int KeyK() { return (glfwGetKey(m_Window, GLFW_KEY_K)); }
		inline int KeyL() { return (glfwGetKey(m_Window, GLFW_KEY_L)); }
		inline int KeyM() { return (glfwGetKey(m_Window, GLFW_KEY_M)); }
		inline int KeyN() { return (glfwGetKey(m_Window, GLFW_KEY_N)); }
		inline int KeyO() { return (glfwGetKey(m_Window, GLFW_KEY_O)); }
		inline int KeyP() { return (glfwGetKey(m_Window, GLFW_KEY_P)); }
		inline int KeyQ() { return (glfwGetKey(m_Window, GLFW_KEY_Q)); }
		inline int KeyR() { return (glfwGetKey(m_Window, GLFW_KEY_R)); }
		inline int KeyS() { return (glfwGetKey(m_Window, GLFW_KEY_S)); }
		inline int KeyT() { return (glfwGetKey(m_Window, GLFW_KEY_T)); }
		inline int KeyU() { return (glfwGetKey(m_Window, GLFW_KEY_U)); }
		inline int KeyV() { return (glfwGetKey(m_Window, GLFW_KEY_V)); }
		inline int KeyW() { return (glfwGetKey(m_Window, GLFW_KEY_W)); }
		inline int KeyX() { return (glfwGetKey(m_Window, GLFW_KEY_X)); }
		inline int KeyY() { return (glfwGetKey(m_Window, GLFW_KEY_Y)); }
		inline int KeyZ() { return (glfwGetKey(m_Window, GLFW_KEY_Z)); }
		inline int KeyEsc() { return (glfwGetKey(m_Window, GLFW_KEY_ESCAPE)); }
		inline int KeySpace() { return (glfwGetKey(m_Window, GLFW_KEY_SPACE)); }

		void setBgColor(RGBColor color);
		RGBColor getBgColor() { return this->clampedBGCol; };
		GLFWwindow* m_Window;
        void update();

    private:
        
        int m_Width, m_Height;
		RGBColor clampedBGCol;
        const char* m_Title;
		
        bool init();
    };
}