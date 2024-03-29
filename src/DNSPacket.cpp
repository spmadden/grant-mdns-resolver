/*
 * DNSPacket.cpp
 *
 *    Copyright (C) 2012 Sean P Madden
 *
 *    This program is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *    If you would like to license this code under the GNU LGPL, please see
 *    http://www.seanmadden.net/licensing for details.
 *
 */

#include "DNSPacket.h"

namespace grant {

DNSPacket::DNSPacket():
	_id(0), _opCode(QUERY), _flags(0){

}

DNSPacket::~DNSPacket() {
}

bool DNSPacket::serialize(uint8_t* buf, const std::size_t size) const{
	unsigned int headerSize = 12; // 12 bytes


	return true;
}

} /* namespace grant */
