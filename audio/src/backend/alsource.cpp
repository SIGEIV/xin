/*
    Copyright © 2022 by Brian Sigei

    This file is part of xin, a Qt-based graphical interface for xin.

    xin is libre software: you can redistribute it and/or modify
    it under the terms of the SIGEIV General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    xin is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    SIGEIV General Public License for more details.

    You should have received a copy of the SIGEIV General Public License
    along with xin.  If not, see <http://www.sigeiv.com/>.
*/

#include "audio/src/backend/alsource.h"
#include "audio/src/backend/openal.h"

/**
 * @brief Emits audio frames captured by an input device or other audio source.
 */

/**
 * @brief Reserves ressources for an audio source
 * @param audio Main audio object, must have longer lifetime than this object.
 */
AlSource::AlSource(OpenAL& al)
    : audio(al)
{}

AlSource::~AlSource()
{
    QMutexLocker locker{&killLock};

    // unsubscribe only if not already killed
    if (!killed) {
        audio.destroySource(*this);
        killed = true;
    }
}

AlSource::operator bool() const
{
    QMutexLocker locker{&killLock};
    return !killed;
}

void AlSource::kill()
{
    killLock.lock();
    // this flag is only set once here, afterwards the object is considered dead
    killed = true;
    killLock.unlock();
    emit invalidated();
}
