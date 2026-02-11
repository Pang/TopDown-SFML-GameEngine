cmake_minimum_required(VERSION 3.28)
project(TopDownRpg-SFML LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.1
    GIT_SHALLOW ON
)

FetchContent_MakeAvailable(SFML)

add_executable(TopDownRpg-SFML
    main.cpp
    Camera/Camera.cpp
    Game/Game.cpp
    Npc/Npc.cpp
    Player/Player.cpp
    TileMap/TileMap.cpp
    World/World.cpp
    Helpers/Helper.cpp
    Helpers/Button.cpp
)

target_link_libraries(TopDownRpg-SFML PRIVATE SFML::Graphics)

add_custom_command(TARGET TopDownRpg-SFML POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/Assets
        $<TARGET_FILE_DIR:TopDownRpg-SFML>/Assets
)
