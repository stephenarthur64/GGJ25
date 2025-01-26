#pragma once

enum class GameState { MENU, GAMEPLAY, CUTSCENE_START, CUTSCENE_END };

static GameState m_state = GameState::MENU;
