#pragma once

#ifdef _WIN32
#define GLFW_EXPOSE_NATIVE_WIN32
#elif __linux__
#ifndef MUZZLE_FORCE_WAYLAND
#define GLFW_EXPOSE_NATIVE_X11
#else
#define GLFW_EXPOSE_NATIVE_WAYLAND
#endif
#elif __APPLE__
#define GLFW_EXPOSE_NATIVE_COCOA
#endif

#include "../deps/cute_sound.h"
#include <cstdio>
#include "Window.h"
#include <GLFW/glfw3native.h>

#define DEFAULT_PLAY_FREQUENCY_HZ 44100
#define DEFAULT_BUFFERED_SAMPLES 15
#define DEFAULT_PLAYING_POOL 5

typedef cs_context_t audio_context;
typedef struct audio
{
    cs_loaded_sound_t loaded;
    cs_playing_sound_t sound;
} audio;

audio_context* initialize_audio_context(artisan::Window window, unsigned play_freq_hz, int buffered_samples, int playing_pool_count);


audio load_audio_wav(const char* filepath);
void play_audio(audio_context* ctx, audio* sound);

void mix_audio_context(audio_context* ctx);
void spawn_mix_thread(audio_context* ctx);

void unload_audio(audio* sound);
void unload_audio_context(audio_context* ctx);