#ifndef H_AW_GAMESTATESTORE
#define H_AW_GAMESTATESTORE

#include <unordered_map>
#include <string>
#include <memory>
#include "GameState.hpp"

namespace aw {
class GameStateStore {

public:

    GameStateStore () = delete; // static only
    ~GameStateStore () = delete;

    GameStateStore (GameStateStore&&) = delete;
    GameStateStore& operator = (GameStateStore&&) = delete;

    GameStateStore (const GameStateStore&) = delete;
    GameStateStore& operator = (const GameStateStore&) = delete;

    // state getters
    static bool stateExists (const std::string&);
    static std::shared_ptr<GameState> getState (const std::string&);

    // state setters
    template <typename TState, typename ...TArg>
    static std::shared_ptr<GameState> makeState (const std::string& key, TArg&&... args) {
        auto state = std::make_shared<TState>(std::forward<TArg>(args)...);
        if (registerState(key, state)) {
            return state;
        } else {
            return nullptr;
        }
    }
    static bool registerState (const std::string&, GameState*);
    static bool registerState (const std::string&, const std::shared_ptr<GameState>&);
    static void deleteState (const std::string&);

private:

    static std::unordered_map<std::string, std::shared_ptr<GameState>> m_stateMap;

};
}

#endif
