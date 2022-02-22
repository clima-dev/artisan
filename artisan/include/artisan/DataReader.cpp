#include "DataReader.h"
#include "Shapes.h"
#include "GUI.h"
#include "imgui.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

void read_aeg_data(const char* name, artisan::Window* window) {
    //  file open

    std::ifstream fin(std::string("src/") + name);

    if (!fin) {
        std::cout << "no file found\n";
        return;
    }

    //  read file
    std::string line;
    while (!fin.eof()) {
        std::getline(fin, line);

        if (line.find("// ") == 0) {
            continue;
        }

        if (line.find("circle ") == 0) {
            std::stringstream ss(line.c_str() + 7);
            int x, y, radius;
            std::string col;

            ss >> x >> y >> radius >> col;

            draw_circle(x, y, radius, WHITE);
        }


        if (line.find("set_bg_col ") == 0) {
            std::stringstream ss(line.c_str() + 11);
            float r, g, b, a;

            ss >> r >> g >> b >> a;

            window->setBgColor({ r, g, b, a });
        }

        if (line.find("rec ") == 0) {
            std::stringstream ss(line.c_str() + 4);
            int x, y, w, h;
            std::string col;

            ss >> x >> y >> w >> h >> col;

            draw_rectangle(x, y, w, h, WHITE);
        }

        if (line.find("show_demo_win ") == 0) {
            std::stringstream ss(line.c_str() + 14);

            bool showDemo = true;

            ImGui::ShowDemoWindow(&showDemo);
        }
    }

    return;
}