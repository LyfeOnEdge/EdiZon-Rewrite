/**
 * Copyright (C) 2020 WerWolv
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

#include "overlay/elements/list_item.hpp"

namespace edz::ovl::element {

    ListItem::ListItem(std::string text) : m_text(text) {

    }

    ListItem::~ListItem() {

    }


    Element* ListItem::requestFocus(Element *oldFocus, FocusDirection direction) {
        return this->getParent();
    }

    void ListItem::draw(ovl::Screen *screen, u16 x1, u16 y1) {
        const auto [x, y] = this->getPosition();
        const auto [w, h] = this->getSize();

        screen->drawRect(x, y, w, 1, { 0x5, 0x5, 0x5, 0xF });
        screen->drawRect(x, y + h - 1, w, 1, { 0x5, 0x5, 0x5, 0xF });

        screen->drawString(this->m_text.c_str(), false, x + 20, y + 45, 25, { 0xF, 0xF, 0xF, 0xF });
    }

    void ListItem::layout() {
        this->setSize(FB_WIDTH - 80, 72);
    }

}