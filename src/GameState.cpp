#include "../include/GameState.hpp"

void GameState::clearWindow () {

    if (m_clearWindow) {
        Window::clear(m_clearColor);
    }

}

Controller& GameState::getController () {

    return m_controller;

}

void GameState::setController (Controller& controller) {

    m_controller = controller;

}

void GameState::clearController () {

    m_controller = Controller();

}