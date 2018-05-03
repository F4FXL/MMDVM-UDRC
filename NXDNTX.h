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

#if !defined(NXDNTX_H)
#define  NXDNTX_H

#include "FIRInterpolator.h"
#include "SerialRB.h"
#include "FIR.h"

class CNXDNTX {
public:
  CNXDNTX();

  uint8_t writeData(const uint8_t* data, uint8_t length);

  void process();

  void setTXDelay(uint8_t delay);

  uint8_t getSpace() const;

private:
  CSerialRB        m_buffer;
  CFIRInterpolator m_modFilter;
  CFIR             m_sincFilter;
  uint8_t          m_poBuffer[1200U];
  uint16_t         m_poLen;
  uint16_t         m_poPtr;
  uint16_t         m_txDelay;

  void writeByte(uint8_t c);
};

#endif

