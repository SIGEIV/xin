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

#pragma once

#include <QObject>

/**
 * @fn void Audio::frameAvailable(const int16_t *pcm, size_t sample_count, uint8_t channels,
 * uint32_t sampling_rate);
 *
 * When there are input subscribers, we regularly emit captured audio frames with this signal
 * Always connect with a blocking queued connection lambda, else the behaviour is undefined
 */

class IAudioSource : public QObject
{
    Q_OBJECT
public:
    virtual ~IAudioSource() = default;

    virtual operator bool() const = 0;

signals:
    void frameAvailable(const int16_t* pcm, size_t sample_count, uint8_t channels,
                        uint32_t sampling_rate);
    void volumeAvailable(qreal value);
    void invalidated();
};
