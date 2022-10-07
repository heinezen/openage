// Copyright 2019-2020 the openage authors. See copying.md for legal info.

#pragma once

#include "util/path.h"

namespace qtsdl {
class GuiApplication;
}

namespace openage {

namespace engine {
class Engine;
}

namespace renderer {
class Renderer;
class Window;

namespace gui {
class GUI;
}

} // namespace renderer

namespace presenter {

class Presenter {
public:
	Presenter(const util::Path &path);

	/**
	 * Start the presenter and initialize subsystems.
	 *
	 */
	void run();

	/**
	 * Initialize the Qt application managing the graphical views. Required
	 * for creating windows.
	 *
	 * @returns Pointer to openage's application wrapper,
	 */
	static std::shared_ptr<qtsdl::GuiApplication> init_window_system();

protected:
	// TODO: remove and move into our config/settings system
	util::Path root_dir;

	std::shared_ptr<qtsdl::GuiApplication> gui_app;
	std::shared_ptr<renderer::gui::GUI> gui;
	std::shared_ptr<renderer::Window> window;
	std::shared_ptr<renderer::Renderer> renderer;

	// TODO: Activate
	std::shared_ptr<engine::Engine> engine = nullptr;
};

} // namespace presenter
} // namespace openage