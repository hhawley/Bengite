cmake_minimum_required(VERSION 2.8.4)
project(rlpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -std=c++11")
include_directories(include/Bengite)

if(ANDROID)
	#WIP
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPLATFORM_ANDROID")
	include_directories(dps_android/include)
	include_directories(${ANDROID_NDK}/sources/android/native_app_glue)
	link_directories(dps_android/libs)


	set(SOURCE_FILES ${ANDROID_NDK}/sources/android/native_app_glue/android_native_app_glue.c)
else()
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DPLATFORM_DESKTOP")
	set(SOURCE_FILES 
	src/Core/Input/Mouse.cpp)
endif()



set(SOURCE_FILES ${SOURCE_FILES}
#Core#
src/Core/Game.cpp
src/Core/GameTime.cpp
src/Core/Objects.cpp
src/Core/RNG.cpp

src/Core/Math/BMath.cpp

src/Core/Debugging/debug.cpp

src/Core/GameStateManager.cpp

src/Core/Input/Keyboard.cpp

src/Core/Components/Player.cpp
src/Core/Components/World.cpp
src/Core/Components/ComponentsManager.cpp

src/Core/Timers/CooldownTimer.cpp
src/Core/Timers/CountDown.cpp
src/Core/Timers/Timer.cpp

#Content#
src/Content/ContentManager.cpp

#Graphics#
src/Graphics/SpriteBatch.cpp
src/Graphics/DrawingManager.cpp

src/Graphics/Controls/Control.cpp
src/Graphics/Controls/ControlManager.cpp
src/Graphics/Controls/Button.cpp
src/Graphics/Controls/MaskedNumericIndicator.cpp
src/Graphics/Controls/NumericIndicator.cpp
src/Graphics/Controls/ProgressBar.cpp
src/Graphics/Controls/TextIndicator.cpp
src/Graphics/Controls/TextBox.cpp

src/Graphics/16bitTileEngine/Camera2D.cpp
src/Graphics/16bitTileEngine/Tile.cpp
src/Graphics/16bitTileEngine/TileSet.cpp
src/Graphics/16bitTileEngine/TileLayer.cpp
src/Graphics/16bitTileEngine/CollisionLayer.cpp
src/Graphics/16bitTileEngine/TopLayer.cpp
src/Graphics/16bitTileEngine/Chunk.cpp

src/Graphics/Animation/AnimatedSprite.cpp
src/Graphics/Animation/Animation.cpp

#Gameplay#
src/Gameplay/Interactuable.cpp
# src/Agriculture/BasePlant.cpp
# src/Agriculture/Ground.cpp

#Json#
src/json/jsoncpp.cpp
src/json/jsonStream.cpp

#Includes
#Core#
include/Bengite/Core/Game.h
include/Bengite/Core/GameTime.h
include/Bengite/Core/Objects.h
include/Bengite/Core/RNG.h

include/Bengite/Core/Math/BMath.h

include/Bengite/Core/Debugging/debug.h

include/Bengite/Core/GameState.h
include/Bengite/Core/GameStateManager.h

include/Bengite/Core/Components/Player.h
include/Bengite/Core/Components/World.h
include/Bengite/Core/Components/ComponentsManager.h

include/Bengite/Core/Events/Event.h

include/Bengite/Core/Input/Mouse.h
include/Bengite/Core/Input/Keyboard.h

include/Bengite/Core/Timers/CooldownTimer.h
include/Bengite/Core/Timers/CountDown.h
include/Bengite/Core/Timers/Timer.h

#Content#
include/Bengite/Content/ContentManager.h

#Graphics#
include/Bengite/Graphics/SpriteBatch.h
include/Bengite/Graphics/DrawObject.h
include/Bengite/Graphics/DrawingManager.h

include/Bengite/Graphics/Controls/Control.h
include/Bengite/Graphics/Controls/ControlManager.h
include/Bengite/Graphics/Controls/Button.h
include/Bengite/Graphics/Controls/MaskedNumericIndicator.h
include/Bengite/Graphics/Controls/NumericIndicator.h
include/Bengite/Graphics/Controls/ProgressBar.h
include/Bengite/Graphics/Controls/TextIndicator.h
include/Bengite/Graphics/Controls/TextBox.h

include/Bengite/Graphics/16bitTileEngine/Camera2D.h
include/Bengite/Graphics/16bitTileEngine/Layer.h
include/Bengite/Graphics/16bitTileEngine/Tile.h
include/Bengite/Graphics/16bitTileEngine/TileSet.h
include/Bengite/Graphics/16bitTileEngine/TileLayer.h
include/Bengite/Graphics/16bitTileEngine/CollisionLayer.h
include/Bengite/Graphics/16bitTileEngine/TopLayer.h
include/Bengite/Graphics/16bitTileEngine/Chunk.h

include/Bengite/Graphics/Animation/AnimatedSprite.h
include/Bengite/Graphics/Animation/Animation.h

#Gameplay#
include/Bengite/Gameplay/Interactuable.h
# include/Bengite/Agriculture/BasePlant.h
# include/Bengite/Agriculture/Ground.h

#Amalgamations#
include/Bengite/json/json.h
include/Bengite/json/json-forwards.h
include/Bengite/json/jsonStream.h

)


add_library(rlpp STATIC ${SOURCE_FILES})
SET(CMAKE_EXE_LINKER_FLAGS "-lraylib -lglfw3 -lglew32 -lopenal32 -lopengl32")
