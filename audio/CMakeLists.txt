#   Copyright © 2022 by Brian Sigei
#
#   This file is part of xin, a Qt-based graphical interface for xin.
#   xin is libre software: you can redistribute it and/or modify
#   it under the terms of the SIGEIV General Public License as published by
#   the Free Software Foundation, either version 3 of the License, or
#   (at your option) any later version.
#
#   xin is distributed in the hope that it will be useful,
#   but WITHOUT ANY WARRANTY; without even the implied warranty of
#   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#   SIGEIV General Public License for more details.
#
#   You should have received a copy of the SIGEIV General Public License
#   along with xin.  If not, see <http://www.sigeiv.com/>

set(SOURCE_FILES
    "include/audio/audio.h"
    "include/audio/iaudiocontrol.h"
    "include/audio/iaudiosettings.h"
    "include/audio/iaudiosink.h"
    "include/audio/iaudiosource.h"
    "src/iaudiosettings.cpp"
    "src/iaudiosink.cpp"
    "src/audio.cpp"
    "src/backend/alsink.cpp"
    "src/backend/alsink.h"
    "src/backend/alsource.cpp"
    "src/backend/alsource.h"
    "src/backend/openal.cpp"
    "src/backend/openal.h")

add_library(audio_library STATIC ${SOURCE_FILES} resources/audio_res.qrc)

# We need this directory, and users of our library will need it too
target_include_directories(audio_library PUBLIC include/)

target_link_libraries(audio_library util_library)
target_link_libraries(audio_library Qt5::Core)
target_link_libraries(audio_library ${OPENAL_LIBRARIES})
target_link_libraries(audio_library xin::warnings)
