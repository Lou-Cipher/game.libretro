/*
 *      Copyright (C) 2016 Team Kodi
 *      http://kodi.tv
 *
 *  This Program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This Program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this Program; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */
#pragma once

#include "kodi_game_types.h"

#include <memory>

class CHelper_libKODI_game;

namespace LIBRETRO
{
  class CVideoGeometry;

  class CVideoStream
  {
  public:
    CVideoStream();

    void Initialize(CHelper_libKODI_game* frontend);
    void Deinitialize();

    void SetGeometry(const CVideoGeometry &geometry);

    void AddFrame(const uint8_t* data, unsigned int size, unsigned int width, unsigned int height, GAME_PIXEL_FORMAT format, GAME_VIDEO_ROTATION rotation);

  private:
    void CloseStream();

    CHelper_libKODI_game* m_frontend;

    std::unique_ptr<CVideoGeometry> m_geometry;
    void *m_stream = nullptr;
    GAME_PIXEL_FORMAT m_format = GAME_PIXEL_FORMAT_UNKNOWN; // Guard against libretro changing formats
  };
}
