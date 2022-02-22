#include "Draw.h"
#include "imgui_impl_glfw.h"

void begin_drawing()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void end_drawing(artisan::Window window)
{
	glfwSwapBuffers(window.m_Window);
	glfwPollEvents();

	ImGuiIO& io = ImGui::GetIO();

	if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
	{
		GLFWwindow* backup_current_context = glfwGetCurrentContext();
		ImGui::UpdatePlatformWindows();
		ImGui::RenderPlatformWindowsDefault();
		glfwMakeContextCurrent(backup_current_context);
	}

	glFlush();	
	
}

void clear_bg(artisan::RGBColor color)
{
	glClearColor(color.r, color.g, color.b, color.alpha);

}