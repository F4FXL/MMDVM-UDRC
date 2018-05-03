/*
 *   Copyright (C) 2015,2016,2017,2018 by Jonathan Naylor G4KLX
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation; either version 2 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program; if not, write to the Free Software
 *   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#if !defined(YSFRX_H)
#define  YSFRX_H

#include "YSFDefines.h"

enum YSFRX_STATE {
  YSFRXS_NONE,
  YSFRXS_DATA
};

class CYSFRX {
public:
  CYSFRX();

  void samples(const float* samples, uint8_t length);

  void reset();

private:
  YSFRX_STATE m_state;
  uint32_t    m_bitBuffer[YSF_RADIO_SYMBOL_LENGTH];
  float       m_buffer[YSF_FRAME_LENGTH_SAMPLES];
  uint16_t    m_bitPtr;
  uint16_t    m_dataPtr;
  uint16_t    m_startPtr;
  uint16_t    m_endPtr;
  uint16_t    m_syncPtr;
  uint16_t    m_minSyncPtr;
  uint16_t    m_maxSyncPtr;
  float       m_maxCorr;
  uint16_t    m_lostCount;
  uint8_t     m_countdown;
  float       m_centre[16U];
  float       m_centreVal;
  float       m_threshold[16U];
  float       m_thresholdVal;
  uint8_t     m_averagePtr;

  void processNone(float sample);
  void processData(float sample);
  bool correlateSync();
  void calculateLevels(uint16_t start, uint16_t count);
  void samplesToBits(uint16_t start, uint16_t count, uint8_t* buffer, uint16_t offset, float centre, float threshold);
  void writeData(uint8_t* data);
};

#endif

