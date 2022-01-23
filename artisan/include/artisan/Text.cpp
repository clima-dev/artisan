#include "Text.h"


Font load_font(const char* filepath, const char* name)
{
    FONScontext* context = glfonsCreate(512, 512, FONS_ZERO_TOPLEFT);
    int fn = fonsAddFont(context, name, filepath);

    if (fn == -1) {
        std::cerr << "Failed to load font\n";
    }

    return Font { fn, context };
}

void draw_text(Font font_used, const char* text, float x, float y, float font_size, color color_drawn)
{
    unsigned int col = glfonsRGBA(color_drawn.r, color_drawn.g, color_drawn.b, color_drawn.a);

    fonsClearState(font_used.context);
    fonsSetFont(font_used.context, font_used.fn);

    fonsSetSize(font_used.context, font_size);
    fonsSetColor(font_used.context, col);
    fonsDrawText(font_used.context, x, y + font_size - 6, text, NULL);
}