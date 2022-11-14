// Copyright 2019-2022 the openage authors. See copying.md for legal info.

#pragma once

#include <memory>
#include <vector>

#include "util/path.h"

namespace qtgui {
class GuiApplication;
}

namespace openage {

namespace renderer {
class RenderPass;
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
	static std::shared_ptr<qtgui::GuiApplication> init_window_system();

protected:
	/**
	 * Initialize all graphics subsystems of the presenter, i.e.
	 *     - window creation
	 *     - main renderer
	 *     - component renderers (Terrain, Game Entities, GUI)
	 */
	void init_graphics();
	// void init_audio();

	/**
	 * Render all configured render passes in sequence.
	 */
	void render();

	// TODO: remove and move into our config/settings system
	util::Path root_dir;

	// graphics
	std::shared_ptr<qtgui::GuiApplication> gui_app;
	std::shared_ptr<renderer::Window> window;
	std::shared_ptr<renderer::Renderer> renderer;
	std::shared_ptr<renderer::gui::GUI> gui;
	std::vector<std::shared_ptr<renderer::RenderPass>> render_passes;
};

} // namespace presenter
} // namespace openage
