/**
 * Copyright (C) 2019 WerWolv
 * 
 * This file is part of EdiZon.
 * 
 * EdiZon is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * EdiZon is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with EdiZon.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <memory>
#include <vector>
#include <chrono>
#include <thread>

#include "overlay/screen.hpp"
#include "overlay/elements/element.hpp"

#include "helpers/utils.hpp"

namespace edz::ovl::gui {

    using Element = element::Element;

    class Gui {
    public:
        Gui();
        virtual ~Gui();

        static void init(Screen *screen);
        static void exit();

        virtual bool shouldClose();

        virtual Element* createUI() = 0;
        virtual void update() = 0;

        static void tick();
        static void hidUpdate(s64 keysDown, s64 keysHeld, JoystickPosition joyStickPosLeft, JoystickPosition joyStickPosRight, u32 touchX, u32 touchY);

        static void setGuiOpacity(float opacity);

        static void playIntroAnimation();


        template<typename T>
        static void changeTo()   {  Gui::s_nextGui = new T(); }

        static Gui* getCurrGui() {  return Gui::s_currGui;    }

        static void requestFocus(Element *element, FocusDirection direction);
        static void removeFocus(Element *element = nullptr);

        static bool isFocused(Element *element) { return Gui::s_focusedElement == element; }

    private:
        static inline Screen *s_screen = nullptr;
        static inline Gui *s_currGui = nullptr;
        static inline Gui *s_nextGui = nullptr;
        static inline Element *s_topElement = nullptr;
        static inline Element *s_focusedElement = nullptr;

        static inline float s_guiOpacity = 0.0;

        static inline bool s_introAnimationPlaying = true;
        static inline bool s_outroAnimationPlaying = true;

        static inline std::chrono::duration<int, std::nano> s_lastFrameDuration = 0s;

    };

}